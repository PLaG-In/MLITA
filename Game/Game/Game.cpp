// Game.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

void ChooseWinner(ifstream &fin, ofstream &fout)
{
	int count, x, y;
	fin >> count;
	for (size_t i = 0; i < count; ++i)
	{
		fin >> x;
		fin >> y;
		if ((x % 2 == 0) || (y % 2 == 0))
		{
			fout << "1\n";
		}
		else
		{
			fout << "2\n";
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Usage: game [file1] [file2] \n";
		return 1;
	}
	ifstream fin(argv[1]);
	if (!fin)
	{
		return 1;
	}
	ofstream fout(argv[2]);
	if (!fout)
	{
		return 1;
	}
	ChooseWinner(fin, fout);
	return 0;
}

