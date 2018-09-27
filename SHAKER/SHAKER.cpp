// SHAKER.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

int main()
{
	int size, t, left, right;
	std::cin >> size;
	int *a;
	a = new int[size];
	for (int i = 0; i < size; i++) {
		std::cin >> a[i];
	}
	left = 0;
	right = size-1;
	while(left<right){
		for (int i = left; i < right; i++) {
			if (a[i] > a[i + 1]) {
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
			}
		}
		right--;
		for (int i = right; i > left; i--) {
			if (a[i - 1] > a[i]) {
				t = a[i];
				a[i] = a[i - 1 ];
				a[i - 1] = t;
			}
		}
		left++;
	}
	
	for (int i = 0; i < size; i++)
		std::cout << a[i] << " ";
}

