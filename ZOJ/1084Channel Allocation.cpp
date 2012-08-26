/*
zju 1084 Channel Allocation
00:00.00 440k
2004.09.11 by adai
*/

#include <iostream>
#include <cstring>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int mat[26][26];
int n, color, found;
int mm[26];

int check(int nn) {
	for (int i = 0; i < nn; i ++) {
		if (mat[i][nn] && mm[i] == mm[nn]) return 0;
	}
	return 1;
}

int dfs(int nn) {
	if (nn == n) {
		found = 1;
		return 0;
	}
	if (found) return 0;
	for (int i = 1; i <= color; i ++) {
		mm[nn] = i;
		if (check(nn)) dfs(nn + 1);
	}
	return 0;
}

int main() {
	while (cin >> n && n) {
		memset(mat, 0, sizeof(mat));
		for (int i = 0; i < n; i ++) {
			char tt[28];
			cin >> tt;
			int ss = tt[0] - 'A';
			for (int j = 2; tt[j] != '\0'; j ++) mat[ss][tt[j] - 'A'] = mat[tt[j] - 'A'][ss] = 1;
		}
		found = 0;
		for (color = 1; color <= 4; color ++) {
			mm[0] = 1;
			dfs(1);
			if (found) break;
		}
		if (color == 1) cout << "1 channel needed." << endl;
		else cout << color << " channels needed." << endl;
	}
	return 0;
}