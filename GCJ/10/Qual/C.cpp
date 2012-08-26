#include <iostream>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;

void run() {
    int r, k, n;
    cin >> r >> k >> n;
    vector<LL> mm(n);
    REP(i,n) {
        cin >> mm[i];
    }
    vector<LL> money(n, 0);
    vector<int> next(n);
    REP(i,n) {
        REP(j,n) {
            if (money[i] + mm[(i + j) % n] > k) break;
            money[i] += mm[(i + j) % n];
            next[i] = (i + j + 1) % n;
        }
    }

    LL total = 0;
    int idx = 0;
    vector<LL> dd;
    vector<int> vv(n, -1);
    REP(i,r) {
        if (vv[idx] != -1) {
            int cnt = i - vv[idx];
            LL s = 0;
            REP(j,cnt) s += dd[vv[idx] + j];
            LL left = r - i;
            LL c = left / cnt;
            total += c * s;
            REP(j,left - cnt * c) {
                total += dd[vv[idx] + j];
            }

            cout << total << endl;
            return;
        }

        vv[idx] = i;
        dd.push_back(money[idx]);
        total += money[idx];
        idx = next[idx];
    }

    cout << total << endl;
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
