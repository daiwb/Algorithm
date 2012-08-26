/*
 * ZJU 1883 Tight Words
 * 00:00.01 844k
 * 2005.03.13 by adai
 */

#include <iostream>
#include <string>
using namespace std;

int n, k, flag;
double ret, total;
double mm[2][10];

int main()
{
	
	while (scanf("%d %d", &k, &n) != EOF)
	{
		for (int i = 0; i <= k; ++i) mm[0][i] = 1;
		flag = 0;
		for (int ii = 1; ii < n; ++ii)
		{
			flag = 1 - flag;
			memset(mm[flag], 0, sizeof(mm[flag]));
			for (int i = 0; i <= k; ++i){
				mm[flag][i] = mm[1 - flag][i];
				if (i - 1 >= 0) mm[flag][i] += mm[1 - flag][i - 1];
				if (i + 1 <= k) mm[flag][i] += mm[1 - flag][i + 1];
			}
		}

		ret = 0;
		for (int i = 0; i <= k; ++i) ret += mm[flag][i];

		total = 1;
		for (int i = 0; i < n; ++i) total *= k + 1;

		ret *= 100.00 / total;

		printf("%.5lf\n", ret);
	}
	return 0;
}