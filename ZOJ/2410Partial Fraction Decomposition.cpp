/**
 * ZOJ 2410 Partial Fraction Decomposition
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

typedef int elem_t;
//quick sort
int cmp(const void *t1, const void *t2) {
	elem_t *a, *b; 
	a = (elem_t*)t1;
	b = (elem_t*)t2;
	return (*a) - (*b);
}

int a[3], b[3], r[3];
double A[3];
int c, d;

int judge(int value)
{
	int tmp = 1;
	for (int i = 2; i >= 0; --i) {
		tmp = tmp * value + b[i];
	}
	if (tmp == 0) return 1;
	return 0;
}

int Run()
{
	int tmp, end;
	if (b[0] == 0) {
		r[0] = 0;
		r[1] = int((-b[2] + sqrt(double(b[2] * b[2] - 4 * b[1]))) / 2.0);
		r[2] = int((-b[2] - sqrt(double(b[2] * b[2] - 4 * b[1]))) / 2.0);
		goto label;
	}
	
	tmp = b[0] > 0 ? b[0] : -b[0];
	end = int(pow(tmp, 1 / 3.0));
	for (int i = 1; i <= end; ++i) {
		if (tmp % i != 0) continue;
		if (judge(i)) {
			r[0] = i;
			break;
		}
		if (judge(-i)) {
			r[0] = -i;
			break;
		}
	}
	c = b[2] + r[0];
	d = -b[0] / r[0];
	r[1] = int((-c + sqrt(double(c * c - 4 * d))) / 2.0);
	r[2] = int((-c - sqrt(double(c * c - 4 * d))) / 2.0);
	
label:
	qsort(r, 3, sizeof(r[0]), cmp);
	
	for (int i = 0; i < 3; ++i) {
		A[i] = a[2] * r[i] * r[i] + a[1] * r[i] + a[0];
		for (int j = 0; j < 3; ++j) {
			if (i != j) A[i] /= r[i] - r[j];
		}
	}
	
	printf("%d", r[0]);
	for (int i = 1; i < 3; ++i) printf(" %d", r[i]);
	for (int i = 0; i < 3; ++i) printf(" %.2lf", A[i]);
	printf("\n");
	return 0;
}

int main() {
	while (scanf("%d %d %d %d %d %d", &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]) && ! (a[0] == 0 && a[1] == 0 && a[2] == 0))
	{
		Run();
	}
	return 0;
}
