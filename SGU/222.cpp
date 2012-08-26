//ac

#include <iostream>
using namespace std;

long long c(long long n, long long k) {
	long long ret = 1;
	k = k <?= n - k;
	for (long long i = 1; i <= k; ++i) {
		ret *= (n - k + i);
	}
	for (long long i = 1; i <= k; ++i) {
		ret /= i;
	}
	return ret;
}

long long p(long long n, long long k) {
	long long ret = 1;
	for (int i = n - k + 1; i <= n; ++i) ret *= i;
	return ret;
}

int main() {
	long long n, k;
	cin >> n >> k;
	if (k > n) {
		cout << 0 << endl;
		return 0;
	}
	long long ret = c(n, k) * p(n, k);
	cout << ret << endl;
	return 0;
}

