//ac

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, m;

void run() {
	vector<vector<int> > mat(n, vector<int>(n, 0));
	int flag = 0;
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		if (mat[a][b] == 1) {
			flag = 1;
		}
		mat[a][b] = -1, mat[b][a] = 1;
	}
	if (flag) {
		printf("No solution\n");
		return;
	}
	//Marshall Algorithm
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (mat[j][i] == 1) {
				for (int k = 0; k < n; ++k) {
					if (mat[i][k] == 1) {
						if (mat[j][k] == -1) {
							printf("No solution\n");
							return;
						}
						mat[j][k] = 1, mat[k][j] = -1;
					}
				}
			}
		}
	}
	vector<int> out(n);
	vector<int> num(n, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (mat[i][j] == 1) {
				++num[i];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (num[j] == 0) {
				out[j] = i;
				num[j] = -1;
				for (int k = 0; k < n; ++k) {
					if (mat[k][j] == 1) {
						mat[k][j] = mat[j][k] = 0;
						--num[k];
					}
				}
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (i) printf(" ");
		printf("%d", out[i] + 1);
	}
	printf("\n");
}

int main() {
	scanf("%d %d", &n, &m);
	run();
	return 0;
}

