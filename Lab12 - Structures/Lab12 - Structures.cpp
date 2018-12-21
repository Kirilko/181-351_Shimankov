#include <iostream> 

#include <stack> // ���������� ���������� ��� ������������� ����� 
#include <queue> // ���������� ���������� ��� ������������� ������� 
#include <deque> // ���������� ���������� ��� ������������� ����
#include <string>

#include <list> // ���������� ���������� ��� ������������� ������
#include <set> // ���������� ���������� ��� ������������� ���������
#include <map> // ���������� ���������� ��� ������������� �������������� �������
int main()
{
	setlocale(LC_ALL, "rus");
	/*
	���� � ��� ��������� ������, ������� ��������
	�� �������� FILO(first in � last out; ������ ������ � ��������� ����).

	� ����� ��� ��������,�.�. ������ ���������� � ������������� ��������.
	������ ������� ����� ��������� �� ��������� �������.
	�������� ������� ��������� �� NULL.

	�����������: �������� �������� � ���������� �������� �������� �� const �����.

	*/

	/*std::stack<int> stackInt;//stack <��� ������> <���>; -�������� �����
	int i = 0, a = 0;
	std::cout << "������� 5 ����� �����: " << std::endl;
	while (i != 5) {
		std::cin >> a;
		stackInt.push(a); // ��������� ��������� �����
		i++;
	}

	if (stackInt.empty()) // ��������� ���� �� ���� (���)
		std::cout << "���� �� ����";

	std::cout << "������� ������� �����: " << stackInt.top() << std::endl;
	stackInt.pop(); // ������� ������� �������

	std::cout << "����� ������� �������: " << stackInt.top() << std::endl;
	*/


	/*
	��������� ������������ ����������� ������ (,),[,],{,}
	� ��������� ������������� ��������� �� �������� �����
	(���� �������� ���������).
	2+4-5(87192479_7348){72648]76823[] -> no
	({}) -> yes
	({)} -> no
	*/

	/*
	��������� �������.
	���� ��� (,[ ��� {, �� �������� �� � ����.
	���� ��� ),] ��� }, �� ���������� � ������� ��������� �����.
	���� ������������ ����, �� ������� ������� ����� �������.
	����� - ��������� ������������.

	����� ��� �������� �������, �� ��������� ���� �� �������.
	���� ���� ����, �� ��������� ����������.
	����� - ��������� ������������.
	*/

	/*
	������� � ��� ��������� ������, ������� ��������� �� ��������
	LILO (last in � last out: ��������� ������ � ��������� �����).
	*/
	/*int i = 0, a = 0;
	std::queue <int> MyQueue; // ������� �������
	std::cout << "������� 7 �����: " << std::endl;
	for (i = 0; i < 7; i++) {
		std::cin >> a;
		MyQueue.push(a); // ��������� � ������� ��������
	}
	std::cout << std::endl;
	std::cout << "������ ������� � �������: " << MyQueue.front() << std::endl;
	MyQueue.pop(); // ������� ������� �� �������
	std::cout << "������ ������� (����� ��������): " << MyQueue.front() << std::endl;

	if (!MyQueue.empty()) // ��������� ����� �� ������� (���)
		std::cout << "������� �� �����!";
	/*
	������� � ����������� (priority_queue) � ��� ������� �������,
	�� � ��� ����� ������� ����������� � ����� �����,
	����� ������� ���� ������������� �� ��������.
	*/

	/*std::priority_queue <int> priority_q; // ��������� ������������ �������

	std::cout << "������� 7 �����: " << std::endl;
	for (i = 0; i < 7; i++) {
		std::cin >> a;
		priority_q.push(a); // ��������� �������� � �������
	}
	// ������� ������
	std::cout << "������ ������� �������: " << priority_q.top();

	// ������� 2
	/*
	��������� �� ���� �������� ������ ����������.
	� ������ ������ ������� ������� ����� ������ (�����, ������ 9, 10 ��� 11),
	����� (����� ������) � �������.
	���������� ������� ������ �� �������:
	������� ���� �������� 9 ������, ����� � 10, ����� � 11.
	������ ������ ������ ������� ������ ������ ���� ����� ��, ��� �� �����.
	*/
	//������� 1 (������)
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
			//������� 2 (������)
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
			//������� 3 (����������)
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
			//������� 4 (list)
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
			//������� 5 (set)
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
			//������� 6(map) �� ��������
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
	������� 3 ������� (���� ��� ������� ������).

	��������� ��������� ������. � ����������� �� ������
	��������� ������� � ��������������� �������

	����� ��� �������, ������� ������� ���������������:

	������� ��� 9 ������, ����� ������� 10 ������,
	� � ����� ����� ������� 11 ������.
	*/

	/*
	����� (����. deque � ������������ �� double-ended queue, ������������� �������)
	���������� ��������� ������, � ������� �����*/
	/*std::deque<int> dequeInt;//deque <��� ������> <���>; -�������� ����� 
	int i = 0, a = 0;
	std::cout << "������� 5 ����� �����: " << std::endl;
	while (i != 5) {
		std::cin >> a;
		dequeInt.push_front(a); // ��������� ��������� ����� 
		i++;
	}

	if (dequeInt.empty()) // ��������� ���� �� ���� (���) 
		std::cout << "���� �� ����";

	std::cout << "������� ������� �����: " << dequeInt.back
	() << std::endl;
	dequeInt.pop_back(); // ������� ������� ������� 

	std::cout << "����� ������� �������: " << dequeInt.back() << std::endl;*/
system("pause");
return 0;
}