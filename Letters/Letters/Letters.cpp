// Letters.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

void CheckWords(map <string, int> &dict, const string &mainWord)
{
	int counter, score = 0;
	int pos;
	std::vector<std::pair<string, int>> items;
	string tempWord = mainWord;
	/*sort(dict.begin(), dict.end());*/
	for (auto it = dict.begin(); it != dict.end(); ++it)
	{
		string elem = it->first;
		counter = 0;
		tempWord = mainWord;
		for (size_t i = 0; i < elem.length(); ++i)
		{
			pos = tempWord.find(elem[i]);
			if (pos != -1)
			{
				counter++;
				tempWord[pos] = '0';
			}
			else
			{
				counter = 0;
			}
		}
		score += counter;
		dict[elem] += counter;
	}
	ofstream fout("output.txt");
	fout << score << endl;
	for (auto it = dict.begin(); it != dict.end(); ++it)
	{
		if (it->second != 0){
			items.push_back(pair<string, int>(it->first, it->second));
		}
	}
	std::sort(items.begin(), items.end());
	for (auto it = items.begin(); it != items.end(); ++it)
	{
		fout << it->first << endl;
	}
}

int main(int argc, char* argv[])
{
	ifstream fin("input.txt");
	string mainWord, tempWord;
	fin >> mainWord;
	map <string, int> dict;
	while (!fin.eof())
	{
		fin >> tempWord;
		dict.insert(pair<string, int>(tempWord, 0));
	}
	CheckWords(dict, mainWord);
	
	return 0;
}

