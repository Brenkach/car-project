#pragma once
#include <iostream>
#include "car.h"
#include <fstream>

using namespace std;
Car::Car() {
	
}
Car::Car(string newcolor, int newcarage , string newmark, double newpetrol, int newdoor, double newprice)
	:color{ newcolor }, carage{ newcarage }, mark{ newmark }, petrol{ newpetrol }, door{ newdoor }, price{newprice} {
	
}
// Конструктор копіювання
Car::Car(const Car& other) {
	color = other.color;
	carage = other.carage;
	mark = other.mark;
	petrol = other.petrol;
	door = other.door;
	price = other.door;

}

int Car::GetCount() {
	return count;
}

Car::~Car() {}
void Car::Setcolor(string newcolor) {
	this->color = newcolor;
}
void Car::Setcarage(int newcarage) {
	this->carage = newcarage;
}
void Car::Setmark(string newmark) {
	this->mark = newmark;
}
void Car::Setpetrol(double newpetrol) {
	this->petrol = newpetrol;

}
void Car::Setdoor (int newdoor) {
	this->door = newdoor;
}
void Car::Setprice(double newprice) {
	this->price = newprice;
}
void Car::CarDispley() {
	cout << "Car age:" << carage << endl;
	cout << "Car mark:" << mark << endl;
	cout << "Car price:" << price << endl;
	cout << "Car door:" << door << endl;
	cout << "Car petrol:" << petrol << endl;
	cout << "Car color:" << color << endl;
}
int Car::count = 0;
void Car::showNewDetails() {
	if (&Details :: isNewDetails ) {
		cout << "You have a new details." << endl;
	}
	else {
		cout << "You have a old details." << endl;
	}
}
void Car::AllCars()
{

}
istream& operator>>(istream& is, Car& car) {
	cout << "Enter Car age: ";
	is >> car.carage;

	cout << "Enter Car mark: ";
	is >> car.mark;

	cout << "Enter Car color: ";
	is >> car.color;

	cout << "Enter Car petrol per 100km: ";
	is >> car.petrol;

	cout << "Enter Car door: ";
	is >> car.door;

	cout << "Enter Car price: ";
	is >> car.price;
	return is;

}
ostream& operator<<(ostream& os, Car& car) {
	os << "Car age:" << car.carage << endl;
	os << "Car mark: " << car.mark << endl;
	os << "Car color:" << car.color << endl;
	os << "Car door:" << car.door << endl;
	os << "Car price:" << car.price << endl;
	os << "Car petrol:" << car.petrol << endl;
	return os;
}

string Car::fileName = "cars.txt";
void Car::AddCar() {
	// Відкриття файлу для запису у режимі додавання
	ofstream outFile(fileName, ios::app);

	// Перевірка, чи вдалося відкрити файл
	if (!outFile.is_open()) {
		cerr << "Unable to open file: " << fileName << endl;
		return;
	}

	// Запис полів об'єкта у файл у окремі рядки
	outFile << "Color: " << color << endl;
	outFile << "Car Age: " << carage << endl;
	outFile << "Mark: " << mark << endl;
	outFile << "Petrol: " << petrol << endl;
	outFile << "Door: " << door << endl;
	outFile << "Price: " << price << endl;



	//outFile << "Motor Details: " << endl;

	// Закриття файлу
	outFile.close();

	cout << "Car details have been successfully added to the file." << endl;






}
