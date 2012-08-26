#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int n;

int Run() {
	printf("%d", n / 2);
	int a = 0, b = 0, sum = 0;
	for (int i = 1; i <= n; ++i) {
		char A[3];
		scanf("%s", A);
		a = 0;
		for (int j = 0; j < 2; ++j) {
			a *= 16;
			if (A[j] >= 'A') a += A[j] - 'A' + 10;
			else a += A[j] - '0';
		}
		if (a - sum < -8) b = -8;
		else if (a - sum > 7) b = 7;
		else b = a - sum;
		sum += b;
		if (b < 0) b += 16;
		if (i % 2 == 1) {
			if (i % 16 == 1) printf("\n");
			else printf(" ");
		}
		printf("%x", b);
	}
	printf("\n");
	return 0;
}

int main() {
	while (scanf("%d", &n) != EOF) {
		Run();
	}
	return 0;
}
