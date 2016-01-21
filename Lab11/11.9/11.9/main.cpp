#include <vector>
#include <iostream>
#include <stack>
#include <fstream>
#include <algorithm>

using namespace std;

struct CompareCoords
{
	pair<__int64, __int64> p;
	CompareCoords(pair<__int64, __int64> p)
	{
		this->p = p;
	}

	bool operator()(const pair<__int64, __int64> &p1, const pair<__int64, __int64> &p2)
	{
		long double coords = CheckCoords(p, p1, p2);
		if (coords > 0 || (coords == 0 && FindLength(p, p1) < FindLength(p, p2)))
		{
			return true;
		}
		return false;
	}
};

long double CheckCoords(const pair<__int64, __int64> &p1, const pair<__int64, __int64> &p2, const pair<__int64, __int64> &p3)
{
	return ((p2.first - p1.first) * (p3.second - p1.second) * 1.0 - (p2.second - p1.second) * (p3.first - p1.first) * 1.0);
}

long double FindLength(const pair<__int64, __int64> &p1, const pair<__int64, __int64> &p2)
{
	return sqrt((p2.first - p1.first) * (p2.first - p1.first) * 1.0 + (p2.second - p1.second) * (p2.second - p1.second) * 1.0);
}

int main()
{
	ifstream fin("input.txt");
	vector<pair<__int64, __int64>> coords;
	int N;
	fin >> N;
	int f = 0;
	for (int i = 0; i < N; i++)
	{
		__int64 x = 0, y = 0;
		fin >> x >> y;
		pair<__int64, __int64 > p = { x, y };
		coords.push_back(p);
		if (coords[f].second > p.second || (coords[f].second == p.second && coords[f].first > p.first))
		{
			f = i;
		}
	}
	swap(coords[0], coords[f]);
	sort(coords.begin() + 1, coords.end(), CompareCoords(coords[0]));
	vector<pair<__int64, __int64>> s;
	s.push_back(coords[0]);
	if (coords.size() > 1)
	{
		s.push_back(coords[1]);
		for (int i = 2; i < coords.size(); i++)
		{
			while (s.size() > 1 && CheckCoords(s[s.size() - 2], s[s.size() - 1], coords[i]) <= 0)
			{
				s.pop_back();
			}
			s.push_back(coords[i]);
		}
	}
	ofstream fout("output.txt");
	fout << s.size() << endl;
	for (int i = 0; i < s.size(); i++)
	{
		fout << s[i].first << " " << s[i].second << endl;
	}
	fin.close();
	fout.close();
	return 0;
}