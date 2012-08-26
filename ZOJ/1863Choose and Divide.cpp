/**
 * ZOJ 1863 Choose and Divide
 *
 * 2005/05/03 By adai
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

int p, q, r, s;
double ret;

int Run() {
	int small;
	if (q > p - q) q = p - q;
	if (s > r - s) s = r - s;
	if (s < q) small = s;
	else small = q;
	ret = 1;
	for (int i = 1; i <= small; ++i) {
		ret *= 1.0 * (p - q + i) / (r - s + i);
	}
	if (s == small) {
		for (int i = small + 1; i <= q; ++i) ret *= 1.0 * (p - q + i) / i;
	}
	else {
		for (int i = small + 1; i <= s; ++i) ret *= 1.0 * i / (r - s + i);
	}
	printf("%.5lf\n", ret);
	return 0;
}

int main() {
	while (scanf("%d %d %d %d", &p, &q, &r, &s) != EOF) {
		Run();
	}
	return 0;
}
