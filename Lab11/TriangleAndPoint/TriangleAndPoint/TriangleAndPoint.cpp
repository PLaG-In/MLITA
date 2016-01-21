// TriangleAndPoint.cpp: определяет точку входа для консольного приложения.
//Алитов Владимир Валерьевич ПС-21 11.1. Треугольник и точка (5)

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

double Area(double s1, double s2, double s3)
{
	double p = (s1 + s2 + s3) / 2;
	return sqrt(p * (p - s1) * (p - s2) * (p - s3));
}

double CountUpLengthOfSides(double x, double x1, double y, double y1)
{
	return sqrt(pow(x1 - x, 2) + pow(y1 - y, 2));
}

void CheckPoint(vector<pair<double, double>> &vect)
{
	const double d = 1e-6;
	double len1, len2, len3, len4, len5, len6, p, p1, p2, p3, area1, area2, area3, area;
	ofstream fout("output.txt");
	len1 = CountUpLengthOfSides(vect[1].first, vect[0].first, vect[1].second, vect[0].second);
	len2 = CountUpLengthOfSides(vect[2].first, vect[0].first, vect[2].second, vect[0].second);
	len3 = CountUpLengthOfSides(vect[1].first, vect[2].first, vect[1].second, vect[2].second);
	len4 = CountUpLengthOfSides(vect[1].first, vect[3].first, vect[1].second, vect[3].second);
	len5 = CountUpLengthOfSides(vect[2].first, vect[3].first, vect[2].second, vect[3].second);
	len6 = CountUpLengthOfSides(vect[0].first, vect[3].first, vect[0].second, vect[3].second);
	cout << len1 << " " << len2 << " " << len3 << " " << len4 << " " << len5 << " " << len6 << endl;
	area = Area(len1, len2, len3);
	area1 = Area(len1, len4, len6);
	area2 = Area(len2, len5, len6);
	area3 = Area(len3, len4, len5);
	cout << area << " " << area1 << " " << area2 << " " << area3 << endl;
	double areaSum = (area1 + area2 + area3);
	double res = areaSum - area;
	if (res <= d)
	{
		fout << "In";
	}
	else
	{
		fout << "Out";
	}
	cout << areaSum - area << endl;
	fout.close();
}

int main(int argc, char* argv[])
{
	ifstream fin("input3.txt");
	if (!fin)
	{
		cout << "Error: Can't open file!\n";
	}
	double x, y;
	vector<pair<double, double>> coords;
	for (size_t i = 0; i < 4; ++i)
	{
		fin >> x >> y;
		coords.push_back(make_pair(x, y));
	}
	CheckPoint(coords);
	fin.close();
	return 0;
}

