/**
 * ZOJ 2402 Lenny's Lucky Lotto Lists
 *
 * 2005/04/30 By adai
 */

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#ifndef WIN32
typedef long long i64;
#else
typedef __int64 i64;
#endif

void print(i64 a)
{
    if(a > 9) print(a / 10);
    printf("%d", a % 10);
}

int n, m, kk;
i64 a[10][2001], lists;

int Run() {
	scanf("%d %d", &n, &m);
	printf("Case %d: n = %d, m = %d, # lists = ", kk, n, m);
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= m; ++i) a[n - 1][i] = 1;
	int tm = m / 2;
	for (int i = n - 2; i >= 0; --i) {
		for (int j = 1; j <= tm; ++j) {
			for (int k = j * 2; k <= m; ++k) a[i][j] += a[i + 1][k];
		}
		tm /= 2;
	}
	lists = 0;
	for (int i = 1; i <= m; ++i) lists += a[0][i];
	print(lists);
	printf("\n");
	return 0;
}

int main() {
	int kase;
	scanf("%d", &kase);
	for (kk = 1; kk <= kase; ++kk) {
		Run();
	}
	return 0;
}
