#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

#define MAXN 40

int C, N;
double mm[MAXN + 5];
double pro[MAXN + 5][MAXN + 5];
double total;

double getp(int n, int m) {
    double& res = pro[n][m];
    if (res > -1.0) return res;

    if (n < m) return res = 0.0;
    if (n == m) return res = 1.0;

    if (m > n - m) return res = getp(n, n - m);

    res = 1.0;
    FOR(i,1,m) {
        res *= n + 1 - i;
        res /= i;
    }

    return res;
}

double dp(int n) {
    double& res = mm[n];
    if (res > -1.0) return res;

    int mx = min(n + N, C);

    double p = getp(n, N);
    p /= total;

    double t = 0.0;
    FOR(i,n+1,mx) {
        double p1 = getp(n, N - (i - n));
        double p2 = getp(C - n, i - n);
        double p3 = dp(i);
        t += p1 * p2 * p3;
    }
    t /= total;
    t += 1.0;

    res = t / (1 - p);
    return res;
}

void run() {
    cin >> C >> N;

    total = getp(C, N);

    REP(i,MAXN+5) {
        mm[i] = -1.0;
    }
    mm[C] = 0.0;

    double res = dp(0);
    cout << res << endl;
}
int main() {
    REP(i,MAXN+5) {
        REP(j,MAXN+5) {
            pro[i][j] = -1.0;
        }
    }

    int T;
    cin >> T;
    FOR(k,1,T) {
        cout << "Case #" << k << ": ";
        run();
    }

    return 0;
}
