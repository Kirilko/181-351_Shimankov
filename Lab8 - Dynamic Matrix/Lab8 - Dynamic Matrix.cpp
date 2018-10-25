#include "pch.h"
#include <iostream>

class matrix {

 private:
	int rows;
	int columns;
	double **matr;

 public:
	matrix();
	~matrix();

	bool input();
	void print();
	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);
	bool transp();

	int getRows();
	int getColumns();
	double getElem(int row, int col);
};


int main()
{
	setlocale(LC_ALL, "Russian");
	matrix matrA, matrB;
	return 0;
}

matrix::matrix()
{
}

matrix::~matrix()
{
}

bool matrix::input()
{
	std::cout << "Кол-во строк: ";
	std::cin >> rows;
	std::cout << '\n'<< "Кол-во столбцов: ";
	std::cin >> columns;
	matr = new double* [rows];
	for (int i = 0; i < rows; i++) {
		matr[i] = new double[columns];
	}
	std::cout <<'\n'<< "Матрица: ";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cin >> matr[i][j];
		}
	}
	
	return true;
}

void matrix::print()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << matr[i][j] << '\t';
		}
		std::cout << '\n';
	}
}

bool matrix::summMatrix(matrix matr2)
{
	double **result = new double* [rows];
	for (int i = 0; i < rows; i++) {
		result[i] = new double[columns];
	}
	std::cout << '\n' << "Сумма: " << '\n';
	if ((rows == matr2.getRows()) && (columns == matr2.getColumns())) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				result[i][j] = matr[i][j] + matr2.getElem(i, j);
				std::cout << result[i][j] << '\t';
			}
			std::cout << '\n';
		}
		return true;
	}
	else return false;
}

bool matrix::multMatrix(matrix matr2)
{
	double **matr3 = new double*[rows];
	for (int i = 0; i < rows; i++) {
		matr3[i] = new double[columns];
	}
	if (columns == matr2.getRows()) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < rows; j++) {
				for (int k = 0; k < matr2.getColumns(); k++) {
					matr3[i][j] = matr[i][k] * matr2.getElem(k, j);
				}
			}
		}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			std::cout << matr3[i][j] << '\t';
		}
		std::cout << '\n';
	}
	return true;
}
	else return false;
}

bool matrix::transp()
{
	int ch;
	if (rows != columns) {
		ch = rows;
		rows = columns;
		columns = ch;
	}
	double temp = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = i; j < columns; j++) {
			temp = matr[i][j];
			matr[i][j] = matr[j][i];
			matr[j][i] = temp;
		}
	}
	return true;
}

int matrix::getRows()
{
	return rows;
}

int matrix::getColumns()
{
	return columns;
}

double matrix::getElem(int row, int col)
{
	if (row<rows && col<columns && row>-1 && col>-1)
		return matr[row][col];
	else
		return -11111111111;
	std::cout << "Error!\n";
	return -1;
}
