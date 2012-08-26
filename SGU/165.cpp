#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class player {
public:
	int hei;
	int pos;
	player(int h, int p) : hei(h), pos(p) {}
	bool operator < (const player &r) const {
		return hei < r.hei;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	vector<player> mm;
	for (int i = 0; i < n; ++i) {
		double a;
		scanf("%lf", &a);
		mm.push_back(player((int)(a * 1000000 - 2000000), i + 1));
	}
	sort(mm.begin(), mm.end());
	int left = 0, right = n - 1, sum = 0;
	printf("yes\n");
	while (left <= right) {
		if (sum <= 0) {
			sum += mm[right].hei;
			printf("%d ", mm[right--].pos);
		} else {
			sum += mm[left].hei;
			printf("%d ", mm[left++].pos);
		}
	}
	printf("\n");
	return 0;
}

