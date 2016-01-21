// FenvickTree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
std::vector<int> vec;
int n;

void init(int nn)
{
	n = nn;
	vec.assign(n, 0);
}

int sum(int r)
{
	int result = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		result += vec[r];
	return result;
}

void inc(int i, int delta)
{
	for (; i < n; i = (i | (i + 1)))
		vec[i] += delta;
}

int sum(int l, int r)
{
	return sum(r) - sum(l - 1);
}

void init(std::vector<int> a)
{
	init((int)a.size());
	for (unsigned i = 0; i < a.size(); i++)
		inc(i, a[i]);
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream fin("input.txt");
	int num;
	fin >> num;
	vec.reserve(num);
	for (size_t i = 0; i < vec.size(); ++i)
	{
		fin >> vec[i];
	}
	init(vec);
	return 0;
}

