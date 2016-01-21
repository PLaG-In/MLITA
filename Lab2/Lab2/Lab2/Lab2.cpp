// Lab2.cpp: определяет точку входа для консольного приложения.
//
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;
int map[300][300];
int newMap[300][300];
int xSteps[10000];
int ySteps[10000];
int x2, y2, steps, N;

void RefreshArray(bool no, int x, int y, int x1, int y1)
{
	int temp = map[x][y];
	steps++;
	xSteps[steps] = x1;
	ySteps[steps] = y1;
	temp++;
	map[x1][y1] = temp;
	no = false;
}

void SearchWay(bool &norm, int &x, int &y)
{
	if ((x >= 0 && x < N) && (y >= 0 && y < N))
	{
		if (x > 2 && y < N)
		{
			if (map[x - 2][y + 1] == 0)
			{
				RefreshArray(norm, x, y, x - 2, y + 1);
			}
		}
		if (x > 1 && y < N)
		{
			if (map[x - 1][y + 2] == 0)
			{
				RefreshArray(norm, x, y, x - 1, y + 2);
			}
		}
		if (x < N && y < N)
		{
			if (map[x + 1][y + 2] == 0)
			{
				RefreshArray(norm, x, y, x + 1, y + 2);
			}
			if (map[x + 2][y + 1] == 0)
			{
				RefreshArray(norm, x, y, x + 2, y + 1);
			}
		}
		if (x < N && y > 1)
		{
			if (map[x + 2][y - 1] == 0)
			{
				RefreshArray(norm, x, y, x + 2, y - 1);
			}
		}
		if (x < N && y > 2)
		{
			if (map[x + 1][y - 2] == 0)
			{
				RefreshArray(norm, x, y, x + 1, y - 2);
			}
		}
		if (x > 1 && y > 2)
		{
			if (map[x - 1][y - 2] == 0)
			{
				RefreshArray(norm, x, y, x - 1, y - 2);
			}
		}
		if (x > 2 && y > 1)
		{
			if (map[x - 2][y - 1] == 0)
			{
				RefreshArray(norm, x, y, x - 2, y - 1);
			}
		}
	}
}

void LoadField()
{
	ifstream fin("input.txt");
	if (!fin.is_open())
	{
		cout << "Error: can't open input file\n";
	}
	int steps = 0;
	fin >> N;
	char step = '@', hole = '#';
	char temp;
	while (!fin.eof())
	{
		for (size_t i = 0; i < N; ++i)
		{
			for (size_t j = 0; j < N; ++j)
			{
				fin >> temp;
				if (temp == step)
				{
					if (steps == 1)
					{
						x2 = i;
						y2 = j;
					}
					if (steps == 0)
					{
						map[i][j] = 1;
						xSteps[steps] = i;
						ySteps[steps] = j;
						steps++;
					}
				}
				else
				{
					if (temp == hole)
					{
						map[i][j] = -2;
					}
					else
					{
						map[i][j] = 0;
					}
				}
			}
		}
	}
	fin.close();
}

void GetResult(string result)
{
	ofstream fout("output.txt");
	if (!fout)
	{
		cout << "Error";
	}
	fout << result << endl;
	fout.close();
}

void CheckPlace(int &x, int& y)
{
	if ((x < N && x > 1) && (y < N && y > 1))
	{
		if (x > 2 && y < N && (map[x][y] - map[x - 2][y + 1] == 1))
		{
			x -= 2;
			y += 1;
			return;
		}
		if (x > 1 && y < N - 1 && (map[x][y] - map[x - 1][y + 2] == 1))
		{
			x -= 1;
			y += 2;
			return;
		}
		if (x < N && y < N - 1 && map[x][y] - map[x + 1][y + 2] == 1)
		{
			x += 1;
			y += 2;
			return;
		}
		if (x < N - 1 && y < N && (map[x][y] - map[x + 2][y + 1] == 1))
		{
			x += 2;
			y += 1;
			return;
		}
		if (x < N - 1 && y > 1 && (map[x][y] - map[x + 2][y - 1] == 1))
		{
			x += 2;
			y -= 1;
			return;
		}
		if (x < N && y > 2 && (map[x][y] - map[x + 1][y - 2] == 1))
		{
			x += 1;
			y -= 2;
			return;
		}
		if (x > 1 && y > 2 && (map[x][y] - map[x - 1][y - 2] == 1))
		{
			x -= 1;
			y -= 2;
			return;
		}
		if (x > 2 && y > 1 && (map[x][y] - map[x - 2][y - 1] == 1))
		{
			x -= 2;
			y -= 1;
			return;
		}
	}
}

void SaveArray()
{
	char step = '@', hole = '#';
	ofstream fout("output.txt");
	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = 0; j < N; ++j)
		{
			if (map[i][j] == -2)
			{
				fout << hole;
			}
			else
			{
				if (newMap[i][j] == step)
				{
					fout << step;
				}
				else
				{
					fout << '.';
				}
			}
		}
		fout << endl;
	}
	fout.close();
}

int main(int argc, char* argv[])
{
	LoadField();
	bool norm = false;
	int count1 = 0, x, y, x1, y1;
	x1 = xSteps[count1];
	y1 = ySteps[count1];
	steps = 0;
	char step = '@';
	do
	{
		norm = true;
		for (int i = 0; i <= steps; ++i)
		{
			int x = xSteps[count1];
			int y = ySteps[count1];
			SearchWay(norm, x, y);
			count1++;
		}
	} while (map[x2][y2] > 0 || norm);
	if (norm)
	{
		GetResult("Impossible");
		return 0;
	}
	else
	{
		x = x2;
		y = y2;
		newMap[x][y] = step;
		do
		{
			CheckPlace(x, y);
			newMap[x][y] = step;
		} while (newMap[x1][y1] == step);
		SaveArray();
	}
	return 0;
}

