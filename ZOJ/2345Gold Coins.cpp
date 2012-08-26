/**
 * ZOJ 2345 Gold Coins
 *
 * 2005/05/02 By adai
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

int kase, n;
int a[142];
int day[142];

int Init() {
	a[0] = day[0] = 0;
	for (int i = 1; i <= 141; ++i) {
		a[i] = a[i - 1] + i * i;
		day[i] = day[i - 1] + i;
	}
	return 0;
}

int Run() {
	int ret = 0;
	for (int i = 1; i <= 141; ++i) {
		if (day[i + 1] > n) {
			ret = a[i] + (n - day[i]) * (i + 1);
			printf("%d\n", ret);
			break;
		}
	}
	return 0;
}

int main() {
	Init();
	scanf("%d", &kase);
	for (int kk = 0; kk < kase; ++kk) {
		if (kk) printf("\n");
		while (scanf("%d", &n) && n) {
			printf("%d ", n);
			Run();
		}
	}
	return 0;
}
