/*
 * ZJU 1204 Additive equations
 * 00:02.29 844k
 * 2005.03.20 by adai
 */

#include <iostream>
#include <cstdio>
using namespace std;

//quick sort
int cmp(const void *t1, const void *t2)
{
	int *a, *b; 
	a = (int *)t1;
	b = (int *)t2;
	if ((*a) > (*b)) return 1;
	if ((*a) < (*b)) return -1;
	return 0; 
} 

int kase, n, depth, flag;
int num[30], out[30];

int dfs(int ii, int total, int sum)
{
	if (sum > num[n - 1]) return 0;
	if (total == depth)
	{
		if (sum == 5 && out[0] == 1)
		{
			int adai = 1;
		}
		for (int i = ii; i < n; ++i)
		{
			if (sum == num[i])
			{
				flag = 0;
				printf("%d", out[0]);
				for (int j = 1; j < depth; ++j)
					printf("+%d", out[j]);
				printf("=%d\n", sum);
				break;
			}
		}
		return 0;
	}
	if (ii == n) return 0;
	out[total] = num[ii];
	dfs(ii + 1, total + 1, sum + num[ii]);
	dfs(ii + 1, total, sum);
	return 0;
}

int main()
{
	for (scanf("%d", &kase); kase; --kase)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &num[i]);
		qsort(num, n, sizeof(num[0]), cmp);

		flag = 1;
		for (depth = 2; depth <= n - 1; ++depth)
		{
			dfs(0, 0, 0);
		}

		if (flag)
			printf("Can't find any equations.\n");
		printf("\n");
	}
	return 0;
}
