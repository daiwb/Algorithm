/**
 * ZOJ 2358 Sum of Factorials
 *
 * 2005/05/01 By adai
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

int out[409115];

int a[10];
int n;

int search(int index, int num) {
	if (index == 10) return 0;
	for (int i = index; i < 10; ++i) {
		out[num + a[i]] = 1;
		search(i + 1, num + a[i]);
	}
	return 0;
}

int Init() {
	a[0] = 1;
	for (int i = 1; i <= 9; ++i) a[i] = a[i - 1] * i;
	memset(out, 0, sizeof(out));
	for (int i = 0; i < 10; ++i) {
		out[a[i]] = 1;
		search(i + 1, a[i]);
	}
	return 0;
}

int main() {
	Init();
	while (scanf("%d", &n) && n >= 0) {
		if (n > 409114) {
			printf("NO\n");
			continue;
		}
		if (out[n]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
