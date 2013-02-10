#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define INF 1000000000
typedef long long LL;

LL run() {
    LL n, k, p, q;
    cin >> n >> k >> p;
	if (p == 100) {
		return (n + k - 1) / k;
	}
	if (k * 100 > p * n) return 1;
    q = 100 - p;
    LL x = (n % k);
    while (true) {
		LL m = 0;
		LL px = p * x, pk = p * k;
		if (100 * k < px) m = 0;
		else m = (100 * k - px) / pk;
        LL t = (m * k + x);
        if (t >= n) return 1;
		LL qk = q * k;
        LL s = (p * t + qk - 1) / qk;
        if (s * k + t > n) {
            LL a = (n - t) / k + 1;
            return a;
        }
        x = t + s * k;
    }
	return 1;
}

int main() {
    int m;
    cin >> m;
    FOR(i,1,m) {
        cout << "Case #" << i << ": ";
        cout << run() << endl;
    }
    return 0;
}
