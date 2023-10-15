#pragma once
#include <iostream>
using namespace std;

class Polis
{
protected:
	static inline int id;
	struct polisInfo
	{
		int polisNumber;
		string firstName;
		string lastName;
		string validity;
	} InfoPolis;
public:

	string getFerstname() { return InfoPolis.firstName; }

	Polis(string firstName, string lastName, string validity)
		: InfoPolis{ id++, firstName, lastName, validity }
	{
		cout << "Полис под номером: " << id - 1 << " был создан." << endl;
	}

	~Polis()
	{
		cout << "Память полиса под номером: " << InfoPolis.polisNumber << " была очищена!" << endl;
	}
	bool operator==(string SearchLastName);
	virtual void print()
	{
		cout << "\nНомер Полиса Страхования Жилища: " << InfoPolis.polisNumber << endl;
		cout << "Имя: " << InfoPolis.firstName << endl;
		cout << "Фамилия: " << InfoPolis.lastName << endl;
		cout << "Срок действия полиса: " << InfoPolis.validity << endl;
	}
};

bool Polis::operator==(string SearchLastName)
{
	return InfoPolis.lastName == SearchLastName;
}
