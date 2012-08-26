//ac

#include <iostream>
#include <cstdio>
using namespace std;

class task {
public:
	int t, l;
	bool operator < (const task& c) const {
		if (l != c.l) return l > c.l;
		else return t > c.t;
	}
}mm[100];

int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &mm[i].t);
	for (int i = 0; i < n; ++i) scanf("%d", &mm[i].l);
	sort(mm, mm + n);
	long long ret = 0, now = 0;
	for (int i = 0; i < n; ++i) {
		now += mm[i].t;
		if (now + mm[i].l > ret) ret = now + mm[i].l;
	}
	printf("%lld\n", ret);
	return 0;
}

