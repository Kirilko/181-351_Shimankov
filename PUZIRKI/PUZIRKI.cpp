// PUZIRKI.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

int main()
{
	int size,t;
	std::cin >> size;
	int *a;
	a = new int[size];
	for (int i = 0; i < size; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1;j++) {
			if (a[j] > a[j + 1]) {
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < size; i++)
		std::cout << a[i] << " ";
}

