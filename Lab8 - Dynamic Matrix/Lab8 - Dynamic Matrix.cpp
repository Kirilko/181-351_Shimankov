#include "pch.h"
#include <iostream>

class matrix {

 protected:
	int rows;
	int columns;
	double **matr;

 public:
	matrix();
	~matrix();

	bool input();
	bool input(int columns);
	void print();
	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);
	bool transp();

	int getRows();
	int getColumns();
	double getElem(int row, int col);
};
class  vector :public matrix
{
public:
	vector() { columns = 1; }
	bool multVec(vector vec2);
};
bool vector::multVec(vector vec2)
{
		int scal = 0;
		if (rows == vec2.getRows())
		{
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < 1; j++)
				{
					scal = scal + matr[i][j] * vec2.getElem(i, j);
				}
			std::cout << scal;
			return true;
		}
	else {
		std::cout << "error";
		return false;
	}
}



int main()
{
	setlocale(LC_ALL, "Russian");
	vector vec1, vec2;
	vec1.input();
	vec2.input();
	vec1.multVec(vec2);
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
	if (columns == 0) {
		std::cout << '\n' << "Кол-во столбцов: ";
		std::cin >> columns;
	}
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

/*bool matrix::input(int column)
{
	std::cout << "Кол-во строк: ";
	std::cin >> rows;
	columns = column;
	matr = new double*[rows];
	for (int i = 0; i < rows; i++) {
		matr[i] = new double[columns];
	}
	std::cout << '\n' << "Матрица: ";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cin >> matr[i][j];
		}
	}

	return true;
}*/

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
				double sum = 0;
				for (int k = 0; k < matr2.getColumns(); k++) {
					sum += matr[i][k] * matr2.getElem(k, j);
				}
				matr3[i][j] = sum;
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
