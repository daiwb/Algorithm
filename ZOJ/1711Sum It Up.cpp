/*
 * zju 1711 Sum It Up
 * 00:00.01 380k
 * 2004.10.14 by adai
 */

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int total, n, a[12], visited[12], num, none;

int dfs(int ii, int left) {
	if (left == 0) {
		none = 0;
		int first = 1;
		for (int i = 0; i < n; i ++) {
			if (visited[i]) {
				if (first) first = 0;
				else printf("+");
				printf("%d", a[i]);
			}
		}
		printf("\n");
		return 0;
	}
		
	int last = -1;
	for (int i = ii + 1; i < n; i ++) {
		if (a[i] == last) continue;
		last = a[i];
		if (a[i] <= left) {
			visited[i] = 1;
			dfs(i, left - a[i]);
			visited[i] = 0;
		}
	}
	return 0;
}

int main() {
	while (1) {
		scanf("%d %d", &total, &n);
		if (!n) break;
		for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
		printf("Sums of %d:\n", total);
		memset(visited, 0, sizeof(visited));

		none = 1;

		int last = -1;
		for (int i = 0; i < n; i ++) {
			if (a[i] == last) continue;
			last = a[i];
			if (a[i] <= total) {
				visited[i] = 1;
				dfs(i, total - a[i]);
				visited[i] = 0;
			}
		}
		if (none) printf("NONE\n");
	}
	return 0;
}
