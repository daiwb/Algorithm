// http://contest.usaco.org/OPEN11.htm

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

#define MAXN 100005

LL ps[MAXN] = {0};
int N, K;

int main() {
    scanf("%d %d", &N, &K);
    REP(i,N) {
        scanf("%lld", &ps[i + 1]);
        ps[i + 1] += ps[i];
    }
    priority_queue<pair<LL, int> > que;
    que.push(make_pair(0, 0));
    que.push(make_pair(-ps[1], 1));
    LL mx = ps[1];
    FOR(i,1,N) {
        while (que.top().second < i - K) que.pop();
        mx = ps[i] + que.top().first;
        que.push(make_pair(mx - ps[i + 1], i + 1));
    }
    printf("%lld\n", mx);
    return 0;
}
