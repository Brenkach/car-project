#pragma once
#include <iostream>
#include "people.h"
using namespace std;
People::People()
	:name{ "None" }, surname{ "unknow" },age{ 0 } {}
People::People(string newname)
	:People(newname, "Unknow") {}
People::People(string newname, string newsurname)
	: name{ newname }, surname  { newsurname } {}
People::People(string newaname, string newsurname, int age)
	: name{ newaname }, surname{ newsurname }, age{ age } {}
People::People(string newaname, string newsurname, int age, string number_phone)
	: name{ newaname }, surname{ newsurname }, age{ age }, number_phone{ number_phone } {}

People::People(const People& other) {
	name = other.name;
	surname = other.surname;
	age = other.age;
	number_phone = other.number_phone;
}//copy constructor
People& People::operator=(const People& other) {
	if (this != &other) {
		name = other.name;
		age = other.age;
		surname = other.surname;
		number_phone = other.number_phone;
	}
	return *this;
}//operator =
People::People(People&& other)noexcept
:name(move(other.name)),age(move(other.age)),surname(move(other.surname)), number_phone(move(other.number_phone)){
	other.name = nullptr;
	other.surname = nullptr;
	other.age = NULL;
	other.number_phone = nullptr;
} //Move constructor

People::~People() {}

void People::Setname(string newname) {
	this->name = newname;
}
void People::Setage(int newage) {
	this->age = newage;
}
void People::Setsurname(string newsurname) {
	this->surname = newsurname;
}
void People::Setnumber_phone(int number_phone) {
	this->number_phone = number_phone;
}
void People::print(ostream& os) const {
	os << "Interface for People: " << endl;
	os << "My name: " << name << endl << "Surname: " << surname << endl
		<< "Age: " << age << endl << "Number phone: " << number_phone << endl;
	os << endl;
}

void People::Displey()const {
	cout << "People name:" << name << endl;
	cout << "People surname:" << surname << endl;
	cout << "People age" << age << endl;
	cout << "People number_phone:" << number_phone << endl;


}

