/*
 * ZJU 1565 Input
 * 00:00.01 840k
 */

#include <iostream>
#include <cstdio>
using namespace std;

#define min(a,b) ((a) > (b) ? (b) : (a))
#define max(a,b) ((a) < (b) ? (b) : (a))

int kase, len, wid, num, area, flag;
int x[100][2], y[100][2];

int run()
{
	//test for NONDISJOINT
	for (int i = 0; i < num; ++i)
	{
		for (int j = i + 1; j < num; ++j)
		{
			flag = 1;
			if (x[i][1] - x[i][0] + x[j][1] - x[j][0] <= max(x[i][1], x[j][1]) - min(x[i][0], x[j][0])) {
				flag = 0;
			}
			if (!flag) continue;
			if (y[i][1] - y[i][0] + y[j][1] - y[j][0] <= max(y[i][1], y[j][1]) - min(y[i][0], y[j][0])) {
				flag = 0;
			}
			if (flag) {
				printf("NONDISJOINT\n");
				return 0;
			}
		}
	}

	//test for NONCONTAINED
	for (int i = 0; i < num; ++i)
	{
		if (x[i][0] < 0 || x[i][1] > len || y[i][0] < 0 || y[i][1] > wid) {
			printf("NONCONTAINED\n");
			return 0;
		}
	}

	//test for NONCOVERING
	area = 0;
	for (int i = 0; i < num; ++i) {
		area += (x[i][1] - x[i][0]) * (y[i][1] - y[i][0]);
	}
	if (area != len * wid) {
		printf("NONCOVERING\n");
		return 0;
	}

	//ok
	printf("OK\n");
	return 0;
}

int main()
{
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%d %d %d", &len, &wid, &num);
		for (int i = 0; i < num; ++i) {
			scanf("%d %d %d %d", &x[i][0], &y[i][0], &x[i][1], &y[i][1]);
		}
		run();
	}
	return 0;
}
