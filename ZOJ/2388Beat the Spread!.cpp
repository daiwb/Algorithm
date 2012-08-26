/**
 * ZOJ 2388 Beat the Spread!
 */

#include <iostream>
#include <cstdio>
using namespace std;

int Run() {
	int sum, abso;
	scanf("%d %d", &sum, &abso);
	if (sum < abso) {
		printf("impossible\n");
		return 0;
	}
	if ((sum + abso) % 2) {
		printf("impossible\n");
		return 0;
	}
	printf("%d %d\n", (sum + abso) / 2, (sum - abso) / 2);
	return 0;
}

int main() {
	int kase;
	scanf("%d", &kase);
	for (int kk = 0; kk < kase; ++kk)
		Run();
	return 0;
}
