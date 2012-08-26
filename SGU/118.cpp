//ac

#include <iostream>
#include <vector>
using namespace std;

int f(int n) {
	if (n == 0) return 0;
	if (n % 9 == 0) return 9;
	return n % 9;
}

void run() {
	int n;
	scanf("%d", &n);
	vector<int> mm(n);
	for (int i = 0; i < n; ++i) scanf("%d", &mm[i]);
	int ret = 0, tmp = 1;
	for (int i = 0; i < n; ++i) {
		tmp = f(f(tmp) * f(mm[i]));
		ret += tmp;
	}
	ret = f(ret);
	printf("%d\n", ret);
}

int main() {
	int kase;
	for (scanf("%d", &kase); kase; --kase) {
		run();
	}
	return 0;
}

