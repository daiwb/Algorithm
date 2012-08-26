#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	vector<bool> mark(n + 1, true);
	mark[0] = mark[1] = 0;
	for (int i = 2; i <= n; ++i) {
		if (! mark[i]) continue;
		for (int j = i * 2; j <= n; j += i) mark[j] = false;
	}
	int out[8200];
	int num = 0;
	for (int i = 3; i <= n - 2; i += 2) {
		if (mark[i] && mark[i + 2]) out[num++] = i;
	}
	printf("%d\n", num);
	for (int i = 0; i < num; ++i) printf("%d %d\n", 2, out[i]);
	return 0;
}
