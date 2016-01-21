// StringReplacer.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

using namespace std;

string FindUniqueString(string inpString)
{
	map < char, int > dict;
	for (int i = 0; i < inpString.length(); i++)
	{

	}
}

int main()
{
	ifstream fin("input.txt");
	int len;
	string inpString;
	if (!fin.is_open())
	{
		cout << "Error: can't open input file" << endl;
		return 0;
	}
	fin >> len;
	fin >> inpString;
	FindUniqueString(inpString);
	return 0;
}

