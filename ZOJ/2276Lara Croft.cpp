/*
 * ZJU 2276 Lara Croft
 * 00:00.02 1200k
 * by adai
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

int n;
int a[100];
int p1, p2;
int tt[100][100];
int alist[100000], blist[100000];
int head, tail;

int bfs() {
	int step = 0;
	int nhead, ntail;
	while (1) {
		nhead = tail + 1;
		ntail = tail;
		step ++;
		for (int i = head; i <= tail; i ++) {
			int ta, tb;
			int temp = a[blist[i]] % n;
			ta = alist[i], tb = (blist[i] + temp) % n;
			if (tt[ta][tb] == 0) {
				tt[ta][tb] = tt[tb][ta] = 1;
				ntail ++;
				alist[ntail] = ta, blist[ntail] = tb;
			}
			tb = (blist[i] - temp + n) % n;
			if (tt[ta][tb] == 0) {
				tt[ta][tb] = tt[tb][ta] = 1;
				ntail ++;
				alist[ntail] = ta, blist[ntail] = tb;
			}
			temp = a[alist[i]] % n;
			ta = (alist[i] + temp) % n, tb = blist[i];
			if (tt[ta][tb] == 0) {
				tt[ta][tb] = tt[tb][ta] = 1;
				ntail ++;
				alist[ntail] = ta, blist[ntail] = tb;
			}
			ta = (alist[i] - temp + n) % n;
			if (tt[ta][tb] == 0) {
				tt[ta][tb] = tt[tb][ta] = 1;
				ntail ++;
				alist[ntail] = ta, blist[ntail] = tb;
			}
		}
		for (int i = 0; i < n; i ++) {
			if (tt[i][i] == 1) return step;
		}
		if (ntail < nhead) break;
		for (int i = nhead; i <= ntail; i ++) {
			alist[i - nhead] = alist[i];
			blist[i - nhead] = blist[i];
		}
		head = 0, tail = ntail - nhead;
	}
	return -1;
}

int main () {
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
		scanf("%d %d", &p1, &p2);
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) tt[i][j] = 0;
		}
		tt[p1][p2] = tt[p2][p1] = 1;
		head = tail = 0;
		alist[head] = p1;
		blist[head] = p2;
		if (p1 == p2) {
			printf("open it on the %dth move!\n", 0);
			continue;
		}
		int res = bfs();
		if (res == -1) printf("Lara is traped!\n");
		else printf("open it on the %dth move!\n", res);
	}
	return 0;
}
