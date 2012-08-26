//ac

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	vector<int> a(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	vector<int> up(n + 1, 0);
	vector<int> lo(n + 1, 0);
	for (int i = n - 1; i >= 0; --i) {
		int res = (int)((double)a[i] * 100 / sum);
		if (a[i] * 100 % sum == 0) {
			up[i] = up[i + 1] + res;
			lo[i] = lo[i + 1] + res;
		} else {
			up[i] = up[i + 1] + res + 1;
			lo[i] = lo[i + 1] + res;
		}
	}
	if (up[0] < 100 || lo[0] > 100) {
		printf("No solution");
		return 0;
	}
	int now = 0;
	vector<int> answer(n);
	for (int i = 0; i < n; ++i) {
		answer[i] = a[i] * 100 / sum;
		if (a[i] * 100 % sum != 0) {
			if (now + answer[i] + up[i + 1] < 100) {
				answer[i] += 1;
			}
		}
		now += answer[i];
	}
	for (int i = 0; i < n; ++i) {
		if (i) printf(" ");
		printf("%d", answer[i]);
	}
	printf("\n");
	return 0;
}


