

#include "pch.h"
#include <iostream>


int main()
{
	setlocale(0, "RUS");
	char a[50] = { 0 };
	std::cin >> a;
	for (int i = 0; i < strlen(a); i++)
		a[i] += 3;
	std::cout << a;
}
