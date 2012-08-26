// tle
// seems it only can get accepted using pascal

#include <iostream>
using namespace std;

long long cyc1, cyc2, n, m, a, b;
long long gr[1100000];

long long gray(long long i) {
	long long tm1, tm2, tm3;
	int p[55];
	tm1 = i; tm2 = 0;
	while (tm1 > 0) {
		++tm2;
		p[tm2] = (tm1 & 1 == 1);
		tm1 = tm1 >> 1;
	}
	tm3 = 0;
	while (tm2 > 0) {
		if (p[tm2] ^ p[tm2 + 1])
			tm3 += tm3 + 1;
		else
			tm3 += tm3;
		--tm2;
	}
	return tm3;
}

int main() {
	scanf("%lld %lld", &n, &m);
	long long nm = 1 << max(n, m);
	for (int i = 0; i < nm; ++i)
		gr[i] = gray(i);
	long long n1 = 1 << n;
	long long m1 = 1 << m;
	for (int i = 0; i < n1; ++i) {
		a = gr[i] << m;
		for (int j = 0; j < m1; ++j)
			printf("%lld ", a + gr[j]);
		printf("\n");
	}
	return 0;
}

