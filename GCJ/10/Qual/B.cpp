#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;

LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

void run() {
    int n;
    cin >> n;
    vector<LL> mm(n);
    REP(i,n) cin >> mm[i];
    sort(mm.begin(), mm.end());

    LL g = mm[1] - mm[0];
    FOR(i,2,n-1) {
        g = gcd(g, mm[i] - mm[i - 1]);
    }

    LL y = mm[0] % g;
    if (y != 0) y = g - y;
    cout << y << endl;
}

int main() {
    int kase;
    cin >> kase;
    FOR(k,1,kase) {
        cout << "Case #" << k << ": ";
        run();
    }
    return 0;
}
