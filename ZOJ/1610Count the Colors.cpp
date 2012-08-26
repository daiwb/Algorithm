/**
 * ZOJ 1610 Count the Colors
 *
 * 2005/04/08 By adai
 *
 * Algo Desc: Kd-Trees
 */

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#define MAXN 8000

class node {
public:
	int left;
	int right;
	int color;
	int l_child;
	int r_child;
	int isleaf;
}mm[MAXN * 100];

int input[MAXN][3];
int n;
int a, b, num, maxcolor;
int cc[MAXN + 2];
int color, ret;

int insert(int a, int b, int c, int index) {
	int aa = mm[index].left, bb = mm[index].right;
	if (a == aa && b == bb) {
		mm[index].color = c;
		mm[index].isleaf = 1;
		return 0;
	}
	int mid = (mm[index].left + mm[index].right) / 2;
	if (mm[index].isleaf) {
		mm[index].isleaf = 0;
		mm[num].left = mm[index].left, mm[num].right = mid, mm[num].color = mm[index].color, mm[num].isleaf = 1;
		mm[index].l_child = num++;
		mm[num].left = mid, mm[num].right = mm[index].right, mm[num].color = mm[index].color, mm[num].isleaf = 1;
		mm[index].r_child = num++;		
	}
	if (a >= mid) insert(a, b, c, mm[index].r_child);
	else if (b <= mid) insert(a, b, c, mm[index].l_child);
	else {
		insert(a, mid, c, mm[index].l_child);
		insert(mid, b, c, mm[index].r_child);
	}
	return 0;
}

int tongji(int index) {
	if (mm[index].isleaf) {
		if (color != mm[index].color) cc[mm[index].color]++;
		color = mm[index].color;
		return 0;
	}
	tongji(mm[index].l_child);
	tongji(mm[index].r_child);
	return 0;
}

int Run() {
	a = MAXN, b = 0, maxcolor = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) scanf("%d", &input[i][j]);
		if (input[i][0] < a) a = input[i][0];
		if (input[i][1] > b) b = input[i][1];
		if (input[i][2] > maxcolor) maxcolor = input[i][2];
	}
	num = 0;
	mm[num].left = a, mm[num].right = b, mm[num].color = MAXN + 1, mm[num++].isleaf = 1;
	for (int i = 0; i < n; ++i) insert(input[i][0], input[i][1], input[i][2], 0);
	
	memset(cc, 0, sizeof(cc));
	color = MAXN + 1, ret = 0;
	tongji(0);
	for (int i = 0; i <= maxcolor; ++i) {
		if (cc[i]) printf("%d %d\n", i, cc[i]);
	}
	printf("\n");
	return 0;
}

int main() {
	while (scanf("%d", &n) != EOF) {
		Run();
	}
	return 0;
}
