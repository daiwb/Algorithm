#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long LL;

class player {
public:
    int p, e;
};

bool cmp1(const player& a, const player& b) {
    return a.p > b.p;
}

bool cmp2(const player& a, const player& b) {
    return a.e > b.e;
}

int n, k;
LL sum, res;
vector<player> mm, dd;

void doit(int win) {
    int rk = 1;
    LL sub = 0;
    REP(i,n) {
        if (mm[i].p > win) ++rk;
    }
    int lo = n - win;
    REP(i,n) {
        if (lo == 0) break;
        bool chk = (dd[i].p == win || dd[i].p + 1 == win);
        if (chk && rk == k) continue;
        if (chk) ++rk;
        sub += dd[i].e;
        --lo;
    }
    //if (lo == 0) {
        res = min(res, sum - sub);
    //}
}

int main() {
    scanf("%d %d", &n, &k);
    if (k == n + 1) {
        printf("0\n");
        return 0;
    }
    sum = 0;
    mm.clear();
    dd.clear();
    REP(i,n) {
        player ppl;
        scanf("%d %d", &ppl.p, &ppl.e);
        mm.push_back(ppl);
        dd.push_back(ppl);
        sum += ppl.e;
    }
    sort(mm.begin(), mm.end(), cmp1);
    sort(dd.begin(), dd.end(), cmp2);
    res = sum;
    int W = mm[k - 1].p;
    if (W > n) {
        printf("-1\n");
        return 0;
    }

    if (W + 2 <= n) doit(W + 2);
    if (W + 1 <= n) doit(W + 1);
    doit(W);
    printf("%I64d\n", res);
    return 0;
}
