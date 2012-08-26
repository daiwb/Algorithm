//ac

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int n;
int A[3][3], B[3][3], BB[3][3];
int dir[2][2] = {{-1, 0}, {0, -1}};
int flag;

void dfs(int now) {
	//cout << now << endl;
	if (flag) return;
	if (now == n * n) {
		int mark = 1;
		for (int i = 0; i < n; ++i) {
			if (BB[n - 1][i] != B[n - 1][i]) {
				mark = 0;
				break;
			}
		}
		if (mark) {
			flag = 1;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (j) printf(" ");
					printf("%d", A[i][j]);
				}
				printf("\n");
			}
		}
		return;
	}
	int r = now / n, c = now % n;
	for (int num = 0; num <= 9; ++num) {
		A[r][c] = num;
		for (int i = 0; i < 2; ++i) {
			int tx = r + dir[i][0], ty = c + dir[i][1];
			if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
			if (A[r][c] > A[tx][ty]) {
				BB[tx][ty] += 1;
			} else if (A[r][c] < A[tx][ty]) {
				BB[r][c] += 1;
			}
		}
		int cx = r - 1;
		if (cx >= 0) {
			if (BB[cx][c] != B[cx][c]) {
				for (int i = 0; i < 2; ++i) {
					int tx = r + dir[i][0], ty = c + dir[i][1];
					if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
					if (A[r][c] > A[tx][ty]) {
						BB[tx][ty] -= 1;
					} else if (A[r][c] < A[tx][ty]) {
						BB[r][c] -= 1;
					}
				}
				continue;
			}
		}
		dfs(now + 1);
		for (int i = 0; i < 2; ++i) {
			int tx = r + dir[i][0], ty = c + dir[i][1];
			if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
			if (A[r][c] > A[tx][ty]) {
				BB[tx][ty] -= 1;
			} else if (A[r][c] < A[tx][ty]) {
				BB[r][c] -= 1;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	memset(BB, 0, sizeof(BB));
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d", &B[i][j]);
	flag = 0;
	dfs(0);
	if (flag == 0) printf("NO SOLUTION\n");
	return 0;
}

