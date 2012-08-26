/**
 * ZOJ 2316 Matrix Multiplication
 *
 * 2005/04/11 By adai
 */

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#define MAXN 10000

int n, m;
int num[MAXN];

int Run() {
	scanf("%d %d", &n, &m);
	
	memset(num, 0, sizeof(num));
	while (m--) {
		int ii, jj;
		scanf("%d %d", &ii, &jj);
		--ii, --jj;
		++num[ii], ++num[jj];
	}
	
	int ret = 0;
	for (int i = 0; i < n; ++i) ret += num[i] * num[i];
	printf("%d\n", ret);
	return 0;
}

int main() {
	int kk;
	scanf("%d", &kk);
	for (int kase = 0; kase < kk; ++kase) {
		if (kase) printf("\n");
		Run();
	}
	return 0;
}
