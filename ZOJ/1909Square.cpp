/*
zju 1909 Square
00:00.11 380k
2004.09.14 by adai
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

//quick sort
int cmp(const void *t1, const void *t2) {
	int *a, *b; 
	a = (int *)t1;
	b = (int *)t2;
	return (*b) - (*a);
}

int mm[20];
int tt[4];
int visited[20];
int last[4];
int m, len, sign, idx;

int search(int idx) {
	if (sign) return 0;
	if (tt[idx] == 0) idx ++;
	if (idx == 3) {
		sign = 1;
		return 0;
	}
	if (tt[idx] == 0) {
		for (int i = 1; i < m; i ++) {
			if (visited[i] == 0) {
				last[idx] = mm[i];
				visited[i] = 1;
				tt[idx] -= mm[i];
				search(idx);
				last[idx] = 100000;
				visited[i] = 0;
				tt[idx] += mm[i];
				return 0;
			}
		}
	}
	int pre = 0;
	int quit = 0;
	for (int i = 1; i < m; i ++) {
		if (mm[i] > last[idx]) continue;
		if (visited[i]) continue;
		if (tt[idx] - mm[i] < 0) continue;
		if (mm[i] == pre) continue;
		if (tt[idx] == mm[i]) quit = 1;
		pre = mm[i];
		visited[i] = 1;
		tt[idx] -= mm[i];
		int backup = last[idx];
		last[idx] = mm[i];
		search(idx);
		last[idx] = backup;
		visited[i] = 0;
		tt[idx] += mm[i];
		if (quit) break;
	}
	return 0;
}

int main() {
	int kase;
	scanf("%d", &kase);
	while (kase --) {
		scanf("%d", &m);
		len = 0;
		for (int i = 0; i < m; i ++) {
			scanf("%d", &mm[i]);
			len += mm[i];
		}
		if (len % 4) {
			printf("no\n");
			continue;
		}
		len /= 4;

		qsort(mm, m, sizeof(mm[0]), cmp);

		if (mm[0] > len) {
			printf("no\n");
			continue;
		}
		for (int i = 0; i < 4; i ++) {
			tt[i] = len;
			last[i] = 100000;
		}
		memset(visited, 0, sizeof(visited));

		tt[0] -= mm[0];
		visited[0] = 1;
		last[0] = mm[0];
		idx = 0;
		sign = 0;
		search(idx);
		if (sign) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}