/* 
 * zju 2229 Ride to School
 * 00:00.01 456k
 * 2004.10.16 by adai
 */

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int a[10000];
int t[10000];

int main() {
	int n;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		int res = 1000000;
		for (int i = 0; i < n; i ++) {
			scanf("%d %d", &a[i], &t[i]);
		}
		for (int i = 0; i < n; i ++) {
			if (t[i] < 0) continue;//t[i] *= -1;
			double temp = 4.5 / a[i] * 3600 + t[i];
			//int tt = (int)(temp + 0.999999999999);
			int tt = (int)ceil(temp);
			if (tt < res) res = tt;
		}
		printf("%d\n", res);
	}
	return 0;
}
