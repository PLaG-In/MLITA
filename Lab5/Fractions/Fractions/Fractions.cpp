//Алитов Владимир Валерьевич ПС-21 5.3. Упорядоченные дроби (6)
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int Nod(int a, int b) {
	while (a != b)
		a > b ? a -= b : b -= a;
	return a;
}

void FindFractions(int n)
{
	errno_t err;
	FILE* fout;
	if ((err = fopen_s(&fout, "output.txt", "w")) != 0)
	{
		cout << "file don't open" << "\n";
		return;
	}
	vector<pair<int, int>> frac;
	string fraction;
	for (size_t i = 1; i < n; ++i)
	{
		for (size_t j = 1; j <= n; ++j)
		{
			if (i != j && j > i)
			{
				if (Nod(i, j) == 1)
				{
					frac.push_back(make_pair(i, j));
				}
			}
		}
	}
	sort(frac.begin(), frac.end(), [](const pair<int, int> &a, const pair<int, int> &b){return a.first * b.second < a.second * b.first; });
	for (size_t i = 0; i < frac.size(); ++i)
		fprintf(fout, "%u/%u\n",frac[i].first, frac[i].second);
	fclose(fout);
}

int main(int argc, char* argv[])
{
	int n;
	ifstream fin(argv[1]);
	if (!fin)
	{
		cout << "Error: Failed open file!" << endl;
	}
	fin >> n;
	if (n < 2 && n > 1000)
	{
		cout << "Error: N - out of range(2 < n < 1000)" << endl;
	}
	FindFractions(n);
	fin.close();
	return 0;
}

