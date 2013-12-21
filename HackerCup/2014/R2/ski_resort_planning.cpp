#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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
#include <cstring>
#include <ctime>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

#define MAXN 5000
#define MOD 1000000007

LL two[MAXN + 5];
int p[MAXN + 5];
int sz[MAXN + 5];

void run() {
    int n, v;
    scanf("%d", &n);
    p[0] = -1;
    sz[0] = 1;
    LL ret = 1;
    FOR(i,1,n-1) {
        scanf("%d", &v);
        LL tmp = (two[sz[v]] + MOD - 1) % MOD;
        REP(j,i) {
            if (p[j] == v) {
                tmp = (tmp - (two[sz[j]] - 1) % MOD + MOD) % MOD;
            }
        }
        ret = (ret * tmp) % MOD;
        p[i] = v;
        sz[i] = 1;
        while (v != -1) {
            ++sz[v];
            v = p[v];
        }
    }
    printf("%d\n", ret);
}

int main() {
    two[0] = 1;
    FOR(i,1,MAXN) two[i] = (two[i - 1] << 1) % MOD;
    int kase;
    scanf("%d", &kase);
    FOR(k,1,kase) {
        printf("Case #%d: ", k);
        run();
    }
    return 0;
}
