#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

deque<int> ta, tb, tk;
LL a, b, k, n;
LL mm[35][2][2][2];

/*LL dp(int idx, int fa, int fb, int fk) {
    LL& res = mm[idx][fa][fb][fk];
    if (res != -1) return res;

    if (idx == n) return res = 1;

    if (fa + fb + fk == 0) {
        res = 1LL;
        REP(i,n-idx) res *= 4LL;
        return res;
    }

    int ma = ta[idx], mb = tb[idx], mk = tk[idx];
    if (fa == 0) ma = 1;
    if (fb == 0) mb = 1;

    res = 0;
    FOR(i,0,ma) {
        FOR(j,0,mb) {
            int t = (i & j);
            if ((fk == 1) && (t > mk)) continue;
            int na = fa, nb = fb, nk = fk;
            if (i < ma) na = 0;
            if (j < mb) nb = 0;
            if (t < mk) nk = 0;
            res += dp(idx + 1, na, nb, nk);
        }
    }

    return res;
}*/

void run() {
    LL A, B, K;
    cin >> A >> B >> K;

    if (A < K || B < K) {
        LL res = A * B;
        cout << res << endl;
        return;
    }
    
    a = A - 1, b = B - 1, k = K - 1;
    ta.clear(), tb.clear(), tk.clear();
    while (true) {
        ta.push_front(a & 1);
        tb.push_front(b & 1);
        tk.push_front(k & 1);
        if (a + b + k == 0) break;
        a >>= 1, b >>= 1, k >>= 1;
    }
    n = ta.size();
    memset(mm, -1, sizeof(mm));

    RFOR(idx,n,0) {
        REP(fa,2) {
            REP(fb,2) {
                REP(fk,2) {
                    LL& res = mm[idx][fa][fb][fk];

                    if (idx == n) {
                        res = 1;
                        continue;
                    }

                    if (fa + fb + fk == 0) {
                        res = 1LL;
                        REP(i,n-idx) res *= 4LL;
                        continue;
                    }

                    int ma = ta[idx], mb = tb[idx], mk = tk[idx];
                    if (fa == 0) ma = 1;
                    if (fb == 0) mb = 1;

                    res = 0;
                    FOR(i,0,ma) {
                        FOR(j,0,mb) {
                            int t = (i & j);
                            if ((fk == 1) && (t > mk)) continue;
                            int na = fa, nb = fb, nk = fk;
                            if (i < ma) na = 0;
                            if (j < mb) nb = 0;
                            if (t < mk) nk = 0;
                            res += mm[idx + 1][na][nb][nk];
                        }
                    }
                }
            }
        }
    }

    cout << mm[0][1][1][1] << endl;

    /*LL res = dp(0, 1, 1, 1);
    cout << res << endl;*/
}

int main() {
    int nk;
    cin >> nk;
    FOR(c,1,nk) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
