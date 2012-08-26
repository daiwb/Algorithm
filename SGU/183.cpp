#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define INF 1000000000
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

int n, m;
int C[10005];
int mm[10005][105];

/*int dp(int now, int last) {
    int& ret = mm[now][last];
    if (ret != -1) return ret;

    int idx = now + m - last;
    if (idx >= n) return ret = 0;
    
    ret = INF;
    
    FOR(i,now+1,idx) {
        int t = C[i] + dp(i, i - now);
        ret = min(ret, t);
    }

    return ret;
    }*/

int main() {
    scanf("%d %d", &n, &m);
    REP(i,n) scanf("%d", &C[i]);
    //REP(i,10005) C[i] = 10000;
    int res = INF;
    memset(mm, -1, sizeof(mm));
    FOR(i,1,m-1) mm[n - 1][i] = 0;
    RFOR(i,n-2,0) {
        FOR(j,1,m-1) {
            if (i - j < 0) break;

            int idx = i + m - j;
            if (idx >= n) mm[i][j] = 0;
            else {
                mm[i][j] = INF;
                FOR(k,i+1,idx) {
                    int t = C[k] + mm[k][k - i];
                    mm[i][j] = min(mm[i][j], t);
                }
            }
        }
    }
    REP(i,m) {
        FOR(j,i+1,m-1) {
            int t = C[i] + C[j];
            //t += dp(j, j - i);
            t += mm[j][j - i];
            res = min(res, t);
        }
    }
    printf("%d\n", res);
    return 0;
}
