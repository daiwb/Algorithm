//ac

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int a[10000], n, m;
int mm[1000];
int bk[1000];
int res[1000];
int out[1000];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	memset(mm, 0, sizeof(mm));
	mm[1] = 1;
	int ret = 1;
	for (int i = 0; i < n; ++i) {
		memcpy(bk, mm, sizeof(mm));
		for (int j = 1; j <= ret; ++j) {
			if (bk[j]) {
				int now = (a[i] * j) % m;
				if (mm[now] == 0) {
					if (now > ret) {
						ret = now;
					}
					mm[now] = j;
					res[now] = i;
				}
			}
		}
	}
	printf("%d\n", ret);
	if (ret == 1) return 0;
	int num = 0;
	while (ret != 1) {
		out[num++] = res[ret];
		ret = mm[ret];
	}
	for (int i = 0; i < num; ++i) {
		if (i) printf(" ");
		printf("%d", out[num - 1 - i] + 1);
	}
	printf("\n");
	return 0;
}
