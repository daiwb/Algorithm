/*
zju 1027 Human Gene Functions
00:00.00 488k
2004.08.16 by adai
*/

#include <iostream>
#include <string>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int table[5][5] = {
	{5, -1, -2, -1, -3},
	{-1, 5, -3, -2, -4},
	{-2, -3, 5, -2, -2},
	{-1, -2, -2, 5, -1},
	{-3, -4, -2, -1, 5}
};

int change(char c) {
	if (c == 'A') return 0;
	if (c == 'C') return 1;
	if (c == 'G') return 2;
	if (c == 'T') return 3;
	return 4;
}

int lena, lenb;
char a[101], b[101];
int x[100], y[100];
int num[101][101];
bool sign[101][101];

int dp(int s, int t) {
	if (sign[s][t]) return num[s][t];
	int max;
	if (s == lena) {
		max = 0;
		for (int i = t; i < lenb; i ++) max += table[4][y[i]];
		num[s][t] = max;
		sign[s][t] = 1;
		return max;
	}
	if (t == lenb) {
		max = 0;
		for (int i = s; i < lena; i ++) max += table[x[i]][4];
		num[s][t] = max;
		sign[s][t] = 1;
		return max;
	}
	max = table[x[s]][y[t]] + dp(s + 1, t + 1);
	if (table[x[s]][4] + dp(s + 1, t) > max) max = table[x[s]][4] + dp(s + 1, t);
	if (table[4][y[t]] + dp(s, t + 1) > max) max = table[4][y[t]] + dp(s, t + 1);
	num[s][t] = max;
	sign[s][t] = 1;
	return max;
}

int main () {
	int kase;
	cin >> kase;
	while (kase --) {
		cin >> lena >> a;
		cin >> lenb >> b;
		for (int i = 0; i < lena; i ++) x[i] = change(a[i]);
		for (int i = 0; i < lenb; i ++) y[i] = change(b[i]);
		
		memset(sign, 0, sizeof(sign));
		int res = dp(0, 0);
		cout << res << endl;
	}
	return 0;
}
