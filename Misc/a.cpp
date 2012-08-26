#include <iostream>
#include <cstdio>
using namespace std;

int n;

void Run() {
	if (n == 1) {
		printf("Impossible\n\n");
		return;
	}
	printf("0");
	for (int i = 1; i < n; ++i) {
		printf(" %d", 1);
	}
	printf("\n");
	printf("1");
	for (int i = 1; i < n; ++i) {
		printf(" %d", 10);
	}
	printf("\n");
	for (int i = 2; i < n; ++i) {
		printf("80");
		for (int j = 1; j < n; ++j) {
			printf(" 80");
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
	while (scanf("%d", &n) != EOF) {
		Run();
	}
	return 0;
}

