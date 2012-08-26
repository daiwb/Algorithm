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
#include <string>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;

#define MX 5000
#define MAXN 10000000
#define INF 1000000000

int S;
LL cc[MX + 5][MX + 5];
LL mm[MAXN + 5];

void init() {
    REP(i,MAXN+5) mm[i] = i;
    cc[0][0] = 1;
    FOR(i,1,MX) {
        cc[i][0] = cc[i][i] = 1;
        cc[i][1] = cc[i][i - 1] = i;
        FOR(j,2,i-2) {
            LL val = cc[i][j] = cc[i - 1][j] + cc[i - 1][j - 1];
            if (val > MAXN) cc[i][j] = INF;
            else mm[val] = min(mm[val], i + 0LL);
        }
    }
}

void run() {
    cin >> S;
    int hf = (int) sqrt(S + 0.5);
    LL ret = S + 1;
    int ii = 1, jj = S, tt1 = 1, tt2 = S;
    FOR(i,1,hf) {
        if ((S % i) != 0) continue;
        int j = S / i;
        LL t1 = mm[i], t2 = mm[j];
        if (t1 + t2 < ret) {
            ii = i, jj = j, tt1 = t1, tt2 = t2;
        }
        ret = min(ret, t1 + t2);
    }
    cout << ret << endl;
    //cout << ret << " i = " << ii << ", j = " << jj << ", t1 = " << tt1 << ", t2 = " << tt2 << endl;
}

int main() {
    init();
    int kase;
    cin >> kase;
    FOR(k,1,kase) {
        cout << "Case #" << k << ": ";
        run();
    }
    return 0;
}
