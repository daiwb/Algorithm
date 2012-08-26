//ac

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int mm[10005];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	memset(mm, 0, sizeof(mm));
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		mm[a]++, mm[b]++;
	}
	long long ret = 0;
	for (int i = 1; i <= n; ++i) {
		ret += mm[i] * mm[i];
	}
	printf("%lld\n", ret);
	return 0;
}
