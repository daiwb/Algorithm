//ac

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int n, t;
int l[20], v[20];
int num[20];

int main() {
	memset(num, 0, sizeof(num));
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; ++i) scanf("%d", &l[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i] * v[j] > 0) continue;
			int dis;
			if (v[i] < 0)
				dis = l[i] - l[j];
			else
				dis = l[j] - l[i];
			if (dis < 0) dis += 1000;
			int total = (abs(v[i]) + abs(v[j])) * t;
			if (total >= dis) {
				num[i]++;
				num[i] += (total - dis) / 1000;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (i) printf(" ");
		printf("%d", num[i]);
	}
	printf("\n");
	return 0;
}

