/**
 * ZOJ 1354 Extended Lights Out
 *
 * Algo Desc: DFS
 */

#include <iostream>
#include <string>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int mat[5][6], ret[5][6];

int search(int r, int c) {
	int i;
	if (c >= 6) {
		++r;
		c = 0;
	}
	if (r > 1) {
		for (i = 0; i < 6; ++i) {
			if (mat[r - 2][i]) return 0;
		}
	}
	if (r == 5) {
		for (i = 0; i < 6; ++i) {
			if (mat[4][i]) return 0;
		}
		return 1;
	}
	if (search(r, c + 1)) return 1;
	mat[r][c] = 1 - mat[r][c];
	if (r) mat[r - 1][c] = 1 - mat[r - 1][c];
	if (c) mat[r][c - 1] = 1 - mat[r][c - 1];
	if (r < 4) mat[r + 1][c] = 1 - mat[r + 1][c];
	if (c < 5) mat[r][c + 1] = 1 - mat[r][c + 1];
	ret[r][c] = 1;
	if (search(r, c + 1)) return 1;
	mat[r][c] = 1 - mat[r][c];
	if (r) mat[r - 1][c] = 1 - mat[r - 1][c];
	if (c) mat[r][c - 1] = 1 - mat[r][c - 1];
	if (r < 4) mat[r + 1][c] = 1 - mat[r + 1][c];
	if (c < 5) mat[r][c + 1] = 1 - mat[r][c + 1];
	ret[r][c] = 0;
	return 0;
}

int Run() {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 6; ++j) cin >> mat[i][j];
	}
	memset(ret, 0, sizeof(ret));
	search(0, 0);
	for (int i = 0; i < 5; ++i) {
		cout << ret[i][0];
		for (int j = 1; j < 6; ++j) cout << ' ' << ret[i][j];
		cout << endl;
	}
	return 0;
}

int main() {
	int kase;
	cin >> kase;
	for (int kk = 1; kk <= kase; ++kk) {
		cout << "PUZZLE #" << kk << endl;
		Run();
	}
	return 0;
}
