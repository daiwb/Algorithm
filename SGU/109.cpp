//ac

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	if (n == 2) {
		printf("2 2\n3 1 4\n");
		return 0;
	}
	printf("%d", n);
	for (int i = 2; i < n; ++i) {
		for (int j = n + 1 - i; j < n; ++j) {
			printf(" %d", i * n + j + 1);
		}
	}
	printf("\n");
	int num;
	if (n % 2 == 0) num = n - 1;
	else num = n;
	num += 2;
	printf("%d", num);
	for (int i = 1; i < n; ++i) {
		int j = n - i;
		printf(" %d", i * n + j + 1);
	}
	printf("\n");
	for (int t = n - 1; t >= 1; --t) {
		num += 2;
		printf("%d", num);
		for (int i = t; i >= 0; --i) {
			int j = t - i;
			printf(" %d", i * n + j + 1);
		}
		printf("\n");
	}
	return 0;
}

