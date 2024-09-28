#pragma once
#include <iostream>
#include "people.h"
using namespace std;
 class Seler : public People
{
private:
	int selerage;
	string selername;
	string seleradress;
	string selernumder_phone;
	static string fileName;

public:
	Seler();
	Seler(int, string);
	Seler(int, string, string, string);
	~Seler();
	void selerSetname(string nowname);
	void AddSeler();
	void selerSetage(int nowage);
	void selerSetadress(string nowadress);
	void selerSetnumder_phone(string newselernumder_phone);
	void selerDispley();
	virtual void sound() override;
	friend istream& operator>>(istream& os, Seler& car);
};

