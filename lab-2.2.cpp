#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include "car.h"
#include "seler.h"
#include "Client.h"
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>    
using namespace std;

//метод видалення по році
void RemoveCarsByYear(int yearToRemove) {
	ifstream inFile("cars.txt"); // Відкриваємо файл для читання
	ofstream outFile("temp.txt"); // Створюємо тимчасовий файл для запису залишку автомобілів

	if (!inFile.is_open()) {
		cout << "Unable to open file: cars.txt" << endl;
		return;
	}

	if (!outFile.is_open()) {
		cout << "Unable to open file: temp.txt" << endl;
		return;
	}

	string label;
	string color, mark;
	int carAge, door;
	double petrol, price;

	// Читаємо файл та перевіряємо рік
	while (inFile >> label >> color // Зчитуємо "Color:"
		>> label>>label >> carAge // Зчитуємо "Car Age:"
		>> label >> mark // Зчитуємо "Mark:"
		>> label >> petrol // Зчитуємо "Petrol:"
		>> label >> door // Зчитуємо "Door:"
		>> label >> price) // Зчитуємо "Price:"
	{
		// Якщо рік не дорівнює тому, що потрібно видалити, записуємо дані в тимчасовий файл
		if (carAge != yearToRemove) {
			outFile << "Color: " << color << endl;
			outFile << "Car Age: " << carAge << endl;
			outFile << "Mark: " << mark << endl;
			outFile << "Petrol: " << petrol << endl;
			outFile << "Door: " << door << endl;
			outFile << "Price: " << price << endl;
		}
	}

	inFile.close(); // Закриваємо вхідний файл
	outFile.close(); // Закриваємо вихідний файл

	// Заміна старого файлу новим, без видалених автомобілів
	remove("cars.txt");
	rename("temp.txt", "cars.txt");

	cout << "Cars from year " << yearToRemove << " have been removed." << endl;
}




// Функція для обчислення середньої ціни автомобілів у вказаний період
void CalculateAveragePriceInPeriod(int startYear, int endYear) {
	ifstream inFile("cars.txt"); // Відкриваємо файл з автомобілями

	if (!inFile.is_open()) {
		cerr << "Unable to open file: cars.txt" << endl;
		return;
	}

	string label;  // Змінна для зчитування назв полів (наприклад, "Color:", "Car Age:", і т.д.)
	string color, mark;
	int carAge, door;
	double petrol, price;
	int totalCars = 0;
	double totalPrice = 0.0;

	while (inFile >> label >> color   // Зчитуємо назву поля і значення (наприклад, "Color: blue")
		>> label >> label >> carAge  // Зчитуємо "Car Age:" і вік автомобіля
		>> label >> mark    // Зчитуємо "Mark:" і марку
		>> label >> petrol  // Зчитуємо "Petrol:" і витрати палива
		>> label >> door    // Зчитуємо "Door:" і кількість дверей
		>> label >> price)  // Зчитуємо "Price:" і ціну
	{
		// Якщо рік випуску автомобіля у вказаному діапазоні
		if (carAge >= startYear && carAge <= endYear) {
			totalPrice += price; // Додаємо ціну автомобіля
			totalCars++; // Збільшуємо кількість автомобілів
		}
	}

	inFile.close(); // Закриваємо файл

	if (totalCars > 0) {
		double averagePrice = totalPrice / totalCars; // Обчислюємо середню ціну
		cout << "Average price of cars released between " << startYear << " and " << endYear << " is: " << averagePrice << endl;
	}
	else {
		cout << "No cars found in the specified period." << endl;
	}
}
// Функція для пошуку найекономнішого автомобіля
void FindMostEconomicalCar() {
	ifstream inFile("cars.txt"); // Відкриваємо файл з автомобілями

	if (!inFile.is_open()) {
		cerr << "Unable to open file: cars.txt" << endl;
		return;
	}
	string label;
	string color, mark;
	int carAge, door;
	double petrol, price;
	double minPetrol = numeric_limits<double>::infinity(); // Початково встановлюємо мінімальне значення як безкінечність
	string bestCarDetails;

	while (inFile >> label >> color   // Зчитуємо назву поля і значення (наприклад, "Color: blue")
		>> label >> label >> carAge  // Зчитуємо "Car Age:" і вік автомобіля
		>> label >> mark    // Зчитуємо "Mark:" і марку
		>> label >> petrol  // Зчитуємо "Petrol:" і витрати палива
		>> label >> door    // Зчитуємо "Door:" і кількість дверей
		>> label >> price) {
		// Якщо знаходимо автомобіль з меншим споживанням палива, оновлюємо
		if (petrol < minPetrol) {
			minPetrol = petrol;
			bestCarDetails = "Color: " + color + "\nCar Age: " + to_string(carAge) +
				"\nMark: " + mark + "\nPetrol: " + to_string(petrol) +
				"\nDoor: " + to_string(door) + "\nPrice: " + to_string(price);
		}
	}

	inFile.close(); // Закриваємо файл

	if (!bestCarDetails.empty()) {
		cout << "The most economical car is:\n" << bestCarDetails << endl;
	}
	else {
		cout << "No cars found in the file." << endl;
	}
}



