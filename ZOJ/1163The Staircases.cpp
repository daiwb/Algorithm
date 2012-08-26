/*
zju 1163 The Staircases
00:00.01 444k
2004.08.24 by adai
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

#ifndef WIN32
typedef long long i64;
#else
typedef __int64 i64;
#endif

void print(i64 a)
{
    if(a > 9)
        print(a/10);
    cout << (int)(a%10);
}

i64 res[501];

void init() {
	i64 f[2][501];
	for (int i = 1; i <= 500; i ++) f[0][i] = 0;
	f[0][0] = 1;
	int tt = 1;
	for (int i = 1; i <= 500; i ++) {
		for (int j = 1; j < i; j ++) {
			f[tt][j] = f[1 - tt][j];
		}
		f[tt][i] = f[1 - tt][i] + 1;
		for (int j = i + 1; j <= 500; j ++) {
			f[tt][j] = f[1 - tt][j] + f[1 - tt][j - i];	
		}
		res[i] = f[tt][i] - 1;
		tt = 1 - tt;
	}
}

int main () {
	init();
	int n;
	while (cin >> n && n != 0) {
		print(res[n]);
		printf("\n");
	}
	return 0;
}
