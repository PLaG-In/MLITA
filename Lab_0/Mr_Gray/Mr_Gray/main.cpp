#include <iostream>

using namespace std;

int bin2dec(int n)
{
	n = n * 1;
	return n;
}

int gray(int n, int* m, int depth)

{
	int i, t = (1 << (depth - 1));

	if (depth == 0)
		m[0] = 0;

	else
	{
		//массив хранит десятичные записи двоичных слов
		for (i = 0; i < t; i++)
		{
			m[t + i] = m[t - i - 1] + (1 << (depth - 1));
			cout << m[t] << endl;
		}
	}
	if (depth != n)
		gray(n, m, depth + 1);
	return 0;
}

int main()
{
	int codeGray;
	int m[7];
	gray(4, m, 0);
	/*for (int i = 0; i<25; i++)
	{
		codeGray = i ^ (i >> 1);
		cout << "Sequental code - " << i << "\t Gray code - " << codeGray << endl;
	}*/
	system("pause");
	return 0;
}