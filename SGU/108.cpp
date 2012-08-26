//ac

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

class state {
	public:
		int idx;
		int id;
		int value;
}a[5000];

bool cmp1(const state& t1, const state& t2) {
	return t1.idx < t2.idx;
}


bool cmp2(const state& t1, const state& t2) {
	return t1.id < t2.id;
}

int n, k;
int mm[100];
int num;

int d(int n) {
	int ret = 0;
	while (n > 0) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

void init() {
	memset(mm, 0, sizeof(mm));
	num = 0;
	int now = 0, last = 1;
	for (int i = 1; i <= n; ++i) {
		++now;
		if (now == 100) now = 0;
		if (mm[now] == 0) {
			++num;
		}
		mm[now] = 0;
		mm[(now + last) % 100] = 1;
		int tmp = i;
		while (tmp % 10 == 9) {
			last -= 9;
			tmp /= 10;
		}
		++last;
	}
}


void compute() {
	memset(mm, 0, sizeof(mm));
	int now = 0, last = 1;
	num = 0;
	int t = 0;
	for (int i = 1; i <= n; ++i) {
		++now;
		if (now == 100) now = 0;
		if (mm[now] == 0) {
			++num;
			while (num == a[t].idx) {
				a[t].value = i;
				++t;
				if (t == k) {
					return;
				}
			}
		}
		mm[now] = 0;
		mm[(now + last) % 100] = 1;
		int tmp = i;
		while (tmp % 10 == 9) {
			last -= 9;
			tmp /= 10;
		}
		++last;
	}
}

int main() {
	scanf("%d %d", &n, &k);
	init();
	for (int i = 0; i < k; ++i) {
		scanf("%d", &a[i].idx);
		a[i].id = i;
	}
	printf("%d\n", num);
	sort(a, a + k, cmp1);
	compute();
	sort(a, a + k, cmp2);
	for (int i = 0; i < k; ++i) {
		if (i) printf(" ");
		printf("%d", a[i].value);
	}
	printf("\n");
	return 0;
}