void DisplayObject(string fileName) {
	// Відкриття файлу для читання
	ifstream inFile(fileName);

	// Перевірка, чи вдалося відкрити файл
	if (!inFile.is_open()) {
		cerr << "Unable to open file: " << fileName << endl;
		return;
	}

	// Зчитування та виведення даних з файлу
	string line;
	while (getline(inFile, line)) {
		cout << line << endl;
	}

	// Закриття файлу
	inFile.close();
}

void displeyInfoOnUI(const People& people) {
	cout << "---------------------------------------------" << endl;
	people.Displey();
	cout << "---------------------------------------------" << endl;
}
void InterfaceForAll(Interface& obj) {
	cout << obj;                 // Interface
}
void AppendCar()
{
	//"введіть поля машини"
	//створити нову машину
	//викликати метод AddCar()
	Car Car1;
	cin >> Car1;
	cout << Car1 << endl;
	Car1.AddCar();
}
void AppendClient()
{
	Client Client1;
	cin >> Client1;
	cout << Client1 << endl;
	Client1.AddClient();
}
void AppendSeler()
{
	Seler Seler1;
	cin >> Seler1;
	cout << Seler1 << endl;
	Seler1.AddSeler();
}
int Admin()
{


	chrono::system_clock::time_point entertime = chrono::system_clock::now();
	time_t et = chrono::system_clock::to_time_t(entertime);
	ofstream save("history.txt", ios::app);
	save << "admin entered at " << ctime(&et) << '\n';
	save.close();
	string choice;
	while (true) {
		cout << "Menu:" << endl;
		cout << "1. Add Car" << endl;
		cout << "2. Display All Cars" << endl;
		cout << "3. Add Client" << endl;
		cout << "4. Display All Client" << endl;
		cout << "5. Add Seler" << endl;
		cout << "6. Display All Selers" << endl;
		cout << "7. Exit" << endl;
		cout << "8. Show most economic car" << endl;
		cout << "9. Show most price given period " << endl;
        cout << "10. Enter the year of cars to remove: ";
		cout << "Enter your choice: " << endl;
		cin >> choice;
		try {
			switch (stoi(choice)) {
			case 1:
				AppendCar();
				break;
			case 2:
				DisplayObject("cars.txt");

				break;
			case 3:
				AppendClient();
				break;
			case 4:
				DisplayObject("client.txt");
				break;
			case 5:
				AppendSeler();
				break;
			case 6:
				DisplayObject("seler.txt");
				break;
			case 7:
				cout << "Exiting..." << endl;
				return 0;
			case 8:
				FindMostEconomicalCar();
				break;
			case 9:
				int startYear, endYear;
				cout << "type period" << endl;
				cin >> startYear >> endYear;
				CalculateAveragePriceInPeriod(startYear, endYear);
				break;
			case 10:
				int yearToRemove;
				cout << "Year" << endl;
				cin >> yearToRemove;
				RemoveCarsByYear(yearToRemove);
				break;
			default:
				cout << "Invalid choice. Please 101 again." << endl;
				break;
			}
		}
		catch (...)
		{
			cout << "Wrong input" << endl;
		}
	}
}
int User()
{
	chrono::system_clock::time_point entertime = chrono::system_clock::now();
	time_t et = chrono::system_clock::to_time_t(entertime);
	ofstream save("history.txt", ios::app);
	save << "user entered at " << ctime(&et) << '\n';
	save.close();
	string choice;
	while (true) {
		cout << "Menu:" << endl;
		cout << "1. Display All Cars" << endl;
		cout << "2. Display All Client" << endl;
		cout << "3. Display All Seler" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		try {
			switch (stoi(choice)) {
			case 1:
				DisplayObject("cars.txt");

				break;
			case 2:
				DisplayObject("client.txt");
				break;
			case 3:
				DisplayObject("seler.txt");
				break;
			case 4:
				cout << "Exiting..." << endl;
				return 0;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
			}
		}
		catch (...)
		{
			cout << "Wrong input" << endl;
		}
	}
}
string password = "1234";
int main()
{
	string choice;
	while (true) {
		cout << "Menu:" << endl;
		cout << "1. Enter as admin" << endl;
		cout << "2. Enter as user" << endl;
		cin >> choice;
		try
		{
			switch (stoi(choice))
			{
			case 1:
			{
				cout << "Enter password" << endl;
				string testtry;
				cin >> testtry;
				if (testtry == password)
				{
					Admin(); break;
				}
				else
					cout << "Wrong password, Entered as user" << endl;
			}
			default:
				User();
				break;
			}
		}
		catch (...)
		{
			cout << "Wrong input" << endl;
		}
	}




	//	//Seler Seler1;
	//	Car Car3{ "black", 2012, "Audi" };
	//	Seler Seler1{ 18,"Denis","Prospect" };
	//	Seler1.AddSeler();
	//	//cout << Seler1 << endl;
	//	cout << Car3<<endl;
	//	Car car2 = Car(Car1);
	//	cout << car2 << endl;
	//Client Client2(18, "Denus", "Brenkach","Prospect", 55555);
	//Client2.AddClient();
	// Client2.Displey();
	// People& People1=Client2;
	//People1.Displey();//static 
	// People* client1 = new Client();//base class pointer
	// client1->Setname("John");
	//displeyInfoOnUI(*client1);
	//delete client1;
	//Client Client3;//referens
	//Client3.Setname("name");
	//People& People2 = Client3;
	//People2.sound();
	//InterfaceForAll(People2);//interface
	//Base class referens
	//displeyInfoOnUI(People2);

}

