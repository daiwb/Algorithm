/**
 * ZOJ 2408 Rate of Return
 *
 * 2005/05/07 By adai
 */

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

#define eps 1e-6

int n, kase = 0;
int a[12], end;
double money[12], result;

void Run() {
	for (int i = 0; i < n; ++i) {
		scanf("%d %lf", &a[i], &money[i]);
	}
	scanf("%d %lf", &end, &result);
	for (int i = 0; i < n; ++i) a[i] = end + 1 - a[i];
	double left = 0, right = 1, mid;
	int first = 1;
	double last, ff;
	while (1) {
		mid = (left + right) / 2;
		ff = 0;
		for (int i = 0; i < n; ++i) {
			double tmp = money[i];
			for (int j = 0; j < a[i]; ++j) tmp *= 1 + mid;
			ff += tmp;
		}
		if (ff > result) right = mid;
		else left = mid;
		if (first) {
			first = 0, last = mid;
		}
		else {
			if (fabs(mid - last) < eps) break;
		}
		last = mid;
	}
	if (kase++) printf("\n");
	printf("Case %d: %.5lf\n", kase, mid);
}

int main() {
	while (scanf("%d", &n) && n != -1) {
		Run();
	}
	return 0;
}
