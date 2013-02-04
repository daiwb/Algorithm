#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define INF 1000000000
#define MOD 1000000007
typedef long long LL;

int a[10005];
LL mm[10005][10005];

void init() {
    FOR(i,0,10000) mm[i][0] = mm[i][i] = 1;
    FOR(m,1,10000) {
        FOR(n,1,m-1) {
            mm[m][n] = (mm[m - 1][n] + mm[m - 1][n - 1]) % MOD;
        }
    }
}

void run() {
    int n, k;
    scanf("%d %d", &n, &k);
    REP(i,n) scanf("%d", &a[i]);
    sort(a, a + n);

    LL res = 0;
    FOR(i,k-1,n-1) {
        res = (res + mm[i][k - 1] * a[i]) % MOD;
    }
    printf("%d\n", res);
}

int main() {
    init();
    int m;
    scanf("%d", &m);
    FOR(i,1,m) {
        printf("Case #%d: ", i);
        run();
    }
    return 0;
}
