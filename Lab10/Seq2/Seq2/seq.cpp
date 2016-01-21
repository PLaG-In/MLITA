//Алитов Владимир Валерьевич ПС-21 10.1. Последовательность 1 (6)
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int CountUpAN(int &m, int &n, int &a1)
{
	vector <int> vect;
	size_t idx;
	ofstream fout("myres.txt");
	int sq, count, count1;
	int an = a1;
	if (a1 == 0 || a1 == 1)
	{
		return a1;
	}
	else
	{
		for (size_t i = 0; i < n - 1; ++i)
		{
			sq = an * an;
			an = sq % m;
		}
	}
	fout.close();
	return an;
}

int main()
{
	ifstream fin("input.txt");
	if (!fin)
	{
		cout << "Error: Can't open file!\n";
	}
	int m, n, a1, an;
	fin >> m >> n >> a1;
	if ((m < 1 || m > 10000)
		|| (n < 2 || n > 2 * pow(10, 9))
		|| (a1 < 0 || a1 > m))
	{
		cout << "Error: Out of range(m, n or a1)\n";
	}
	an = CountUpAN(m, n, a1);
	ofstream fout("output.txt");
	if (!fout)
	{
		cout << "Error: Can't create output file!\n";
	}
	fout << an;
	fin.close();
	fout.close();
	return 0;
}