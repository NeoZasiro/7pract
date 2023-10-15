#include <iostream>
#include <Windows.h>
#include <random>
#include "Class OMS.h"
#include "Class House.h"
#include <iomanip>
using namespace std;
using namespace Model;

//Вариант А.
//Задание 1. Использовать структуру классов,
//спроектированную на  практическом занятии №5.
//Наследование одного из производных классов осуществить по типу private.
//Перегрузить оператор для работы с объектами классов
//и использовать его для определения Вычисляемого показателя.

string ReturnString(string text)
{
	cout << text;
	cin >> text;
	return text;
}

int GetRandomNumber(int min, int max)
{
	static random_device rd;
	static mt19937 generator(rd());
	uniform_int_distribution<int> distribution(min, max);

	int randomValue;

	randomValue = distribution(generator);

	return randomValue;
}
int CountLastName(OMS* oms[], Model::House* house[], string searchLastName, int numPolis)
{
	int count{};
	for (int k = 0; k < numPolis; k++)
	{
		if (*oms[k] == searchLastName)
		{
			count++;
		}
		else if (*house[k] == searchLastName)
		{
			count++;
		}
	}
	return count;
}

int CountLastName(OMS* oms[], string searchLastName, int numPolis)
{
	int count{};
	for (int k = 0; k < numPolis; k++)
	{
		if (*oms[k] == searchLastName)
		{
			count++;
		}
	}
	return count;
}
int CountLastName(House* house[], string searchLastName, int numPolis)
{
	int count{};
	for (int k = 0; k < numPolis; k++)
	{
		if (*house[k] == searchLastName)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	const int numPolis = 5;
	int count = 0;
	OMS** omsArray = new OMS * [numPolis]
		{
			new OMS("Иван", "Иванов", "01.01.2025", "01.01.1990", "Мужской"),
				new OMS("Мария", "Кузнецова", "01.01.2024", "15.05.1985", "Женский"),
				new OMS("Петр", "Федоров", "01.01.2025", "05.09.1980", "Мужской"),
				new OMS("Алексей", "Федоров", "01.01.2023", "20.03.1975", "Мужской"),
				new OMS("Елена", "Ковалева", "01.01.2024", "10.12.1992", "Женский")
		};

	for (int i = 0; i < numPolis; i++)
	{
		omsArray[i]->print();
	}

	House** houseArray = new House * [numPolis]
		{
			new House("Денис", "Михайлов", "01.01.2023", "ул. Гагарина, д. 789", GetRandomNumber(22, 59), GetRandomNumber(300000, 700000), GetRandomNumber(200000, 500000)),
				new House("Ольга", "Козлова", "01.01.2024", "ул. Пушкина, д. 456", GetRandomNumber(22, 59), GetRandomNumber(300000, 700000), GetRandomNumber(200000, 500000)),
				new House("Андрей", "Иванов", "01.01.2023", "ул. Ленина, д. 123", GetRandomNumber(22, 59), GetRandomNumber(300000, 700000), GetRandomNumber(200000, 500000)),
				new House("Сергей", "Иванов", "01.01.2025", "ул. Советская, д. 321", GetRandomNumber(22, 59), GetRandomNumber(300000, 700000), GetRandomNumber(200000, 500000)),
				new House("Кирилл", "Федоров", "01.01.2024", "ул. Ломоносова, д. 654", GetRandomNumber(22, 59), GetRandomNumber(300000, 700000), GetRandomNumber(200000, 500000))
		};

	for (int i = 0; i < numPolis; i++)
	{
		houseArray[i]->print();
	}
	string searchLastName = "";
	string typePolis;
	while (typePolis != "q" && typePolis != "Q")
	{
		string resultPolis;
		typePolis = ReturnString("Введите тип полиса: ");
		// searchLastName = ReturnString("Введите фамилию для поиска: ");

		for (char& c : typePolis)
		{
			resultPolis += tolower(c);
		}
		if (typePolis == "q" || typePolis == "Q")
		{
			cout << "Выход" << endl;
			continue;
		}
		else if (resultPolis == "oms")
		{
			searchLastName = ReturnString("Введите фамилию для поиска: ");
			count = CountLastName(omsArray, searchLastName, numPolis);
		}
		else if (resultPolis == "house")
		{
			searchLastName = ReturnString("Введите фамилию для поиска: ");
			count = CountLastName(houseArray, searchLastName, numPolis);
		}
		else if (resultPolis == "all")
		{
			searchLastName = ReturnString("Введите фамилию для поиска: ");
			count = CountLastName(omsArray, houseArray, searchLastName, numPolis);
		}
		else
		{
			cout << "Такого типа полиса не существует! " << endl;
			continue;
		}

		cout << "Количество полюсов на заданную фамилию: " << count << endl;
		count = 0;

	}

	for (int i = 0; i < numPolis; i++)
	{
		cout << "\n" << setfill('-') << setw(60) << " " << endl;
		delete omsArray[i];
	}
	delete[] omsArray;

	for (int i = 0; i < numPolis; i++)
	{
		cout << "\n" << setfill('-') << setw(60) << " " << endl;
		delete houseArray[i];
	}
	delete[] houseArray;
}