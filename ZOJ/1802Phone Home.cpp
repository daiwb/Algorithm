/**
 * ZOJ 1802 Phone Home
 *
 * 2005/04/15 By adai
 *
 * Algo Desc: DFS
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

#define MAXN 12

int n, kase = 0, ret, quit;
double x[MAXN], y[MAXN];
int mat[MAXN][MAXN];
int fre[MAXN];

int dfs(int index) {
	if (quit) return 0;
	if (index == n) {
		quit = 1;
		return 0;
	}
	for (int i = 0; i < ret; ++i) {
		int flag = 1;
		for (int j = index - 1; j >= 0; --j) {
			if (mat[index][j] && fre[j] == i) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			fre[index] = i;
			dfs(index + 1);
		}
	}
	return 0;
}

int Run() {
	for (int i = 0; i < n; ++i)
		scanf("%lf %lf", &x[i], &y[i]);
	memset(mat, 0, sizeof(mat));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= 400) mat[i][j] = 1;
	quit = 0;
	for (ret = 1; ret <= n; ++ret) {
		fre[0] = 0;
		dfs(1);
		if (quit) break;
	}
	printf("The towers in case %d can be covered in %d frequencies.\n", ++kase, ret);
	return 0;
}

int main() {
	while (scanf("%d", &n) && n) {
		Run();
	}
	return 0;
}
