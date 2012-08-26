/*
zju 2110 Tempter of the Bone
00:00.42 380k
2004.08.09 by adai
*/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#ifdef WIN32
#define for if (0); else for
#endif

int n, m, t;
int sn, sm, dn, dm;
int mat[9][9];
int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
int sign;

int dfs(int tt, int ss, int num) {
	if (sign) return 0;
	if (num == t) {
		if (tt == dn && ss == dm) {
			sign = 1;
		}
		return 0;
	}
	int temp = t - num - abs(tt - dn) - abs(ss - dm);
	if (temp < 0 || temp & 1) return 0;
	for (int i = 0; i < 4; i ++) {
		int cn, cm;
		cn = tt + dir[i][0];
		cm = ss + dir[i][1];
		if (mat[cn][cm] == 1) continue;
		mat[cn][cm] = 1;
		dfs(cn, cm, num + 1);
		mat[cn][cm] = 0;
	}
	return 0;
}

int main() {
	for (int i = 0; i < 9; i ++) {
		for (int j = 0; j < 9; j ++) mat[i][j] = 1;
	}
	while (1) {
		scanf("%d %d %d", &n, &m, &t);
		if (n == 0 && m == 0 && t == 0) break;
		int wall = 0;
		char input[7];
		for (int i = 1; i <= n; i ++) {
			scanf("%s", input);
			for (int j = 0; j < m; j ++) {
				if (input[j] == 'S') {
					sn = i, sm = j + 1;
					mat[i][j + 1] = 1;
				}
				else if (input[j] == 'X') {
					mat[i][j + 1] = 1;
					wall ++;
				}
				else if (input[j] == 'D') {
					mat[i][j + 1] = 0;
					dn = i, dm = j + 1;
				}
				else mat[i][j + 1] = 0;
			}
		}
		if (n * m - wall <= t) {
			printf("NO\n");
			continue;
		}
		int temp = t - abs(sn - dn) - abs(sm - dm);
		if (temp < 0 || temp & 1) {
			printf("NO\n");
			continue;
		}
		sign = 0;
		for (int i = 0; i < 4; i ++) {
			int cn, cm;
			cn = sn + dir[i][0], cm = sm + dir[i][1];
			if (mat[cn][cm] == 1) continue;
			mat[cn][cm] = 1;
			dfs(cn, cm, 1);
			mat[cn][cm] = 0;
		}
		if (sign) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
