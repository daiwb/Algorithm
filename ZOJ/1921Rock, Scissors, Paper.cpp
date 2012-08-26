/*
zju 1921 Rock, Scissors, Paper
00:01.49 460k
2004.09.16 by adai
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int mat[102][102];
int mat2[102][102];

char output[3] = {'R', 'S', 'P'};

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int check(int i, int j) {
	int a, b;
	a = mat[i][j];
	for (int t = 0; t < 4; t ++) {
		b = mat[i + dir[t][0]][j + dir[t][1]];
		if (b == (a + 2) % 3) return 1;
	}
	return 0;
}

int main() {
	int kase;
	scanf("%d", &kase);
	for (int kk = 0; kk < kase; kk ++) {
		if (kk) printf("\n");
		int r, c, d;
		scanf("%d %d %d", &r, &c, &d);

		memset(mat, 3, sizeof(mat));

		for (int i = 0; i < r; i ++) {
			char temp[101];
			scanf("%s", temp);
			for (int j = 0; j < c; j ++) {
				if (temp[j] == 'R') mat[i + 1][j + 1] = 0;
				else if (temp[j] == 'S') mat[i + 1][j + 1] = 1;
				else mat[i + 1][j + 1] = 2;
			}
		}
		while (d --) {
			memset(mat2, 3, sizeof(mat2));
			for (int i = 1; i <= r; i ++) {
				for (int j = 1; j <= c; j ++) {
					if (check(i, j)) mat2[i][j] = (mat[i][j] + 2) % 3;
					else mat2[i][j] = mat[i][j];
				}
			}
			memcpy(mat, mat2, sizeof(mat));
		}
		for (int i = 1; i <= r; i ++) {
			for (int j = 1; j <= c; j ++) printf("%c", output[mat[i][j]]);
			printf("\n");
		}
	}
	return 0;
}