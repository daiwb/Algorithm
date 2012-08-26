/*
zju 1601 Integer Approximation
00:00.00 376k
2004.09.14 by adai
*/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int main() {
	double a;
	int l;
	while (scanf("%lf", &a) != EOF) {
		scanf("%d", &l);
		if (a * l < 1) {
			printf("1 %d\n", l);
			continue;
		}
		if (a > l) {
			printf("%d 1\n", l);
			continue;
		}
		int resa, resb;
		double eps = 100000;
		for (int i = 1; i <= l; i ++) {
			int tt = a * i;
			double temp;
			if (tt <= l) {
				temp = tt * 1.0 / i;
				if (fabs(temp - a) < eps) {
					eps = fabs(temp - a);
					resa = tt;
					resb = i;
				}
			}
			tt ++;
			if (tt <= l) {
				temp = tt * 1.0 / i;
				if (fabs(temp - a) < eps) {
					eps = fabs(temp - a);
					resa = tt;
					resb = i;
				}
			}
		}
		printf("%d %d\n", resa, resb);
	}
	return 0;
}