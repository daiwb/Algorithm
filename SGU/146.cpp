//ac

#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main() {
	double l;
	int n;
	int len, t, v, now;
	scanf("%lf %d", &l, &n);
	len = (int)(l * 10000 + 0.5);
	now = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &t, &v);
		int d = ((long long)t * v * 10000) % len;
		now = (now + d) % len;
	}
	if (now > len - now) now = len - now;
	printf("%.4lf\n", now / 10000.0);
	return 0;
}

