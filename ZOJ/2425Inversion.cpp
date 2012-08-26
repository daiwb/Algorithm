/**
 * ZOJ 2425 Inversion
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

#ifndef WIN32
typedef long long i64;
#else
typedef __int64 i64;
#endif

void print(i64 a)
{
    if(a > 9) print(a/10);
    printf("%d", (int)(a % 10));
}

//quick sort
int cmp(const void *t1, const void *t2) {
	i64 *a, *b; 
	a = (i64*)t1;
	b = (i64*)t2;
	return (*a) - (*b);
}

int nn, mm;
i64 n, m;
int num = 0;
i64 a[50000];

void Run() {
	num = 0;
	for (int i = 0; i < n; ++i) a[i] = i + 1;
	for (int i = 0; i < n; ++i) {
		if (i) cout << ' ';
		i64 tmp = n - 1 - i;
		tmp = tmp * (tmp - 1) / 2;
		if (tmp >= m) {
			print(a[num++]);
		}
		else {
			print(a[num + m - tmp]);
			a[num + m - tmp] = a[num + n - 1 - i];
			qsort(a + num, n - 1 - i, sizeof(i64), cmp);
			for (int j = n - 2 - i; j >= 0; --j) {
				printf(" ");
				print(a[num + j]);
			}
			printf("\n");
			return;
		}
	}
	printf("\n");
}

int main() {
	while (scanf("%d %d", &nn, &mm)) {
		if (nn == -1 && mm == -1) break;
		n = nn, m = mm;
		Run();
	}
	return 0;
}
