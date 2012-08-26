/*
zju 1910 Blocks
00:00.01
2004.08.31 by adai
*/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int main() {
	int kase;
	scanf("%d", &kase);
	while (kase --) {
		int n;
		scanf("%d", &n);
		int first = 1, minimum;
		int sqrtn = sqrt(n+0.0);
		for (int i = 1; i <= sqrtn; i ++) {
			if (n % i) continue;
			int nn = n / i;
			int sqrtnn = sqrt(nn+0.0);
			for (int j = i; j <= sqrtnn; j ++) {
				if (nn % j) continue;
				int k = nn / j;
				int temp = 2 * (i * j + j * k + k * i);
				if (first) {
					minimum = temp;
					first = 0;
				}
				else {
					if (temp < minimum) minimum = temp;
				}
			}
		}
		printf("%d\n", minimum);
	}
	return 0;
}