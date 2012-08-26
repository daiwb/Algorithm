/**
 * ZOJ 1107 FatMouse and Cheese
 
 * 2005.03.27 by adai
 
 * Algo Desc: DP
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

#define MAXN 100

class location {
public:
	int x;
	int y;
	int cheese;
}grid[MAXN * MAXN];

int cmp(const void *t1, const void *t2) {
	location *a, *b; 
	a = (location *)t1;
	b = (location *)t2;
	if ((*a).cheese > (*b).cheese) return 1;
	if ((*a).cheese < (*b).cheese) return -1;
	return 0;
}

int n, k;
int cc, ret[MAXN * MAXN];

int Judge(int jj, int ii) {
	if (grid[ii].cheese == grid[jj].cheese) return 0;
	if (grid[ii].x == grid[jj].x) {
		if (abs(grid[ii].y - grid[jj].y) <= k) return 1;
	}
	if (grid[ii].y == grid[jj].y) {
		if (abs(grid[ii].x - grid[jj].x) <= k) return 1;
	}
	return 0;
}

int Run() {
	cc = 0;
	int flag = 1, start, tmp;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &tmp);
			if (flag) {
				start = tmp;
				flag = 0;
				grid[cc].cheese = tmp;
				grid[cc].x = i, grid[cc++].y = j;
			}
			if (tmp > start) {
				grid[cc].cheese = tmp;
				grid[cc].x = i, grid[cc++].y = j;
			}
		}
	}
	qsort(grid, cc, sizeof(location), cmp);
	/*cout << "cc = " << cc << endl;
	for (int i = 0; i < cc; ++i) {
		cout << grid[i].x << ' ' << grid[i].y << ' ' << grid[i].cheese << endl;
	}*/
	
	for (int i = 0; i < cc; ++i) {
		ret[i] = -1;
	}
	ret[0] = start;

	for (int i = 1; i < cc; ++i) {
		for (int j = 0; j < i; ++j) {
			if (ret[j] == -1) continue;
			if (Judge(j, i)) {
				if (ret[j] + grid[i].cheese > ret[i])
					ret[i] = ret[j] + grid[i].cheese;
			}
		}
	}
	
	int out = 0;
	for (int i = 0; i < cc; ++i) {
		if (ret[i] > out) out = ret[i];
	}
	printf("%d\n", out);
	return 0;
}

int main() {
	while (scanf("%d %d", &n, &k)) {
		if (n == -1 && k == -1) break;
		Run();
	}
	return 0;
}
