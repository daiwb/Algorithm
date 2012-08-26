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
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

int mat[1005][1005];

void run() {
    memset(mat, 0, sizeof(mat));
    int n;
    scanf("%d", &n);
    REP(i,n) {
        int m;
        scanf("%d", &m);
        REP(j,m) {
            int t;
            cin >> t;
            mat[i][t - 1] = 1;
        }
    }
    REP(k,n) {
        REP(i,n) {
            REP(j,n) {
                mat[i][j] += min(mat[i][k], mat[k][j]);
                if (mat[i][j] >= 2) {
                    printf("Yes\n");
                    return;
                }
            }
        }
    }
    printf("No\n");
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout <<  "Case #" << c << ": ";
        run();
    }
    return 0;
}
