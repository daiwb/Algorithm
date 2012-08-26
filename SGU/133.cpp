//ac

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

class outpost {
public:
	int x, y;
	int id;
	bool operator < (const outpost &c) const {
		return c.x < x;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	vector<outpost> mm(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &mm[i].x, &mm[i].y);
	}
	sort(mm.begin(), mm.end());
	int maxn = -1;
	vector<int> dd(n);
	for (int i = n - 1; i >= 0; --i) {
		if (mm[i].y > maxn) {
			maxn = mm[i].y;
		}
		dd[i] = maxn;
	}
	int ret = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (dd[i + 1] > mm[i].y) ++ret;
	}
	printf("%d\n", ret);
	return 0;
}

