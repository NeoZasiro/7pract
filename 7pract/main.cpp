#include <iostream>
#include <Windows.h>
#include <iomanip>
#include "Class Polis.h"
using namespace std;

//Вариант А.
//Задание 1. В соответствии с индивидуальным заданием(см.приложение) создать класс для предметной области.
//Задание 2. Спроектировать шаблон класса с одним обобщенным типом.
//Задание 3. Разработать реализацию шаблона класса для каждого из двух вычисляемых показателей.

string ReturnString(string text)
{
	cout << text;
	cin >> text;
	return text;
}

int CountLastName(Polis<string>* polis[], string searchLastName, int numPolis)
{
	int count{};
	for (int k = 0; k < numPolis; k++)
	{
		if (polis[k]->GetPolisLastName() == searchLastName)
		{
			count++;
		}
	}
	return count;
}

int findMinNumber(Polis<string>* polis[], int numPolis)
{
	int min = polis[0]->GetPolisNumber();
	for (int i = 0; i < numPolis; i++)
	{
		if (polis[i]->GetPolisNumber() <= min)
		{
			min = polis[i]->GetPolisNumber();
		}
	}
	return min;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	const int numPolis = 5;
	int count = 0;

	Polis<string>** polisArray = new Polis<string> *[numPolis]
		{
			new Polis<string>(1234, "Иван", "Иванов", "01.01.2025"),
				new Polis<string>(8543, "Даниил", "Коннов", "02.09.2027"),
				new Polis<string>(1001, "Григорий", "Иванов", "03.11.2024"),
				new Polis<string>(2222, "Игорь", "Федоров", "06.06.2024"),
				new Polis<string>(3421, "Леонид", "Федоров", "07.07.2026")
		};

	for (int i = 0; i < numPolis; i++)
	{
		polisArray[i]->print();
	}

	cout << "Полис с наименьшим номером: " << findMinNumber(polisArray, numPolis) << endl;
	int countLastName = CountLastName(polisArray, ReturnString("Введите фамилию для поиска: "), numPolis);
	cout << "Количество полюсов на заданную фамилию: " << countLastName << endl;

	for (int i = 0; i < numPolis; i++)
	{
		cout << "\n" << setfill('-') << setw(60) << " " << endl;
		delete polisArray[i];
	}
	delete[] polisArray;
}