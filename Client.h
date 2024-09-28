#pragma once
#include "people.h"
#include <iostream>
using namespace std;
class Client final : public People
{
private:
	string adress;
	static string fileName;

public:
	Client();
	Client(int newage);
	Client(int newage, string newname);
	Client(int newage, string newname, string surname);
	Client(int newage, string newname, string surname, string newadress);
	Client(int newage, string newname, string surname, string newadress, string number_phone);
	Client(const Client& other);
	Client(Client&& other) noexcept;
	Client& operator=(const Client& other);
	~Client();
	void AddClient();
	void Displey();
	void sound()override;
	friend istream& operator>>(istream& os, Client& car);
	friend ostream& operator<<(ostream& os, Client& car);
	virtual void print(ostream& os) const override;

};
