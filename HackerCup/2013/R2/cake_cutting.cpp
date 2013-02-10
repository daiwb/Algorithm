#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define INF 1000000000
typedef long long LL;

void run() {
    int n;
    cin >> n;
    vector<LL> a(n);
    REP(i,n) cin >> a[i];
    LL n1 = 0, n2 = 0;
    REP(i,n) {
        n1 += a[i] + 1;
        n2 += a[i];
    }
    //cout << n1 << " " << n2 << endl;
    LL res = n1 * (n1 + 1) / 2 + 1;
    res -= n2 * 2;
    cout << res << endl;
}

int main() {
    int m;
    cin >> m;
    FOR(i,1,m) {
        cout << "Case #" << i << ": ";
        run();
    }
    return 0;
}
