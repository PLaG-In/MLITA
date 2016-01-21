//Алитов Владимир Валерьевич ПС-21 Лабораторная работа 10.1. Последовательность 1 (6)
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
	int sq;
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
			if (an == sq % m)
			{
				return an;
			}
			an = sq % m;
			vector<int>::iterator it = find(vect.begin(), vect.end(), an);
			if (it != vect.end())//Вектор заполняется уникальными числами последовательности
			{
				idx = distance(vect.begin(), it);
				break;
			}
			else
			{
				vect.push_back(an);
			}
			fout << an << endl;
		}
		if (n > vect.size())//С помощью вектора вычисляем искомый N-ый элемент
		{
			int len = vect.size() - idx;
			if (len == 2)
			{
				if ((n + idx) % 2 == 0)
				{
					return an = vect[idx];
				}
				else
				{
					return an = vect[idx + 1];
				}
			}
			int ost = n % len;
			if (ost != 0)
			{
				return an = vect[ost - 2];
			}
			else
			{
				return an = vect[len - 2];
			}
		}
		else
		{
			return vect[n];
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