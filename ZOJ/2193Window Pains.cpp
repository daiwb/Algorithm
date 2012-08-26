/**
 * ZOJ 2193 Window Pains
 *
 * 2005/05/09 By adai
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

char tag[10];
int window[4][4];
int now[4][4];
int x[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
int y[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
int visited[9];
int found;

void search(int num, int a[4][4]) {
	if (found) return;
	if (num == 9) {
		found = 1;
		return;
	}
	int tx, ty;
	int tmp[4][4];
	for (int i = 0; i < 9; ++i) {
		if (visited[i]) continue;
		for (int ii = 0; ii < 4; ++ii) {
			for (int jj = 0; jj < 4; ++jj) tmp[ii][jj] = a[ii][jj];
		}
		int flag = 1;
		for (int ii = 0; ii < 2; ++ii) {
			if (!flag) break;
			for (int jj = 0; jj < 2; ++jj) {
				tx = x[i] + ii, ty = y[i] + jj;
				if (tmp[tx][ty] == 0) {
					if (i + 1 != window[tx][ty]) {
						flag = 0;
						break;
					}
					tmp[tx][ty] = i + 1;
				}
			}
		}
		if (flag) {
			visited[i] = 1;
			search(num + 1, tmp);
			visited[i] = 0;
		}
	}
}

void Run() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) scanf("%d", &window[i][j]);
	}
	found = 0;
	memset(now, 0, sizeof(now));
	memset(visited, 0, sizeof(visited));
	search(0, now);
	if (found) printf("THESE WINDOWS ARE CLEAN\n");
	else printf("THESE WINDOWS ARE BROKEN\n");
}

int main() {
	while (scanf("%s", tag)) {
		if (strcmp(tag, "ENDOFINPUT") == 0) break;
		Run();
		scanf("%s", tag);
	}
	return 0;
}
