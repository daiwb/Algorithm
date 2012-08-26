#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;

int D, I, M, N;

int mm[105][300];
vector<int> a;

int dp(int idx, int prev) {
    int& ret = mm[idx][prev];
    if (ret != -1) return ret;

    if (idx == N) return ret = 0;

    ret = D + dp(idx + 1, prev);

    REP(now,256) {
        int c = abs(now - a[idx]);

        if (prev != 256) {
            int ab = abs(now - prev);

            if (ab > M) {
                if (M != 0) {
                    ab -= M;
                    int cnt = 0;
                    if ((ab % M) == 0) cnt = ab / M;
                    else cnt = ab / M + 1;
                    c += cnt * I;
                } else {
                    continue;
                }
            }
        }

        c += dp(idx + 1, now);

        ret = min(ret, c);
    }

    return ret;
}

void run() {
    cin >> D >> I >> M >> N;
    a.resize(N);
    REP(i,N) cin >> a[i];

    memset(mm, -1, sizeof(mm));

    int ret = dp(0, 256);

    cout << ret << endl;
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
