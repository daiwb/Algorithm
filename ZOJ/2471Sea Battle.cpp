/**
 * ZOJ 2471 Sea Battle
 *
 * 2005/05/19 By adai
 */

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int r, c, ret;
char mat[1000][1001];

int Run() {
	ret = 0;
	for (int i = 0; i < r; ++i) {
		scanf("%s", mat[i]);
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (mat[i][j] == '.') continue;
			mat[i][j] = '.';
			++ret;
			int left, right, top, bottom;
			left = right = j;
			while (right + 1 < c && mat[i][right + 1] == '#') {
				mat[i][++right] = '.';
			}
			top = bottom = i;
			while (bottom + 1 < r && mat[bottom + 1][j] == '#') {
				mat[++bottom][j] = '.';
			}
			if (left - 1 > 0) {
				for (int ii = top; ii <= bottom; ++ii) {
					if (mat[ii][left - 1] == '#') {
						printf("Bad placement.\n");
						return 0;
					}
				}
			}
			if (right + 1 < c) {
				for (int ii = top; ii <= bottom; ++ii) {
					if (mat[ii][right + 1] == '#') {
						printf("Bad placement.\n");
						return 0;
					}
				}
			}
			if (top - 1 > 0) {
				for (int ii = left; ii <= right; ++ii) {
					if (mat[top - 1][ii] == '#') {
						printf("Bad placement.\n");
						return 0;
					}
				}
			}
			if (bottom + 1 < r) {
				for (int ii = left; ii <= right; ++ii) {
					if (mat[bottom + 1][ii] == '#') {
						printf("Bad placement.\n");
						return 0;
					}
				}
			}
			if (top - 1 > 0 && left - 1 > 0 && mat[top - 1][left - 1] == '#') {
				printf("Bad placement.\n");
				return 0;
			}
			if (right + 1 < c && bottom + 1 < r && mat[bottom + 1][right + 1] == '#') {
				printf("Bad placement.\n");
				return 0;
			}
			if (bottom + 1 < r && left - 1 > 0 && mat[bottom + 1][left - 1] == '#') {
				printf("Bad placement.\n");
				return 0;
			}
			if (top - 1 > 0 && right + 1 < c && mat[top - 1][right + 1] == '#') {
				printf("Bad placement.\n");
				return 0;
			}
			for (int ii = top + 1; ii <= bottom; ++ii) {
				for (int jj = left + 1; jj <= right; ++jj) {
					if (mat[ii][jj] == '.') {
						printf("Bad placement.\n");
						return 0;
					}
					mat[ii][jj] = '.';
				}
			}
		}
	}
	printf("There are %d ships.\n", ret);
	return 0;
}

int main() {
	while (scanf("%d %d", &r, &c)) {
		if (r == 0 && c == 0) break;
		Run();
	}
	return 0;
}
