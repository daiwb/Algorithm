/**
 * ZOJ 2424 Game of Connections
 *
 * 2005/05/07 By adai
 */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

#define MAXN 200

int mm[101][MAXN], tmp[MAXN];
int n;

void mul(int a[MAXN], int b[MAXN], int c[MAXN]){
	int i, j;
	for(i = 0; i < MAXN; i ++) a[i] = 0;
	for(i = MAXN - 1; i >= 0; i --){
		for(j = MAXN - 1; j >= 0; j --){
			if(i + j - (MAXN - 1) < 0) break;
			a[i + j - (MAXN - 1)] += b[i] * c[j];
		}
	}
	int temp = 0;
	for(i = MAXN - 1; i >= 0; i --){
		a[i] += temp;
		temp = a[i] / 10;
		a[i] %= 10;
	}
}

void add(int a[MAXN], int b[MAXN]){
	int temp = 0;
	for(int i = MAXN - 1; i >= 0; i --){
		a[i] += temp + b[i];
		temp = a[i] / 10;
		a[i] %= 10;
	}
}


void init() {
	memset(mm, 0, sizeof(mm));
	mm[1][MAXN - 1] = 1, mm[2][MAXN - 1] = 2, mm[3][MAXN - 1] = 5;
	for (int i = 4; i <= 100; ++i) {
		add(mm[i], mm[i - 1]);
		add(mm[i], mm[i - 1]);
		for (int j = 1; j <= i - 2; ++j) {
			mul(tmp, mm[j], mm[i - 1 - j]);
			add(mm[i], tmp);
		}
	}
}

void print(int a[MAXN]) {
	int i = 0;
	while (a[i] == 0) ++i;
	while (i < MAXN) {
		printf("%d", a[i]);
		++i;
	}
}

int main() {
	init();
	while (scanf("%d", &n) && n != -1) {
		print(mm[n]);
		printf("\n");
	}
	return 0;
}
