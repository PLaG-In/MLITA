// FarmerPlace.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

vector<int> FindAreas(int area)
{
	vector <int> areas;
	int j;
	for (size_t i = 1; i < area; ++i)
	{
		j = i * i;
		if (area - j < area && area - j > 0)
		{
			areas.push_back(j);
		}
	}
	vector<int> ways;
	for (int &elem : areas)
	{
		int counter = 0;
		int ost = area % elem;
		cout << "o " << ost << endl;
		if (area % elem == 0)
		{
			ways.push_back(area / elem);
		}
		else
		{
			for (int &elem2 : areas)
				if (elem2 == ost)
				{
					counter++;
					if (area == ost + elem)
					{
						ways.push_back(counter + area / elem);
						break;
					}
				}
				else
				{

				}
				
			ways.push_back(counter + area / elem);
		}
		cout << elem << endl;

	}
	for (int &elem : ways)
	{
		cout << "w " << elem << endl;
	}
	return areas;
}

//void AreaSeparator(vector <int> areas)
//{
//	for (size_t i = 0; i < areas.size(); ++i)
//	{
//		
//	}
//}

int main()
{
	ifstream fin("input.txt");
	int area;
	fin >> area;
	vector <int> areas = FindAreas(area);
	/*AreaSepatator(areas);*/
	system("pause");
	return 0;
}

