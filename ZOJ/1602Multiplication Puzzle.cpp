/**
 * ZOJ 1602 Multiplication Puzzle
 *
 * Algo Desc: DP
 *
 * 2005/04/02 by adai
 */

#include <iostream>
using namespace std;

#define inf 100000000

int n, a[100];
int mm[100][100];

int Run() {
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n - 1; ++i) mm[i][i + 1] = 0;
	for (int len = 2; len < n; ++len) {
		for (int i = 0; i + len < n; ++i) {
			int temp = inf;
			for (int j = i + 1; j < i + len; ++j) {
				int tt;
				if ((tt = mm[i][j] + mm[j][i + len] + a[i] * a[j] * a[i + len]) < temp) temp = tt;
			}
			mm[i][i + len] = temp;
		}
	}
	cout << mm[0][n - 1] << endl;
	return 0;
}

int main() {
	while (cin >> n) {
		Run();
	}
	return 0;
}
