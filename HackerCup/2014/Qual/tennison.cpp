#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

int K;
double ps, pr, pi, pu, pw, pd, pl;
int pii, pui, pdi;
double mm[105][105][1005];

void run() {
    cin >> K;
    cin >> ps >> pr >> pi >> pu >> pw >> pd >> pl;
    pii = pi * 1000, pui = pu * 1000, pdi = pd * 1000;
    memset(mm, 0, sizeof(mm));
    mm[0][0][pii] = 1.0;
    FOR(t,0,(K<<1)-2) {
        FOR(i,0,t) {
            int w = i, l = t - i;
            if (w >= K || l >= K) continue;
            
            FOR(p,0,1000) {
                double tmp = mm[w][l][p] * (p * ps + (1000 - p) * pr) / 1000;
                mm[w + 1][l][min(1000, p + pui)] += tmp * pw;
                mm[w + 1][l][p] += tmp * (1 - pw);
            }

            FOR(p,0,1000) {
                double tmp = mm[w][l][p] * (p * (1 - ps) + (1000 - p) * (1 - pr)) / 1000;
                mm[w][l + 1][max(0, p - pdi)] += tmp * pl;
                mm[w][l + 1][p] += tmp * (1 - pl);
            }
        }
    }

    double ret = 0.0;
    FOR(i,0,K-1) {
        FOR(j,0,1000) {
            ret += mm[K][i][j];
        }
    }

    cout << setprecision(6) << fixed << ret << endl;
}

int main() {
    int T;
    cin >> T;
    FOR(i,1,T) {
        cout << "Case #" << i << ": ";
        run();
    }
    return 0;
}
