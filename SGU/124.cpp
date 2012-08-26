//ac

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct node {
	int s, t, val;
	bool operator<(const node p) const {
		return val < p.val;
	}
};
vector<node> hor, ver;
int n;
int x, y;

bool border() {
	for (unsigned int i = 0; i < ver.size(); ++i) if (x == ver[i].val && y >= ver[i].s && y <= ver[i].t)
		return true;
	for (unsigned int i = 0; i < hor.size(); ++i) if (y == hor[i].val && x >= hor[i].s && x <= hor[i].t)
		return true;
	return false;
}

bool inside() {
	int cnt = 0;
	for (unsigned int i = 0; i < ver.size(); ++i) if (x > ver[i].val) {
		if (y >= ver[i].s && y < ver[i].t)
			cnt++;
		else if (y == ver[i].s)
			cnt++;
	}
	return cnt & 1;
}

int main() {
	int a, b, c, d;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		node u;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (a == c && b != d) {
			if (b > d) swap(b, d);
			u.val = a; u.s = b; u.t = d;
			ver.push_back(u);
		} else if (b == d && a != c) {
			if (a > c) swap(a, c);
			u.val = b; u.s = a; u.t = c;
			hor.push_back(u);
		}
	}
	scanf("%d%d", &x, &y);
	if (border())
		printf("BORDER\n");
	else {
		if (inside())
			printf("INSIDE\n");
		else
			printf("OUTSIDE\n");
	}
	return 0;
}

