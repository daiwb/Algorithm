//ac

#include <iostream>
using namespace std;

int a[1001][1001];
int b[1001][1001];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	b[n][m] = a[n][m];
	for (int i = n - 1; i >= 1; --i) {
		b[i][m] = min(a[i][m], b[i + 1][m]);
	}
	for (int i = m - 1; i >= 1; --i) {
		b[n][i] = min(a[n][i], b[n - 1][i + 1]);
		for (int j = n - 1; j >= 2; --j) {
			b[j][i] = min(b[j + 1][i], min(a[j][i], b[j - 1][i + 1]));
		}
		b[1][i] = min(b[2][i], min(a[1][i], b[1][i + 1]));
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}

