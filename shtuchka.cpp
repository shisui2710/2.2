#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

int(*point(int *a, int number))(int *a, int number); \

int inversion(int *a, int number);
int neub(int *a, int number);
int neuv(int *a, int number);

int(*point(int *a, int number))(int *a, int number)
{
	int sum = 0;
	for (int i = 1; i < number; i++)
		sum = sum + a[i];
	cout << "sum = " << sum << endl;
	if (sum == a[0])
		return(inversion);
	if (sum > a[0])
		return(neub);
	return(neuv);
}

int neuv(int *a, int number)
{
	int s;
	for (int i = 0; i < number - 1; i++)
		for (int j = i + 1; j < number; j++)
			if (a[j] > a[i])
			{
				s = a[i];
				a[i] = a[j];
				a[j] = s;
			}
	return 0;
}

int neub(int *a, int number)
{
	int s;
	for (int i = 0; i < number - 1; i++)
		for (int j = i + 1; j < number; j++)
			if (a[j] < a[i])
			{
				s = a[i];
				a[i] = a[j];
				a[j] = s;
			}
	return 0;
}

int inversion(int *a, int number)
{
	int s;
	for (int i = 0; i < number / 2; i++)
	{
		s = a[i];
		a[i] = a[number - i - 1];
		a[number - i - 1] = s;
	}
	return 0;
}


int const n = 10;

int main()
{
	int mass[n];
	int i;
	int(*pf)(int *a, int num) = NULL;
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));
	for (i = 0; i < n; i++)
		mass[i] = rand() % 201 - 100;

	cout << "Исходный массив:" << endl;
	for (i = 0; i < n; i++)
		cout << mass[i] << " " << endl;

	pf = point(mass, n);
	pf(mass, n);

	cout << "Результат:" << endl;
	for (i = 0; i < n; i++)
		cout << mass[i] << " ";
	return 0;
}