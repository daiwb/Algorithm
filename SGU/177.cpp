//ac

#include <iostream>
#include <cstdio>
using namespace std;

#define MAXN 1000000

class node {
	public:
		int left;
		int right;
		int top;
		int bottom;
		int color;
		int isleaf;
		node() {}
}mm[MAXN * 2];

int n, m, ret, num;

int mmin(int a, int b) {
	return a < b ? a : b;
}

int mmax(int a, int b) {
	return a > b ? a : b;
}

void insert(int left, int right, int top, int bottom, int idx, char c) {
	if (left > right || top > bottom) return;
	if (mm[idx].left > mm[idx].right || mm[idx].top > mm[idx].bottom) return;
	if (left == mm[idx].left && right == mm[idx].right && top == mm[idx].top && bottom == mm[idx].bottom) {
		mm[idx].color = c;
		mm[idx].isleaf = 1;
		return;
	}
	int cx = (mm[idx].left + mm[idx].right) / 2, cy = (mm[idx].top + mm[idx].bottom) / 2;
	if (mm[idx].isleaf) {
		mm[idx].isleaf = 0;
		int now = idx * 4 + 1;
		mm[now].left = mm[idx].left, mm[now].right = cx, mm[now].top = mm[idx].top, mm[now].bottom = cy;
		mm[now].color = mm[idx].color, mm[now].isleaf = 1;
		++now;
		mm[now].left = cx + 1, mm[now].right = mm[idx].right, mm[now].top = mm[idx].top, mm[now].bottom = cy;
		mm[now].color = mm[idx].color, mm[now].isleaf = 1;
		++now;
		mm[now].left = mm[idx].left, mm[now].right = cx, mm[now].top = cy + 1, mm[now].bottom = mm[idx].bottom;
		mm[now].color = mm[idx].color, mm[now].isleaf = 1;
		++now;
		mm[now].left = cx + 1, mm[now].right = mm[idx].right, mm[now].top = cy + 1, mm[now].bottom = mm[idx].bottom;
		mm[now].color = mm[idx].color, mm[now].isleaf = 1;
	}
	insert(left, mmin(right, cx), top, mmin(bottom, cy), idx * 4 + 1, c);
	insert(mmax(left, cx + 1), right, top, mmin(bottom, cy), idx * 4 + 2, c);
	insert(left, mmin(right, cx), mmax(top, cy + 1), bottom, idx * 4 + 3, c);
	insert(mmax(left, cx + 1), right, mmax(top, cy + 1), bottom, idx * 4 + 4, c);
}

void tongji(int idx) {
	if (mm[idx].isleaf) {
		if (mm[idx].color == 'w') {
			ret += (mm[idx].right - mm[idx].left + 1) * (mm[idx].bottom - mm[idx].top + 1);
		}
		return;
	}
	tongji(idx * 4 + 1);
	tongji(idx * 4 + 2);
	tongji(idx * 4 + 3);
	tongji(idx * 4 + 4);
}

void run() {
	mm[0].left = 1, mm[0].right = n, mm[0].top = 1, mm[0].bottom = n, mm[0].color = 'w', mm[0].isleaf = 1;
	while (m--) {
		int left, top, right, bottom;
		char c;
		scanf("%d %d %d %d %c", &left, &top, &right, &bottom, &c);
		if (left > right) swap(left, right);
		if (top > bottom) swap(top, bottom);
		insert(left, right, top, bottom, 0, c);
	}
	ret = 0;
	tongji(0);
	printf("%d\n", ret);
}

int main() {
	scanf("%d %d", &n, &m);
	run();
	return 0;
}
