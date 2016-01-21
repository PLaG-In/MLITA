// SwimmingPool.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	int quan, count, doctor;
	if (!fin.is_open())
	{
		cout << "Error: can't open input file" << endl;
		return 0;
	}
	fin >> quan;
	vector <vector <int>> matrix;
	matrix.resize(quan);
	for (size_t i = 0; i < quan; i++)
	{
		fin >> count;
		matrix[i].resize(quan);
		for (size_t j = 0; j < count; j++)
		{
			fin >> doctor;
			matrix[doctor - 1][count - 1] = 1;
		}
	}
	for (size_t i = 0; i < quan; ++i)
	{
		cout << endl;
		for (size_t j = 0; j < quan; ++j)
		{
			cout << matrix[i][j];
			int number;			
		}
	}
	system("pause");
	return 0;
}

