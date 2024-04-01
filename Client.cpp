#pragma once
#include <iostream>
#include "Client.h"
#include <fstream>
using namespace std;
Client::Client()
	:People{ "None", "unknow",0 } {}
Client::Client(int newage)
	:People{ "None", "Unknow" , newage } {}
Client::Client(int newage, string newname)
	: People{ newname, "Unknow",newage } {}
Client::Client(int newage, string newname, string newsurname)
	: People{ newname, newsurname,newage } {}
Client::Client(int newage, string newname, string surname, string newadress)
	: People{ newname, surname, age }, adress{ newadress } {}

Client::Client(int newage, string newname, string surname, string newadress, int number_phone)
	: People{ newname, surname, newage, number_phone }, adress{ newadress } {}

Client::Client(const Client& other)
:People("Unknow","Unknown",0,0),adress(other.adress) {}
Client::Client(Client&& other) noexcept
	:People(move(other)), adress(other.adress) {
	other.adress = nullptr;
}
Client& Client::operator = (const Client& other) {
	if (this != &other) {
		People::operator=(other);
		adress = other.adress;
	}
	return *this ;
}
Client::~Client() {}



/*void Client::Setname(string nowname) {
	this->name = nowname;
}
void Client::Setage(int nowage) {
	this->age = nowage;
}
void Client::Setadress(string nowadress) {
	this->adress = nowadress;
}
void Client::Setnumber_phone(int nownumber_phone) {
	this->number_phone = nownumber_phone;
}
*/
void  Client::Displey()const {
	People::Displey();
	cout << "Adress: " << adress << endl;
}
void Client::sound() {
	cout << "I am :" << name << " Ready to buy your car" << endl;
}
void Client::print(ostream& os) const {
	os << "Interface for Client: " << endl;
	os << "My name: " << name << endl << "Surname: " << surname <<endl
		<< "Age: " << age << endl << "Number phone: " << number_phone << endl << "Adress: " << adress << endl;
	os << endl;

}
istream& operator>>(istream& is, Client& client) {
	cout << "Enter Client name: ";
	is >> client.name;

	cout << "Enter Client age: ";
	is >> client.age;

	cout << "Enter Client adress: ";
	is >> client.adress;

	cout << "Enter Client number: ";
	is >> client.adress;
	return is;
}
ostream& operator<<(ostream& os, Client& client) {
	os << "Client name:" << client.name << endl;
	os << "Client age" << client.age << endl;
	os << "Client adress:" << client.adress << endl;
	os << "Client number:" << client.number_phone << endl;


	return os;
}
string Client::fileName = "client.txt";
void Client::AddClient() {
	// ³������� ����� ��� ������ � ����� ���������
	ofstream outFile(fileName, ios::app);

	// ��������, �� ������� ������� ����
	if (!outFile.is_open()) {
		cerr << "Unable to open file: " << fileName << endl;
		return;
	}

	// ����� ���� ��'���� � ���� � ����� �����
	outFile << "name: " << name << endl;
	outFile << "surname: " << surname << endl;
	outFile << "age: " << age << endl;
	outFile << "number_phone: " << number_phone << endl;
	outFile << "adress: " << adress << endl;


	// �������� �����
	outFile.close();

	cout << "Data Client has been successfully added to the file." << endl;
}

