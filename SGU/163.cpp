//ac

#include <iostream>
#include <cstdio>
using namespace std;

int p(int n, int k) {
	int ret = 1;
	for (int i = 0; i < k; ++i) ret *= n;
	return ret;
}

int main() {
	int n, k;
	int a[105];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int sum = 0;
	if (k % 2 == 1) {
		for (int i = 0; i < n; ++i) {
			if (a[i] > 0) sum += p(a[i], k);
		}
	} else {
		for (int i = 0; i < n; ++i) {
			if (a[i] != 0) sum += p(a[i], k);
		}
	}
	printf("%d\n", sum);
	return 0;
}

