#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define INF 1000000000
typedef long long LL;

void run() {
    int n, k, a, b, c, r;
    cin >> n >> k >> a >> b >> c >> r;
    vector<int> mm(k);
    mm[0] = a;
    FOR(i,1,k-1) {
        LL t = b;
        t *= mm[i - 1];
        t += c;
        mm[i] = t % r;
    }
    vector<int> t(k + 1), v(k + 5, 0);
    REP(i,k) {
        if (mm[i] < k) v[mm[i]]++;
    }
    int pt = 0;
    int last = INF;
    REP(i,k) {
        while (v[pt] >= 1) ++pt;
        int idx = -1;
        if (last < pt && v[last] == 0) idx = last;
        else {
            idx = pt;
            ++pt;
        }
        t[i] = idx;
        v[idx]++;
        if (mm[i] < k) {
            v[mm[i]]--;
        }
        last = mm[i];
    }
    while (v[pt] >= 1) ++pt;
    t[k] = min(last, pt);
    n %= (k + 1);
    cout << t[n] << endl;
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
