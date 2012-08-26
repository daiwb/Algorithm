/*
zju 2095 Divisor Summation
00:02.82 444k
2004.09.07 by adai
*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int main () {
	int kase;
	scanf("%d", &kase);
	while (kase --) {
		int n, res = 1, num, sum, sq, mm;
		cin >> n;
		mm = n;
		if (n % 2 == 0) {
			num = 0;
			while (n % 2 == 0) {
				n /= 2, num ++;
			}
			sum = 0;
			for (int j = 0; j <= num; j ++) sum += pow(2, j);
			res *= sum;
		}
		if (n % 3 == 0) {
			num = 0;
			while (n % 3 == 0) {
				n /= 3, num ++;
			}
			sum = 0;
			for (int j = 0; j <= num; j ++) sum += pow(3, j);
			res *= sum;
		}
		sq = sqrt(n);
		for (int i = 5; i <= sq;) {
			if (n % i == 0) {
				num = 0;
				while (n % i == 0) {
					n /= i, num ++;
				}
				sum = 0;
				for (int j = 0; j <= num; j ++) sum += pow(i, j);
				res *= sum;
				sq = sqrt(n);
			}
			i += 2;
			if (n % i == 0) {
				num = 0;
				while (n % i == 0) {
					n /= i, num ++;
				}
				sum = 0;
				for (int j = 0; j <= num; j ++) sum += pow(i, j);
				res *= sum;
				sq = sqrt(n);
			}
			i += 4;
		}
		if (n != 1) res *= (1 + n);
		res -= mm;
		printf("%d\n", res);
	}
	return 0;
}
