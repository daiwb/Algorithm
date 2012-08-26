/**
 * ZOJ 1862 Mine Sweeper
 *
 * 2005/04/15 By adai
 */

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#define MAXN 10

int n, kase = 0, touched;
char mine[MAXN][MAXN + 1];
char touch[MAXN][MAXN + 1];
int num[MAXN][MAXN];
int dir[8][2] = {1, 0, -1, 0, 0, 1, 0, -1, -1, -1, -1, 1, 1, -1, 1, 1};

int Run() {
	for (int i = 0; i < n; ++i) scanf("%s", mine[i]);
	memset(num, 0, sizeof(num));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (mine[i][j] == '*') {
				for (int dd = 0; dd < 8; ++dd) {
					int tx = i + dir[dd][0], ty = j + dir[dd][1];
					if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
					if (mine[tx][ty] == '.') ++num[tx][ty];
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) scanf("%s", touch[i]);
	touched = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (mine[i][j] == '*' && touch[i][j] == 'x') {
				touched = 1;
				break;
			}
		}
		if (touched) break;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (mine[i][j] == '*' && touched) printf("*");
			else if (touch[i][j] == 'x') printf("%d", num[i][j]);
			else printf(".");
		}
		printf("\n");
	}
	return 0;
}

int main() {
	while (scanf("%d", &n) != EOF) {
		if (kase++) printf("\n");
		Run();
	}
	return 0;
}
