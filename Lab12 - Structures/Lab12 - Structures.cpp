#include <iostream> 

#include <stack> // подключаем библиотеку для использования стека 
#include <queue> // подключили библиотеку для использования очереди 
#include <deque> // подключили библиотеку для использования дека
#include <string>

#include <list> // подключили библиотеку для использования списка
#include <set> // подключили библиотеку для использования множества
#include <map> // подключили библиотеку для использования ассоциативного массива
int main()
{
	setlocale(LC_ALL, "rus");
	/*
	Стек — это структура данных, которая работает
	по принципу FILO(first in — last out; первый пришел — последний ушел).

	В стеке нет индексов,т.е. нельзя обратиться к определенному элементу.
	Каждый элемент имеет указатель на следующий элемент.
	Головной элемент указывает на NULL.

	Достоинство: операции удаления и добавления элемента делаются за const время.

	*/

	/*std::stack<int> stackInt;//stack <тип данных> <имя>; -создание стека
	int i = 0, a = 0;
	std::cout << "Введите 5 целых чисел: " << std::endl;
	while (i != 5) {
		std::cin >> a;
		stackInt.push(a); // добавляем введенное число
		i++;
	}

	if (stackInt.empty()) // проверяем пуст ли стек (нет)
		std::cout << "Стек не пуст";

	std::cout << "Верхний элемент стека: " << stackInt.top() << std::endl;
	stackInt.pop(); // удаляем верхний элемент

	std::cout << "Новый верхний элемент: " << stackInt.top() << std::endl;
	*/


	/*
	Проверить правильность расстановки скобок (,),[,],{,}
	в введенном пользователем выражении за линейное время
	(один просмотр выражения).
	2+4-5(87192479_7348){72648]76823[] -> no
	({}) -> yes
	({)} -> no
	*/

	/*
	Считываем элемент.
	Если это (,[ или {, то помещаем ее в стек.
	Если это ),] или }, то сравниваем с верхним элементом стека.
	Если образовалась пара, то верхний элемент стека удаляем.
	Иначе - выражение неправильное.

	Когда все элементы считали, то проверяем стек на пустоту.
	Если стек пуст, то выражение правильное.
	Иначе - выражение неправильное.
	*/

	/*
	Очередь — это структура данных, которая построена по принципу
	LILO (last in — last out: последним пришел — последним вышел).
	*/
	/*int i = 0, a = 0;
	std::queue <int> MyQueue; // создали очередь
	std::cout << "Введите 7 чисел: " << std::endl;
	for (i = 0; i < 7; i++) {
		std::cin >> a;
		MyQueue.push(a); // добавляем в очередь элементы
	}
	std::cout << std::endl;
	std::cout << "Первый элемент в очереди: " << MyQueue.front() << std::endl;
	MyQueue.pop(); // удаляем элемент из очереди
	std::cout << "Первый элемент (после удаления): " << MyQueue.front() << std::endl;

	if (!MyQueue.empty()) // проверяем пуста ли очередь (нет)
		std::cout << "Очередь не пуста!";
	/*
	Очередь с приоритетом (priority_queue) — это обычная очередь,
	но в ней новый элемент добавляется в такое место,
	чтобы очередь была отсортирована по убыванию.
	*/

	/*std::priority_queue <int> priority_q; // объявляем приоритетную очередь

	std::cout << "Введите 7 чисел: " << std::endl;
	for (i = 0; i < 7; i++) {
		std::cin >> a;
		priority_q.push(a); // добавляем элементы в очередь
	}
	// выводим первый
	std::cout << "Первый элемент очереди: " << priority_q.top();

	// ЗАДАНИЕ 2
	/*
	Программа на вход получает список школьников.
	В каждой строке сначала записан номер класса (число, равное 9, 10 или 11),
	затем (через пробел) – фамилия.
	Необходимо вывести список по классам:
	сначала всех учащихся 9 класса, затем – 10, затем – 11.
	Внутри одного класса порядок вывода должен быть таким же, как на входе.
	*/
	//Задание 1 (скобки)
	/*std::stack<char> bracket;
			char a = 0;
			std::cin >> a;
			while (a!= '=') {

				if (a == '(' || a == '[' || a == '{') {
					bracket.push(a);
				}
				else if (bracket.top() == '('&& a==')') {
					bracket.pop();
				}
				else if (bracket.top() == '{'&& a == '}') {
					bracket.pop();
				}
				else if (bracket.top() == '['&& a == ']') {
					bracket.pop();
				}
				std::cin >> a;
			}
			if (bracket.empty()) {
				std::cout << "Yes" << std::endl;
			}
			else std::cout << "No" << std::endl;
			*/
			//Задание 2 (классы)
			/*std::queue <std::string> class9;
			std::queue <std::string> class10;
			std::queue <std::string> class11;
			std::string name;
			int cl;
			std::cin >> cl;
			for (;;) {
				if (cl == 0) {
					break;
				} else{
					getline(std::cin, name);
					switch (cl) {
					case 9:
						class9.push(name);
						break;
					case 10:
						class10.push(name);
						break;
					case 11:
						class11.push(name);
						break;
					}
					std::cin >> cl;
				}
			}
			std::cout << "9" << std::endl;
			while (!class9.empty()) {
				std::cout << class9.front() << std::endl;
				class9.pop();
			}
			std::cout << std::endl<< "10" << std::endl;
			while (!class10.empty()) {
				std::cout << class10.front() << std::endl;
				class10.pop();
			}
			std::cout <<std::endl << "11" << std::endl;
			while (!class11.empty()) {
				std::cout << class11.front() << std::endl;
				class11.pop();
			}
			*/
			//Задание 3 (полиндромы)
			/*

			std::deque<char> slovo;
			char a;
			std::cin >> a;
			for (;;) {
				if (a == '.') {
					break;
				}
				else {
					slovo.push_front(a);
				}
				std::cin >> a;
			}
			while (!slovo.empty()) {
				if (slovo.front() != slovo.back()) {
					break;
				}
				else if (slovo.front() == slovo.back()) {
					slovo.pop_back();
					if (!slovo.empty()) {
						slovo.pop_front();
					}
				}
			}
			if (slovo.empty()) {
				std::cout << "Yes" << std::endl;
			}
			else std::cout << "No" << std::endl
			*/
			//Задание 4 (list)
			/*std::list<int> myList;
			int a;
			for (int i = 0; i < 4; i++) {
				std::cin >> a;
				if (i == 0) {
					myList.push_front(a);
				}
				else myList.push_back(a);
			}
			myList.sort();
			myList.pop_front();
			myList.pop_back();
			for (std::list<int>::iterator i = myList.begin(); i != myList.end(); i++) {
				std::cout << *i;
			}
			myList.clear();*/
			//Задание 5 (set)
			/*std::set<int> mySet;
			int a;
			for (int i = 0; i < 5; i++) {
				std::cin >> a;
				mySet.insert(a);
			}
			for (std::set<int>::iterator i = mySet.begin(); i != mySet.end(); i++) {
				std::cout << *i << ' ';
			}
			mySet.erase(3);
			std::cout << std::endl;
			for (std::set<int>::iterator i = mySet.begin(); i != mySet.end(); i++) {
				std::cout << *i << ' ';
			}*/
			//Задание 6(map) не доделано
	/*std::map<int, int> myMap;
	int a;
	for (int i = 0; i < 4; i++) {
		std::cin >> a;
		myMap.emplace(i, a);
	}
	for (int i = 3; i > -1; i--) {
		std::cout << myMap[i] << ' ';
	}*/
	/*
	Создаем 3 очереди (свою для каждого класса).

	Считываем очередную строку. В зависимости от класса
	добавляем фамилию в соответствующую очередь

	Когда все считали, выводим очереди последовательно:

	сначала для 9 класса, затем очередь 10 класса,
	а в самом конце очередь 11 класса.
	*/

	/*
	Деком (англ. deque – аббревиатура от double-ended queue, двухсторонняя очередь)
	называется структура данных, в которую можно*/
	/*std::deque<int> dequeInt;//deque <тип данных> <имя>; -создание стека 
	int i = 0, a = 0;
	std::cout << "Введите 5 целых чисел: " << std::endl;
	while (i != 5) {
		std::cin >> a;
		dequeInt.push_front(a); // добавляем введенное число 
		i++;
	}

	if (dequeInt.empty()) // проверяем пуст ли стек (нет) 
		std::cout << "Стек не пуст";

	std::cout << "Верхний элемент стека: " << dequeInt.back
	() << std::endl;
	dequeInt.pop_back(); // удаляем верхний элемент 

	std::cout << "Новый верхний элемент: " << dequeInt.back() << std::endl;*/
system("pause");
return 0;
}