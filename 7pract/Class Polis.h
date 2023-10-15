#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Polis
{
protected:
	struct polisInfo
	{
		int polisNumber;
		T firstName;
		T lastName;
		T validity;
	} InfoPolis;

public:
	Polis(int polisNumber, T firstName, T lastName, T validity)
		: InfoPolis{ polisNumber, firstName, lastName, validity }
	{
		cout << "Полис под номером: " << InfoPolis.polisNumber << " был создан." << endl;
	}

	~Polis()
	{
		cout << "Память полиса под номером: " << InfoPolis.polisNumber << " была очищена!" << endl;
	}
	int GetPolisNumber()
	{
		return InfoPolis.polisNumber;
	}
	T GetPolisLastName()
	{
		return InfoPolis.lastName;
	}

	virtual void print()
	{
		cout << "\nНомер Полиса Страхования Жилища: " << InfoPolis.polisNumber << endl;
		cout << "Имя: " << InfoPolis.firstName << endl;
		cout << "Фамилия: " << InfoPolis.lastName << endl;
		cout << "Срок действия полиса: " << InfoPolis.validity << endl;
	}
};
