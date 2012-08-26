/*
 * zju 2258 Number Sequence II
 * 00:00.01 376k
 */

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int n, a, b;

int main()
{
	while (scanf("%d %d %d", &n, &a, &b) != EOF)
	{
		if (a > n || a < 1 || b > n || b < 1 || n <= 1)
		{
			
			printf("-1\n");
			continue;
		}
		if (n == 2 && a == 1 && b == 2)
		{
			printf("0\n");
			continue;
		}
		if (a == 1 && b == n)
		{
			printf("2 0 %d 0 1\n",n-1);
			continue;
		}
		if (b == n)
		{
			if (a>=n)
			{
                printf("-1\n");
                continue;
			}
			else if (a == n - 1)
			{
				printf("1 0 %d\n",n-1);
				continue;
			}
			else
			{
				printf("2 0 %d 0 %d\n",n-a,a);
				continue;
			}
		}
		
		if (a == 1)
		{
			if (b >= n)
			{
                printf("-1\n");
                continue;
			}
			else if (b == n - 1)
			{
				printf("1 1 %d\n",n-1);
				continue;
			}
			else
			{
				printf("2 1 %d 1 %d\n",n-b,b);
				continue;
			}
		}
		
		if (a + b > n)
		{
			printf("-1\n");
			continue;
		}
		else if (a + b == n)
		{
			printf("2 0 %d 1 %d\n",a,b);
			continue;
		}
		else
		{
			printf("3 0 %d 1 %d 1 %d\n",a,n-a-b+1,b);
			continue;
		}
	}
	return 0;
}
