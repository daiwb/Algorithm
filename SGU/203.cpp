//ac

#include <iostream>
#include <cstdio>
#include <queue>
#include <deque>
#include <vector>
using namespace std;

#define for if(0); else for
const int MAXN = 500000;

long long mm[2][MAXN];

int main() {
	int n;
	int num[2] = {0, 0};
	int idx[2] = {0, 0};
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		mm[0][num[0]++] = a;
	}
	num[0] = n;
	long long ret = 0;
	for (int ii = 0; ii < n - 1; ++ii) {
		long long p = 0;
		for (int i = 0; i < 2; ++i) {
			if (idx[0] == num[0]) {
				ret += mm[1][idx[1]];
				p += mm[1][idx[1]++];
			} else if (idx[1] == num[1]) {
				ret += mm[0][idx[0]];
				p += mm[0][idx[0]++];
			} else if (mm[1][idx[1]] < mm[0][idx[0]]) {
				ret += mm[1][idx[1]];
				p += mm[1][idx[1]++];
			} else {
				ret += mm[0][idx[0]];
				p += mm[0][idx[0]++];
			}
		}
		mm[1][num[1]++] = p;
	}
	printf("%lld\n", ret);
	return 0;
}
