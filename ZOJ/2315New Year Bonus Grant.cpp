/**
 * ZOJ 2315 New Year Bonus Grant
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
	return (*a) - (*b);
}

#define MAXN 500000

int n, index;
bool visited[MAXN];
int father[MAXN], out[MAXN];

int Run() {
	memset(visited, 0, sizeof(visited));
	memset(father, 0, sizeof(father));
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int mm;
		scanf("%d", &mm);
		father[i] = --mm;
	}
	index = 0;
	for (int i = n - 1; i >= 1; --i) {
		int ff = father[i];
		if (visited[i]) continue;
		if (visited[ff] == 0) {
			out[index++] = i;
			visited[ff] = 1;
		}
	}
	qsort(out, index, sizeof(out[0]), cmp);
	printf("%d\n", index * 1000);
	printf("%d", out[0] + 1);
	for (int i = 1; i < index; ++i) printf(" %d", out[i] + 1);
	printf("\n");
	return 0;
}

int main() {
	int kase;
	scanf("%d", &kase);
	for (int kk = 0; kk < kase; ++kk) {
		if (kk) printf("\n");
		Run();
	}
	return 0;
}
