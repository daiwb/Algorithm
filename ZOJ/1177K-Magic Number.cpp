/**
 * ZOJ 1177 K-Magic Number
 *
 * 2005/03/28 by adai
 */

#include <iostream>
#include <string>
using namespace std;

#define MAXN 100000

int k, a[MAXN], b[MAXN];

int Run() {
	int len = MAXN;
	for (int num = 1; num < 10; ++num) {
		int now = 0, head = 0, tmp;
		memset(a, 0, sizeof(a));
		a[0] = num;
		while (1) {
			a[now + 1] += a[now] * k;
			tmp = now + 1;
			while (a[tmp] >= 10) {
				a[tmp + 1] += a[tmp] / 10;
				a[tmp] %= 10;
				++tmp;
			}
			if (tmp > head) head = tmp;
			++now;
			if (now == head && a[now] == a[0]) break;
		}
		if (head < len) {
			for (int i = 0; i <= head; ++i) b[i] = a[i];
			len = head;
		}
	}
	for (int i = len; i >= 1; --i) cout << b[i];
	cout << endl;
	return 0;
}

int main() {
	int kase;
	cin >> kase;
	for (int kk = 0; kk < kase; ++kk) {
		cin >> k;
		if (kk) cout << endl;
		Run();
	}
	return 0;
}
