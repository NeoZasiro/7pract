#pragma once
#include <iostream>
#include "Class Polis.h"

using namespace std;

namespace Model
{



	class House : public Polis
	{
	private:
		struct HouseInfo
		{
			string adress;
			int square;
			int cost;
			int summa;
		} InfoHouse;
	public:
		House(string firstName, string lastName, string validity, string adress, int square, int cost, int summa)
			: Polis(firstName, lastName, validity), InfoHouse{ adress, square , cost, summa }
		{
		}
		~House()
		{
			cout << "Память объекта House под номером полиса: " << InfoPolis.polisNumber << " была очищена!" << endl;
		}
		void print()
		{
			cout << "\nНомер Полиса Страхования Жилища: " << InfoPolis.polisNumber << endl;
			cout << "Имя: " << InfoPolis.firstName << endl;
			cout << "Фамилия: " << InfoPolis.lastName << endl;
			cout << "Адрес жилища: " << InfoHouse.adress << endl;
			cout << "Площадь жилища: " << InfoHouse.square << endl;
			cout << "Сумма страхования: " << InfoHouse.summa << endl;
			cout << "Стоимость страхования: " << InfoHouse.cost << endl;
			cout << "Срок действия полиса: " << InfoPolis.validity << endl;
		}
		int GetPolisNumber()
		{
			return InfoPolis.polisNumber;
		}
		string GetLastName()
		{
			return InfoPolis.lastName;
		}
	};
}
