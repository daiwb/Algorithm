/*
 * ZJU 2164 Hanafuda Shuffle
 * 00:00.05 844k
 * 2005.03.19 by adai
 */

#include <iostream>
#include <string>
using namespace std;

int n, r;
int p, c;
int num[2][50];
int flag;

int main()
{
	while (cin >> n >> r && n + r)
	{
		for (int i = 0; i < n; ++i)
			num[0][i] = n - i;
		flag = 0;

		while (r--)
		{
			flag = 1 - flag;
			cin >> p >> c;
			
			for (int i = 0; i < p - 1; ++i) num[flag][i + c] = num[1 - flag][i];
			for (int i = p - 1; i < p + c - 1; ++i) num[flag][i - p + 1] = num[1 - flag][i];
			for (int i = p + c - 1; i < n; ++i) num[flag][i] = num[1 - flag][i];
		}

		cout << num[flag][0] << endl;
	}
	return 0;
}
