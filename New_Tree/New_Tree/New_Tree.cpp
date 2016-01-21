// New_Tree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

struct node
{
	int info;
	node *l, *r;
};
int T[15];
vector<int> tree;

void BuildTree(int i, int L, int R)
{
	int m;
	if (L == R)
	{
		T[i] = tree[L];
	}
	else
	{
		m = (L + R) / 2;
		BuildTree(2 * i, L, m);
		BuildTree(2 * i + 1, m + 1, R);
		T[i] = T[2 * i] + T[2 * i + 1];
	}
}

void Update(int Ind, int NewVal, int i, int L, int R)
{
	int m;
	if (L == R)
	{
		T[i] = NewVal;
	}
	else
	{
		m = (L + R) / 2;
		if (Ind <= m)
		{
			Update(Ind, NewVal, 2 * i, L, m);
		}
		else
		{
			Update(Ind, NewVal, 2 * i + 1, m + 1, R);
		}
		T[i] = T[2 * i] + T[2 * i + 1];
	}
}

int Summ(int L, int R, int i, int Tl, int Tr)
{
	int m;
	if ((L == Tl) && (R == Tr))
	{
		return T[i];
	}
	else
	{
		m = (Tl + Tr) / 2;
		if (R <= m)
		{
			return Summ(L, R, 2 * i, Tl, m);
		}
		else if (L > m)
		{
			return Summ(L, R, 2 * i + 1, m + 1, Tr);
		}
		else
		{
			return Summ(L, m, 2 * i, Tl, m) + Summ(m + 1, R, 2 * i + 1, m + 1, Tr);
		}
	}
}

void Plus(int L, int R, int X, int i, int Tl, int Tr)
{
	int m;
	T[i] = T[i] + X * (R - L + 1);
	if ((L == Tl) && (R == Tr))
	{
		Add[i] =
	}
	else
	{
		m = (Tl + Tr) / 2;
		if (R <= m)
		{
		}
		else
		{
			if (L > m)
			{
				Plus(L, R, X, 2 * i + 1, Tl, m)
			}
		}
	}
}

int main(int argc, char* argv[])
{
	ifstream fin("input.txt");
	if (!fin)
	{
		return 1;
	}
	int q;
	fin >> q;
	tree.reserve(q);
	int temp;
	for (int i = 0; i < q; ++i)
	{
		fin >> temp;
		tree.push_back(temp);
		cout << temp << endl;
	}
	system("pause");
	return 0;
}

