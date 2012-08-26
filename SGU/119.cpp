//ac

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	int a0 = 0, b0 = 0;
	int num = 0;
	long long mm[10000];
	while (1) {
		mm[num++] = (long long)(a0) * 10001 + b0;
		a0 = (a0 + a) % n;
		b0 = (b0 + b) % n;
		if (a0 + b0 == 0) break;
	}
	sort(mm, mm + num);
	printf("%d\n", num);
	for (int i = 0; i < n; ++i) {
		printf("%lld %lld\n", mm[i] / 10001, mm[i] % 10001);
	}
	return 0;
}

