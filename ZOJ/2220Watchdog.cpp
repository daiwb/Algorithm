#include <iostream>
#include <cstdio>
#include <vector>
/*
 * zju 2220 Watchdog
 * 00:00.61 460k
 * 2004.11.18 by adai
 */

#include <cmath>
#include <cstring>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

double dis(int a, int b, int x, int y) {
	return sqrt(pow(a - x, 2) + pow(b - y, 2));
}

int mat[41][41];

int main() {
	int kase;
	scanf("%d", &kase);
	while (kase --) {
		int s, h;
		scanf("%d %d", &s, &h);
		vector <int> vx, vy;
		memset(mat, 0, sizeof(mat));
		for (int i = 0; i < h; i ++) {
			int x, y;
			scanf("%d %d", &x, &y);
			mat[x][y] = 1;
			vx.push_back(x);
			vy.push_back(y);
		}
		int quit = 0;
		for (int i = 0; i <= s; i ++) {
			for (int j = 0; j <= s; j ++) {
				if (mat[i][j]) continue;
				double len = 0;
				for (int k = 0; k < h; k ++) {
					double temp = dis(i, j, vx[k], vy[k]);
					if (temp > len) len = temp;
				}
				if (len <= i && len <= s - i && len <= j && len <= s - j) {
					printf("%d %d\n", i, j);
					quit = 1;
				}
				if (quit) break;
			}
			if (quit) break;
		}
		if (!quit) printf("poodle\n");
	}
	return 0;
}
