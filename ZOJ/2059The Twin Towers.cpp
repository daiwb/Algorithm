/*
zju 2059 The Twin Towers
00:00.34 400k
2004.08.12 by adai
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

#ifdef WIN32
#define for if(0);else for
#endif

int a[100];
int h[2][2000];

int minn(int a, int b) {
	if (a < b) return a;
	return b;
}

int main () {
	int n;
	while (1) {
		scanf("%d", &n);
		if (n < 0) break;

		for (int i = 0; i < n; i ++) {
			scanf("%d", &a[i]);
		}

		memset(h, -1, sizeof(h));
		int p = 0, maxh = 0;
		for (int i = 0; i < n; i ++) {
			memcpy(h[p], h[1 - p], sizeof(h[p]));
			if (h[1 - p][a[i]] == -1) h[p][a[i]] = 0;
			for (int j = 0; j <= maxh; j ++) {
				if (h[1 - p][j] == -1) continue;
				if (h[p][j + a[i]] < h[1 - p][j]) h[p][j + a[i]] = h[1 - p][j];

				int hh = abs(j - a[i]);
				int mm = h[1 - p][j] + minn(a[i], j);
				if (h[p][hh] < mm) h[p][hh] = mm;
			}
			maxh += a[i];
			p = 1 - p;
		}
		if (h[1 - p][0] == -1) printf("Sorry\n");
		else printf("%d\n", h[1 - p][0]);
	}
	return 0;
}
