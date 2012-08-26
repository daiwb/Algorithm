/*
zju 1800 Decorations
00:02.47 1796k
2004.09.03 by adai
*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int n, l, m, res, len;
char bead[600][11];
int mat[600][600];

int match(int a, int b) {
	for (int i = 1; i < len; i ++) {
		if (bead[a][i] != bead[b][i - 1]) return 0;
	}
	return 1;
}

int a[2][600];

int main () {
	while (1) {
		scanf("%d %d %d", &n, &l, &m);
		if (!n && !l && !m) break;
		for (int i = 0; i < m; i ++) scanf("%s", bead[i]);
		len = strlen(bead[0]);
		if (len > l) {
			printf("0\n");
			continue;
		}

		for (int i = 0; i < m; i ++) {
			for (int j = 0; j < m; j ++) {
				if (match(i, j)) mat[i][j] = 1;
				else mat[i][j] = 0;
			}
		}

		int index = 0;
		for (int i = 0; i < m; i ++) a[index][i] = 1;
		int count = len;
		while (1) {
			if (count == l) break;
			count ++;
			index = 1 - index;
			for (int i = 0; i < m; i ++) a[index][i] = 0;
			for (int i = 0; i < m; i ++) {
				for (int j = 0; j < m; j ++) {
					if (mat[j][i]) a[index][j] += a[1 - index][i];
				}
			}
		}

		res = 0;
		for (int i = 0; i < m; i ++) res += a[index][i];
		printf("%d\n", res);
	}
	return 0;
}
