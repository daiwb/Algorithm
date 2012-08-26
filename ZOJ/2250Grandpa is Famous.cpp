/**
 * ZOJ 2250 Grandpa is Famous
 *
 * 2005/05/18 By adai
 */

#include <iostream>
#include <cstdio>
using namespace std;

class appearance {
public:
	int num;
	int no;
}mm[10000];

typedef appearance elem_t;
//quick sort
int cmp(const void *t1, const void *t2) {
	elem_t *a, *b; 
	a = (elem_t*)t1;
	b = (elem_t*)t2;
	if ((*a).num < (*b).num) return 1;
	if ((*a).num > (*b).num) return -1;
	return (*a).no - (*b).no;
}

int n, m;

int Run() {
	for (int i = 0; i < 10000; ++i) {
		mm[i].no = i + 1;
		mm[i].num = 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int app;
			scanf("%d", &app);
			mm[app - 1].num += 1;
		}
	}
	qsort(mm, 10000, sizeof(mm[0]), cmp);
	int value = mm[1].num;
	for (int i = 1; i < 10000; ++i) {
		if (mm[i].num < value) break;
		printf("%d ", mm[i].no);
	}
	printf("\n");
	return 0;
}

int main() {
	while (scanf("%d %d", &n, &m) && n + m) {
		Run();
	}
	return 0;
}
