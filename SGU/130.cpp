//ac

#include <iostream>
#include <iostream>
using namespace std;

long long mm[31];
long long k, n, p;

void init() {
	mm[0] = 1, mm[1] = 1;
	for (int i = 2; i <= k; ++i) {
		long long ret = 0;
		for (int j = 0; j <= i - 1; ++j) {
			ret += mm[j] * mm[i - 1 - j];
		}
		mm[i] = ret;
	}
}

int main() {
	scanf("%lld", &k);
	init();
	p = k + 1;
	n = mm[k];
	printf("%lld %lld\n", n, p);
	return 0;
}

