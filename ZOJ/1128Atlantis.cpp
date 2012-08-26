/**
 * ZOJ 1128 Atlantis
 *
 * 2005/04/07 By adai
 *
 * Algo Desc: ¿Î…¢ªØ
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

#define eps 1e-8

class hline {
public:
	double left;
	double right;
	double y;
	int type;
}hh[200];

int cmp1(const void *t1, const void *t2) {
	double *a, *b; 
	a = (double*) t1;
	b = (double*) t2;
	if ((*a) - (*b) > eps) return 1;
	if ((*a) - (*b) < eps) return -1;
	return 0;
} 

int cmp2(const void *t1, const void *t2) {
	hline *a, *b; 
	a = (hline*) t1;
	b = (hline*) t2;
	if ((*a).y - (*b).y > eps) return 1;
	if ((*a).y - (*b).y < eps) return -1;
	return 0;
} 

double vv[200];

int n;
int numh, numv;

int Run() {
	numh = numv = 0;
	double left, top, right, bottom;
	for (int i = 0; i < n; ++i) {
		scanf("%lf %lf %lf %lf", &left, &top, &right, &bottom);
		hh[numh].left = left, hh[numh].right = right, hh[numh].y = top, hh[numh++].type = 0;
		hh[numh].left = left, hh[numh].right = right, hh[numh].y = bottom, hh[numh++].type = 1;
		vv[numv++] = left, vv[numv++] = right;
	}
	qsort(vv, numv, sizeof(vv[0]), cmp1);
	qsort(hh, numh, sizeof(hh[0]), cmp2);
	
	double ret = 0;
	int count = 0;
	for (int i = 0; i < numv - 1; ++i) {
		left = vv[i], right = vv[i + 1];
		for (int j = 0; j < numh; ++j) {
			if (hh[j].left <= left && hh[j].right >= right) {
				bottom = hh[j].y;
				if (count > 0) {
					ret += (right - left) * (bottom - top);
				}
				if (hh[j].type) --count;
				else ++count;
				top = bottom;
			}
		}
	}
	printf("Total explored area: %.2lf\n\n", ret);
	return 0;
}

int main() {
	int kase = 1;
	while (scanf("%d", &n) && n) {
		printf("Test case #%d\n", kase++);
		Run();
	}
	return 0;
}
