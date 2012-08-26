/*
 * ZJU 1457 Prime Ring Problem
 * 00:02.04 844k
 * 2005.03.16 by adai
 */

#include <iostream>
#include <string>
using namespace std;

int isPrime(int a)
{
	int i = a - 1;
	while (1)
	{
		if (a % i == 0) return 0;
		--i;
		if (i == 1) break;
	}
	return 1;
}
int mm[38];

int num, kase = 1;
int out[20];
int visited[21];

int dfs(int cc, int nn)
{
	if (cc + 1 == num)
	{
		if (mm[nn + 1] == 1)
		{
			cout << out[0];
			for (int i = 1; i < num; ++i) cout << ' ' << out[i];
			cout << endl;
		}
		return 0;
	}

	for (int i = 2; i <= num; ++i)
	{
		if (visited[i]) continue;
		if (!mm[nn + i]) continue;
		visited[i] = 1;
		out[cc + 1] = i;
		dfs(cc + 1, i);
		visited[i] = 0;
	}

	return 0;
}

int main()
{
	memset(mm, 0, sizeof(mm));
	for (int i = 3; i <= 37; i += 2)
	{
		if (isPrime(i)) mm[i] = 1;
	}
	while (cin >> num)
	{
		cout << "Case " << kase++ << ":" << endl;
		if (num % 2 != 1)
		{
			memset(visited, 0, sizeof(visited));
			out[0] = 1;
			visited[1] = 1;
			dfs(0, 1);
		}
		cout << endl;
	}
	return 0;
}
