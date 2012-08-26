/*
 * ZJU 2091 Mean of Subsequence
 * 00:00.28 1624k
 */

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

double a[100000];

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i ++)
			scanf("%lf", &a[i]);

		double max = -1, sum = 0;
		int num = 0;

		for (int i = n - 1; i >= 0; i --) {
			sum += a[i];
			num ++;
			if (sum / num > max) max = sum / num;
		}

		printf("%.6lf\n", max);
	}
	return 0;
}
