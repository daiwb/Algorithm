/*
 * ZJU 1738 Lagrange's Four-Square Theorem
 * 00:00.34 968k
 * 2005.03.16 by adai
 */

#include <iostream>
#include <string>
using namespace std;

int n, tmp;
int ret[33000];

int main()
{
	memset(ret, 0, sizeof(ret));
	for (int i = 1; i <= 181; ++i)
	{
		tmp = i * i;
		++ret[tmp];
		for (int j = i; j <= 181; ++j)
		{
			tmp = i * i + j * j;
			if (tmp < 32768) ++ret[tmp];
			else break;
			for (int k = j; k <= 181; ++k)
			{
				tmp = i * i + j * j + k * k;
				if (tmp < 32768) ++ret[tmp];
				else break;
				for (int l = k; l <= 181; ++l)
				{
					tmp = i * i + j * j + k * k + l * l;
					if (tmp < 32768) ++ret[tmp];
					else break;
				}
			}
		}
	}
	while (cin >> n && n)
	{
		cout << ret[n] << endl;
	}
	return 0;
}