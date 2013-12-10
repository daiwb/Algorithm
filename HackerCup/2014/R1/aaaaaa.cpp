#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

int mat[505][505];
int mm[505][505][2];
int n, m;

int dp(int x, int y, int fg) {
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    
    int& ret = mm[x][y][fg];
    if (ret != -1) return ret;
    
    if (mat[x][y] == 1) return ret = 0;

    ret = 1;

    if (x + 1 < n) {
        ret = max(ret, 1 + dp(x + 1, y, fg));

        if (fg == 0 && mat[x + 1][y] != 1) {
            int s = 0;
            RFOR(ny,y-1,0) {
                if (mat[x + 1][ny] == 1) break;
                ++s;
                int tmp = 2 + s + dp(x + 2, ny, 1);
                ret = max(ret, tmp);
            }
        }
    }
    
    if (y + 1 < m) {
        ret = max(ret, 1 + dp(x, y + 1, fg));

        if (fg == 0 && mat[x][y + 1] != 1) {
            int s = 0;
            RFOR(nx,x-1,0) {
                if (mat[nx][y + 1] == 1) break;
                ++s;
                int tmp = 2 + s + dp(nx, y + 2, 1);
                ret = max(ret, tmp);
            }
        }
    }

    return ret;
}

void run() {
    cin >> n >> m;
    REP(i,n) {
        string str;
        cin >> str;
        REP(j,m) {
            if (str[j] == '#') mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }

    memset(mm, -1, sizeof(mm));
    cout << dp(0, 0, 0) << endl;
}

int main() {
    int T;
    cin >> T;
    FOR(t,1,T) {
        cout << "Case #" << t << ": ";
        run();
    }
    return 0;
}
