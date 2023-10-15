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
		cout << "����� ��� �������: " << InfoPolis.polisNumber << " ��� ������." << endl;
	}

	~Polis()
	{
		cout << "������ ������ ��� �������: " << InfoPolis.polisNumber << " ���� �������!" << endl;
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
		cout << "\n����� ������ ����������� ������: " << InfoPolis.polisNumber << endl;
		cout << "���: " << InfoPolis.firstName << endl;
		cout << "�������: " << InfoPolis.lastName << endl;
		cout << "���� �������� ������: " << InfoPolis.validity << endl;
	}
};
