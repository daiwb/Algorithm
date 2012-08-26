/*
 * ZJU 2191 Series Determination
 * 00:00.00 836k
 * 2005.03.14 by adai
 */

#include <iostream>
using namespace std;

int a, b, c;
int f[3];

int main()
{
	while (1)
	{
		cin >> f[0] >> f[1] >> f[2];
		if (cin.fail()) break;

		c = f[0];
		a = (f[2] - 2 * f[1] + c) / 2;
		b = f[1] - c - a;

		for (int i = 3; i <= 5; ++i)
		{
			if (i > 3) cout << ' ';
			cout << a * i * i + b * i + c;
		}
		cout << endl;
	}
	return 0;
}
