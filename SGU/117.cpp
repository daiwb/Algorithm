//ac

#include <iostream>
using namespace std;

int n, m, k, ret;

void f(int a, int m) {
	int ex = 1;
	while (m > 1) {
		if (m % 2) ex = (ex * a) % k;
		a = (a * a) % k;
		if (a == 0) {
			++ret;
			return;
		}
		m /= 2;
	}
	if ((a * ex) % k == 0) ++ret;
}

void run() {
	scanf("%d %d %d", &n, &m, &k);
	ret = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		f(a, m);
	}
	printf("%d\n", ret);
}

int main() {
	run();
	return 0;
}

