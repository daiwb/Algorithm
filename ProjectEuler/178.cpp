#include <iostream>
using namespace std;

typedef long long LL;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

#define MAXN 40

LL mm[MAXN + 5][10][2][2];

LL dp(int idx, int num, int n0, int n9) {
    LL& ret = mm[idx][num][n0][n9];
    if (ret != -1) return ret;

    if (idx == MAXN) return ret = 0;

    ret = 0;
    if (n0 == 1 && n9 == 1) ++ret;

    if (num >= 1) ret += dp(idx + 1, num - 1, num - 1 == 0 || n0, n9);
    if (num <= 8) ret += dp(idx + 1, num + 1, n0, num + 1 == 9 || n9);

    return ret;
}

int main() {
    memset(mm, -1, sizeof(mm));
    
    LL res = 0;
    FOR(i,1,9) {
        res += dp(0, i, 0, i == 9);
    }

    cout << res << endl;
    
    return 0;
}

