#pragma once
#include <iostream>
#include "Class Polis.h"
using namespace std;

namespace Model
{

	class OMS : private Polis
	{
	private:
		struct InfoOms
		{
			string birthDate;
			string gender;
		}Oms;
	public:
		OMS(string firstName, string lastName, string validity, string birthDate, string gender)
			: Polis(firstName, lastName, validity), Oms{ birthDate, gender }
		{
		}
		~OMS()
		{
			cout << "Память объект класса OMS под номером полиса " << InfoPolis.polisNumber << " была очищена!" << endl;
		}
		void print()
		{
			cout << "\nНомер полиса ОМС: " << InfoPolis.polisNumber << endl;
			cout << "Имя: " << InfoPolis.firstName << endl;
			cout << "Фамилия: " << InfoPolis.lastName << endl;
			cout << "Пол: " << Oms.gender << endl;
			cout << "Дата рождения: " << Oms.birthDate << endl;
			cout << "Срок годности полиса: " << InfoPolis.validity << endl;
		}
		int GetPolisNumber()
		{
			return InfoPolis.polisNumber;
		}
		string GetLastName()
		{
			return InfoPolis.lastName;
		}
		bool operator==(string SearchLastName);
	};

	bool OMS::operator==(string SearchLastName)
	{
		return InfoPolis.lastName == SearchLastName;
	}
}
