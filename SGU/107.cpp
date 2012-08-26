//ac

#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	if (n <= 8) {
		printf("0\n");
	} else if (n == 9) {
		printf("8\n");
	} else if (n == 10) {
		printf("72\n");
	} else {
		printf("72");
		for (int i = 11; i <= n; ++i) {
			printf("0");
		}
		printf("\n");
	}
	return 0;
}

