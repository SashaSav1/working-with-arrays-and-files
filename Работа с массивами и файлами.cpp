//Реализовать возможность ввода размерности массива и его элементов из текстового файла(+1)
//Вычислить произведение четных элементов массива и вывести его на экран. (+0.5)
//Найти в каждой строке количество четных элементов и вывести найденные значения(+1) в текстовый файл в строку(+1).
//Найти минимальный четный элемент массива и вывести его на экран.Если четных элементов нет, то выведите соответствующее сообщение(+1).
//Заменить в  первой строке все однозначные элементы на 0 (+1).
//Вывести измененный массив в текстовый файл в виде матрицы(+1.5)
//Найти произведение номера столбца и номера строки в которых содержится последний максимальный элемент(+1).
//Вычислить количество делителей найденного значения(+1).Оформить алгоритм в виде функции(+1).

#include <iostream>
#include <fstream>

using namespace std;

int func(int a)
{
	int score = 0;

	for (int i = 1; i <= a; i++)
	{
		if ((a % i) == 0)
		{
			score++;
		}
	}
	return score;
}

int main()
{
	setlocale(LC_ALL, "ru");

	int a, b;
	int arr[10][10];
	int proiz = 1;
	int score = 0;
	int minChet = 0;
	int max = 0;
	int placeMax = 0;



	fstream f;

	f.open("1.txt", ios::in);

	f >> a >> b;

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				f >> arr[i][j];
			}
		}

	f.close();

	cout << "Массив : " << endl;

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if ((arr[i][j] % 2) == 0)
			{
				proiz *= arr[i][j];
			}
		}
	}

	cout << "Произведение четных элементов массива : " << proiz << endl;

	f.open("1.txt", ios::app);

	f << endl;

	for (int i = 0; i < a; i++)
	{
		score = 0;
		for (int j = 0; j < b; j++)
		{
			if ((arr[i][j] % 2) == 0)
			{
				score++;

			}
		}
		f << endl << "Кол-во четных элементов в " << i + 1 << " строке : " << score << endl;
		cout << endl;
	}
	f << endl;
	f.close();

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if ((arr[i][j] < arr[i][j+1]) && ((arr[i][j] % 2) == 0))
			{
				minChet = arr[i][j];
			}
		}
	}

	if (minChet > 0)
	{
		cout << "Минимальный четный элемент массива : " << minChet << endl;
	}
	else
	{
		cout << "Минимального четного элемента в массиве нет" << endl;
	}

	f.open("1.txt", ios::app);


	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if ((arr[i][j] >= 10) && (arr[i][j] <= 99))
			{
				arr[i][j] = 0;
			}
		}
		break;
	}

	f << "Новый массив : " << endl << endl;

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			f << arr[i][j] << " ";
		}
		f << endl;
	}

	f.close();

	f.open("1.txt", ios::in);

	f >> a >> b;

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			f >> arr[i][j];
		}
	}

	f.close();

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if (arr[i][j] < arr[i][j + 1])
			{
				max = arr[i][j + 1];				
			}

		}
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
			}

		}
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if (arr[i][j] == max)
			{
				placeMax = (i + 1) * (j + 1);
			}

		}
	}

	cout << "Произведение номера столбца и номера строки в которм находится последний максимальный элемент : " << placeMax << endl;

	cout << "Kол-во делителей числа, который отвечает за произведение номера столбца и номера строки в которм находится последний максимальный элемент : " << func(placeMax);









}
