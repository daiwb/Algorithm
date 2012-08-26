/**
 * ZOJ 1117 Entropy
 * 05/03/29 by adai
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

class node {
public:
	int num;
	int total;
}mm[27];

//quick sort
int cmp(const void *t1, const void *t2) {
	node *a, *b; 
	a = (node *)t1;
	b = (node *)t2;
	return (*a).num - (*b).num;
} 

char in[10000];
int flag[27], all;
int a[2];
double ratio;

int Run() {
	a[0] = strlen(in) * 8;
	memset(flag, 0, sizeof(flag));
	for (int i = 0; i < 27; ++i) {
		mm[i].num = mm[i].total = 0;
	}
	all = 0;
	for (int i = 0; in[i] != '\0'; ++i) {
		if (in[i] >= 'A' && in[i] <= 'Z') {
			if (flag[in[i] - 'A'] == 0) {
				++all;
				flag[in[i] - 'A'] = 1;
			}
			mm[in[i] - 'A'].num++;
		}
		else {
			if (flag[26] == 0) {
				++all;
				flag[26] = 1;
			}
			mm[26].num++;
		}
	}
	int maxn = 0;
	for (int i = 0; i < 27; ++i) {
		if (mm[i].num > maxn) maxn = mm[i].num;	
	}
	for (int i = 0; i < 27; ++i) {
		if (mm[i].num == 0) mm[i].num = maxn + 1;
	}
	qsort(mm, 27, sizeof(node), cmp);
	if (all == 1) {
		printf("%d %d 8.0\n", a[0], a[0] / 8);
		return 0;
	}
	while (all > 1) {
		node tmp;
		tmp.num = mm[0].num + mm[1].num;
		tmp.total = mm[0].total + mm[1].total + tmp.num;
		int ii;
		for (ii = 2; ii < all; ++ii) {
			if (mm[ii].num < tmp.num) {
				mm[ii - 2].num = mm[ii].num;
				mm[ii - 2].total = mm[ii].total;
			}
			else break;
		}
		mm[ii - 2].num = tmp.num;
		mm[ii - 2].total = tmp.total;
		for (; ii < all; ++ii) {
			mm[ii - 1].num = mm[ii].num;
			mm[ii - 1].total = mm[ii].total;
		}
		--all;
	}
	a[1] = mm[0].total;
	ratio = a[0] * 1.0 / a[1];
	printf("%d %d %.1lf\n", a[0], a[1], ratio);
	return 0;
}

int main() {
	while (gets(in)) {
		if (strcmp(in, "END") == 0) break;
		Run();
	}
	return 0;
}
