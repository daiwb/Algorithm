/*
zju 1222 Just the Facts
00:00.04 548k
2004.08.19 by adai
*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

#define MAXN 200

int table[10] = {1, 1, 2, 6, 4, 4, 4, 8, 4, 6};
int tt[10] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};

char number[MAXN];
int num[MAXN];

int f(int number[MAXN]) {
	int num[MAXN];
	for (int i = 0; i < MAXN; i ++) num[i] = number[i];
	int tail = num[MAXN - 1];
	int ii;
	for (ii = 0; ii < MAXN; ii ++) {
		if (num[ii] != 0) break;
	}
	if (ii >= MAXN - 1) return tt[tail];

	int add = 0;
	for (int i = MAXN - 1; i >= 0; i --) {
		int temp = 2 * num[i] + add;
		add = temp / 10;
		num[i] = temp % 10;
	}
	for (int i = MAXN - 1; i >= 1; i --) {
		num[i] = num[i - 1];
	}

	int a = f(num);
	a *= table[tail] * 6;
	a %= 10;

	int four = 10 * num[MAXN - 2] + num[MAXN - 1];
	four %= 4;
	for (int i = 0; i < four; i ++) {
		switch(a) {
		case 2: a = 6; break;
		case 4: a = 2; break;
		case 6: a = 8; break;
		case 8: a = 4; break;
		default: break;
		}
	}
	return a;
}

int main () {
	while (cin >> number) {
		int len = strlen(number);
		memset(num, 0, sizeof(num));
		for (int i = MAXN - len; i < MAXN; i ++) {
			num[i] = number[i - MAXN + len] - '0';
		}
		int res = f(num);
		cout << res << endl;
	}
	return 0;
}
