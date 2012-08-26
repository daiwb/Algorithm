//ac

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class city {
public:
	double x;
	int p;
	bool operator < (const city& t) const {
		return x < t.x;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	vector<city> mm(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lf %d", &mm[i].x, &mm[i].p);
		sum += mm[i].p;
	}
	sort(mm.begin(), mm.end());
	int tmp = 0;
	for (int i = 0; i < n; ++i) {
		tmp += mm[i].p;
		if (tmp * 2 >= sum) {
			printf("%.5lf\n", mm[i].x);
			return 0;
		}
	}
	return 0;
}

