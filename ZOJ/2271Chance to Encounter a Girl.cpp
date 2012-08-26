/**
 * ZOJ 2271 Chance to Encounter a Girl
 *
 * 2005/05/09 By adai
 */

#include <iostream>
#include <cstdio>
using namespace std;

int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

int n;
double ret;
double a[99][99], bk[99][99];

void Run() {
	ret = 0;
	memset(a, 0, sizeof(a));
	a[n / 2][n / 2] = 1.0;
	for (int tt = 0; tt < n; ++tt) {
		memcpy(bk, a, sizeof(a));
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				double num;
				if ((i == 0 || i == n - 1) && (j == 0 || j == n - 1)) num = 2.0;
				else if (i == 0 || i == n - 1 || j == 0 || j == n - 1) num = 3.0;
				else num = 4.0;
				int tx, ty;
				for (int ii = 0; ii < 4; ++ii) {
					tx = i + dir[ii][0];
					ty = j + dir[ii][1];
					if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
					a[tx][ty] += bk[i][j] / num;
				}
			}
		}
		ret += a[tt][n / 2];
		a[tt][n / 2] = 0;
	}
	printf("%.4lf\n", ret);
}

int main() {
  while (scanf("%d", &n) != EOF) {
    Run();
  }
  return 0;
}
