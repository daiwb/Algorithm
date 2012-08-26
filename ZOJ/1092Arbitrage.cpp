/*
zju 1092 Arbitrage
00:00.07 444k
2004.08.17 by adai
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

#define eps	1e-10

char name[30][100];
int n;
double cur[30][30];

int find(char a[100]) {
	for (int i = 0; i < n; i ++) {
		if (strcmp(name[i], a) == 0) return i;
	}
	return n;
}

int main () {
	int kase = 1;
	while (cin >> n && n != 0) {
		for (int i = 0; i < n; i ++) cin >> name[i];
		memset(cur, 0, sizeof(cur));
		int m;
		cin >> m;
		while (m --) {
			char a[100], b[100];
			double c;
			cin >> a >> c >> b;
			int s = find(a);
			int t = find(b);
			cur[s][t] = c;
		}
		for (int k = 0; k < n; k ++) {
			for (int i = 0; i < n; i ++) {
				for (int j = 0; j < n; j ++) {
					//if (cur[i][k] == -1 || cur[k][j] == -1) continue;
					double temp = cur[i][k] * cur[k][j];
					if (temp > cur[i][j]) cur[i][j] = temp;
				}
			}
		}
		int sign = 0;
		for (int i = 0; i < n; i ++) {
			if (cur[i][i] > 1 + eps) {
				sign = 1;
				break;
			}
		}
		cout << "Case " << kase ++ << ": ";
		if (sign) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}