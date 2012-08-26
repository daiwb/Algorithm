#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

int n, idx;
int vv[105];
int mat[105][105];
int mm[105];

void dfs(int now) {
    mm[idx] = now;
    vv[now] = 1;
    ++idx;
    if (idx == n) return;

    REP(i,n) {
        if (vv[i] == 1) continue;
        if (mat[now][i] == 0) continue;
        dfs(i);
        return;
    }
}

void run() {
    cin >> n;
    memset(mat, 0, sizeof(mat));
    REP(i,n) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        mat[a][b] = c;
        mat[b][a] = -c;
    }
    memset(vv, 0, sizeof(vv));
    idx = 0;
    dfs(0);

    int cost1 = 0, cost2 = 0;
    REP(i,n) {
        int f = mm[i], t = mm[(i + 1) % n];
        if (mat[f][t] > 0) cost1 += mat[f][t];
        else cost2 -= mat[f][t];
    }

    cout << min(cost1, cost2) << endl;
}

int main() {
    run();
    return 0;
}
