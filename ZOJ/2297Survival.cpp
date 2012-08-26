/*
 * ZJU 2297 Survival
 * 00:00.00 836k
 */

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#ifdef WIN32
#define for if(0);else for
#endif

int sign, n, boss, hp;
int visited[25];

class oppo {
public:
	int c;
	int r;
	int d;
}a[25];

int cmp(const void *t1, const void *t2) {
	oppo *a, *b; 
	a = (oppo *)t1;
	b = (oppo *)t2;
	if ((*a).c > (*b).c) return 1;
	if ((*a).c == (*b).c) return 0;
	return 1; 
}

int dfs(int t, int num) {
	if (sign) return 0;
	if (hp < 0) return 0;
	if (num == n - 1) {
		if (hp >= boss) sign = 1;
		return 0;
	}

	int temp = hp;
	for (int i = 0; i < n - 1; i ++) {
		if (visited[i] == 0) temp += a[i].d;
	}
	if (temp < boss) return 0;

	for (int i = 0; i < n - 1; i ++) {
		if (hp < a[i].c) continue;
		if (visited[i] == 1) continue;
		int oldhp = hp;
		visited[i] = 1;
		hp += a[i].d;
		if (hp > 100) hp = 100;
		dfs(i, num + 1);
		visited[i] = 0;
		hp = oldhp;
	}
	return 0;
}

int main () {
	while (scanf("%d", &n) != EOF){
		if (n == 0) break;
		for (int i = 0; i < n - 1; i ++) {
			scanf("%d %d", &a[i].c, &a[i].r);
			a[i].d = a[i].r - a[i].c;
		}
		scanf("%d", &boss);
		qsort(a, n - 1, sizeof(oppo), cmp);
		memset(visited, 0, sizeof(visited));
		hp = 100;
		sign = 0;
		for (int i = 0; i < n - 1; i ++) {
			visited[i] = 1;
			hp += a[i].d;
			if (hp > 100) hp = 100;
			dfs(i, 1);
			visited[i] = 0;
			hp = 100;
		}
		if (sign) printf("clear!!!\n");
		else printf("try again\n");
	}
	return 0;
}