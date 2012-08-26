//ac

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

class f {
public:
	double e;
	int idx;
	bool operator < (const f &r) const {
		return e > r.e;
	}
};

int main() {
	int n, m, y;
	scanf("%d %d %d", &n, &m, &y);
	vector<int> x(n), k(n);
	vector<f> mm(n);
	int num = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x[i]);
		k[i] = m * x[i] / y;
		num += k[i];
		mm[i].e = fabs(x[i] * 1.0 / y - k[i] * 1.0 /  m);
		mm[i].idx = i;
	}
	sort(mm.begin(), mm.end());
	num = m - num;
	for (int i  = 0; i < num; ++i) {
		k[mm[i].idx] += 1;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", k[i]);
	}
	return 0;
}

