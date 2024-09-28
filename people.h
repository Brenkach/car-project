#pragma once
#include <iostream>
#include "Interface.h"
using namespace std;
class People : public Interface
{
protected:
	string name;
	string surname;
	int age;
	string number_phone;


public:
	People();
	People(string newname);
	People(string newname, string newsurname);
	People(string newname, string newsurname, int newage);
	People(string newname, string newsurname, int newage, string newnumer_phone);
	People(const People& other);//copy
	People(People&& other) noexcept;//move
	People& operator = (const People& other);//operator =
	virtual ~People();
	void Setname(string name);
	void Setsurname(string surname);
	void Setage(int age);
	void Setnumber_phone(int number_phone);
	virtual void Displey()const;
	virtual void sound() = 0;
	virtual void print(ostream& os)const override;
};

