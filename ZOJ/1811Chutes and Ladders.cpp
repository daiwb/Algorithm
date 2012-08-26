/*
 * ZJU 1811 Chutes and Ladders
 * 00:00.00 840k
 * 2005.03.14 by adai
 */

#include <iostream>
#include <string>
using namespace std;

int num, tmp, turn;
int a[101], b[101];
int step[1000], cc;
int mm[6], delay[2];

int main()
{
	while (scanf("%d", &tmp) && tmp)
	{
		step[cc++] = tmp;
	}
	while (scanf("%d", &num) && num)
	{

		int ii, jj;
		for (int i = 1; i <= 100; ++i) a[i] = i;
		while (scanf("%d %d", &ii, &jj) && ii + jj)
		{
			a[ii] = jj;
		}

		memset(b, 0, sizeof(b));
		while (scanf("%d", &tmp) && tmp)
		{
			if (tmp < 0) b[-tmp] = -1;
			else b[tmp] = 1;
		}

		turn = 0;
		memset(mm, 0, sizeof(mm));
		memset(delay, 0, sizeof(delay));
		for (int i = 0; i < cc; ++i)
		{
			if (delay[turn] == 1)
			{
				delay[turn] = 0;
				turn = (turn + 1) % num;
				--i;
				continue;
			}
			tmp = mm[turn] + step[i];
			tmp = a[tmp];
			if (tmp > 100) continue;
			if (tmp == 100) break;
			mm[turn] = tmp;
			if (b[tmp] > 0){
				for (int j = 0; j < num; ++j)
				{
					if (j == turn) continue;
					delay[j] = 1;
				}
			}
			else if (b[tmp] < 0) delay[turn] = 1;
			turn = (turn + 1) % num;
		}
		printf("%d\n", turn + 1);
	}
	return 0;
}
