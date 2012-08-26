//ac

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <deque>
using namespace std;

int main() {
	int n;
	char str[500005];
	scanf("%d %s", &n, str);
	int len = (int)(log((double)n) / log(2.0) + 1);
	int size = (1 << (len + 1)) - 1;
	vector<bool> mm(size, false);
	for (int d = 1; d <= len; ++d) {
		for (int i = 0; i < n + 1 - d; ++i) {
			int now = 0;
			for (int j = 0; j < d; ++j) {
				if (str[i + j] == 'a') now = now * 2 + 1;
				else now = now * 2 + 2;
			}
			mm[now] = true;
		}
	}
	for (int i = 1; ; ++i) {
		if (!mm[i]) {
			int ret = 0;
			deque<char> out;
			while (i) {
				if (i % 2) out.push_back('a');
				else out.push_back('b');
				i = (i - 1) / 2;
				++ret;
			}
			printf("%d\n", ret);
			for (int j = out.size() - 1; j >= 0; --j) printf("%c", out[j]);
			printf("\n");
			return 0;
		}
	}
	return 0;
}

