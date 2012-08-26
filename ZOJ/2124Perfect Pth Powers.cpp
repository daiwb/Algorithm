/*
zju 2124 Perfect Pth Powers
00:00.03 380k
2004.08.05 by adai
*/

#include <iostream>
#include <cstdio>
using namespace std;

int adai(double x) {
	int sign = 0;
	if (x < 0) {
		sign = 1;
		x *= -1;
	}
	double b, res;
	int p;
	for (b = 2; (res = b * b) <= x; b ++) {
		for (p = 2; res < x ; p ++) res *= b;
		if (res == x) {
			if (sign == 0 || p % 2) {
				printf("%d\n", p);
				return 0;
			}
		}
	}
	printf("1\n");
	return 0;
}

int main() {
	double x;
	while (1) {
		scanf("%lf", &x);
		if (x == 0) break;
		adai(x);
		/*
		int sign = 0;
		if (x < 0) {
			sign = 1;
			x *= -1;
		}
		double b, res;
		int p;
		for (b = 2; (res = b * b) <= x; b ++) {
			for (p = 2; res < x ; p ++) res *= b;
			if (res == x) {
				if (sign == 0 || p % 2) {
					printf("%d\n", p);
					goto exit;
				}
			}
		}
		printf("1\n");
exit:	;
		*/
	}
	return 0;
}
