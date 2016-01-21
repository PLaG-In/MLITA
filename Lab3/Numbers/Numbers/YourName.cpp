
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int CountUpNameVar(int n)
{
	string D;
	string name, endString;
	endString = string(n, 'D');
	name = string(n, 'A');
	int countVars = 0;
	while (name != endString)
	{

	}
	return 0;
}

int main()
{
	int n;
	ifstream fin("input.txt");
	if (!fin.is_open())
	{
		cout << "Error: can't open input file\n";
	}
	fin >> n;
	int maxBAD = n % 3;
	CountUpNameVar(n);
	return 0;
}