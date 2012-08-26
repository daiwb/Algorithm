/**
 * ZOJ 2433 Highways
 *
 * 2005/05/05 By adai
 */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

#define MAXN 50000

int n;
int a[MAXN];

int Run() {
	int mm, index;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) scanf("%d", &a[i]);
	if (n < 4) {
		printf("0\n");
		return 0;
	}
	mm = a[2] - a[1], index = 2;
	for (int i = 3; i < n - 1; ++i) {
		if (a[i] - a[i - 1] < mm) {
			mm = a[i] - a[i - 1];
			index = i;
		}
	}
	printf("%d\n", a[n - 1] + mm);
	printf("%d %d %d %d\n", index + 1, 1, n, index);
	return 0;
}

int main() {
	int kase;
	scanf("%d", &kase);
	for (int kk = 0; kk < kase; ++kk) {
		if (kk) printf("\n");
		Run();
	}
	return 0;
}
