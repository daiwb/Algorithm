/**
 * ZOJ 1015 Fishing Net
 *
 * 2005/05/04 By adai
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

//quick sort
int cmp(const void *t1, const void *t2) {
	int *a, *b; 
	a = (int*)t1;
	b = (int*)t2;
	return (*b) - (*a);
}

#define MAXN 1001

int n, line;
int adj[MAXN][MAXN], adjNum[MAXN];
int label[MAXN], num[MAXN], numI[MAXN];
int m[MAXN];

int maximum_cardinality_search() {
	memset(label, 0, sizeof(label));
	for (int i = n; i >= 1; --i) {
		int v = n + 1, tmp = -1;
		for (int j = n; j >= 1; --j) {
			if (num[j] == 0 && label[j] > tmp) {
				tmp = label[j], v = j;
			}
		}
		num[v] = i;
		numI[i] = v;
		for (int j = 0; j < adjNum[v]; ++j) {
			int w = adj[v][j];
			if (num[w] == 0) ++label[w];
		}
	}
	return 0;
}

int perfect_elimination_order() {
	for (int i = 1; i <= n - 1; ++i) {
		int v = numI[i], w, first = 1;
		for (int j = 0; j < adjNum[v]; ++j) {
			w = adj[v][j];
			if (num[w] > num[v]) {
				if (first) {
					first = 0;
					m[v] = w;
				}
				else {
					if (num[w] < num[m[v]]) m[v] = w;
				}
			}
		}
		for (int j = 0; j < adjNum[v]; ++j) {
			w = adj[v][j];
			if (num[m[v]] < num[w]) {
				int flag = 0;
				for (int k = 0; k < adjNum[m[v]]; ++k) {
					if (w == adj[m[v]][k]) {
						flag = 1;
						break;
					}
				}
				if (flag == 0) return 0;
			}
		}
	}
	return 1;
}

int Run() {
	memset(adjNum, 0, sizeof(adjNum));
	memset(num, 0, sizeof(num));
	while (line--) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a][adjNum[a]++] = b;
		adj[b][adjNum[b]++] = a;
	}
	for (int i = 1; i <= n; ++i) qsort(adj[i], adjNum[i], sizeof(int), cmp);
	maximum_cardinality_search();
	if (perfect_elimination_order()) printf("Perfect\n\n");
	else printf("Imperfect\n\n");
	return 0;
}

int main() {
	while (scanf("%d %d", &n, &line) && n + line) {
		Run();
	}
	return 0;
}
