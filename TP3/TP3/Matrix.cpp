#include <math.h>
#include "Matrix.h"

Matrix::Matrix()
{
	ifstream fin(fileName);

	fin >> size;

	data = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; i++)
	{
		fin >> data[i];
	}

	fin.close();
}

Matrix::~Matrix()
{
	ofstream fin(fileName);

	fin << size;
	fin << endl;

	for (int i = 0; i < size; i++) {
		fin << data[i];
		fin << endl;
	}

	fin.close();

	delete[] data;
}

void Matrix::print()
{
	if (size == 0) {
		cout << "[Matrix is empty]" << endl;
		return;
	}

	cout << data[0] << " " << data[1] << endl;
	cout << data[2] << " " << data[3] << endl;
}

void Matrix::normalaize()
{
	if (size == 0) {
		cout << "[Matrix is empty]" << endl;
		return;
	}

	int max = data[0];

	for (int i = 1; i < size; i++)
	{
		int a = abs(data[i]);
		max = a > max ? a : max;
	}

	cout << "Result: " << max << endl;

}

void Matrix::fill()
{
	for (int i = 0; i < 4; i++)
	{
		int number;
		cout << "Enter number " << (i + 1) << ": ";
		cin >> number;

		data[i] = number;
	}

	size = 4;
}