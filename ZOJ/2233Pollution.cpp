/**
 * ZOJ 2233 Pollution
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

#define EPS 1e-4

int num[100];
double mm[100];
double gg[100];
int mat[100][100];

int n, m;

int main() {
	int kase;
	scanf("%d", &kase);
	while (kase --) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i ++) scanf("%lf", &mm[i]);
		memset(mat, 0, sizeof(mat));
		memset(num, 0, sizeof(num));
		for (int i = 0; i < m; i ++) {
			int start, end;
			scanf("%d %d", &start, &end);
			start --, end --;
			mat[start][end] = mat[end][start] = 1;
		}
		for (int i = 0; i < n; i ++) {
			int total = 0;
			for (int j = 0; j < n; j ++) {
				if (mat[i][j]) total ++;
			}
			num[i] = total;
		}
		while (1) {
			memcpy(gg, mm, sizeof(mm));
			memset(mm, 0, sizeof(mm));
			for (int i = 0; i < n; i ++) {
				if (num[i] == 0) {
					mm[i] = gg[i];
					continue;
				}
				double temp = gg[i] * 1.0 / num[i];
				for (int j = 0; j < n; j ++) {
					if (mat[i][j]) mm[j] += temp;
				}
			}
			int again = 0;
			for (int i = 0; i < n; i ++) {
				if (fabs(gg[i] - mm[i]) > EPS) {
					again = 1;
					break;
				}
			}
			if (!again) break;
		}
		for (int i = 0; i < n; i ++) printf("%.3lf\n", mm[i]);
		printf("\n");
	}
	return 0;
}
