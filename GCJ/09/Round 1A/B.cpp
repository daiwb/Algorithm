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
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
#define INF 1000000000000000000LL
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

int N, M;
LL S[25][25], W[25][25], T[25][25];

LL mm[60][60];

void run() {
    scanf("%d %d", &N, &M);
    //cin >> N >> M;
    RFOR(i,N-1,0) {
        REP(j,M) {
            scanf("%d %d %d", &S[i][j], &W[i][j], &T[i][j]);
            //cin >> S[i][j] >> W[i][j] >> T[i][j];
        }
    }

    REP(i,60) {
        REP(j,60) {
            mm[i][j] = INF;
        }
    }

    int N2 = 2 + (N << 1), M2 = 2 + (M << 1);

    priority_queue<pair<LL, pair<int, int> > > que;
    que.push(make_pair(0, make_pair(1, 1)));
    
    while (!que.empty()) {
        pair<LL, pair<int, int> > now = que.top();
        que.pop();

        LL dist = -now.first;
        int x = now.second.first, y = now.second.second;

        if (dist >= mm[x][y]) continue;

        mm[x][y] = dist;

        if (dist >= mm[N2 - 2][M2 - 2]) continue;

        if (x & 1) {
            if (dist + 2 < mm[x - 1][y]) {
                que.push(make_pair(-(dist + 2), make_pair(x - 1, y)));
            }
        } else {
            if (dist + 2 < mm[x + 1][y]) {
                que.push(make_pair(-(dist + 2), make_pair(x + 1, y)));
            }
        }

        if (y & 1) {
            if (dist + 2 < mm[x][y - 1]) {
                que.push(make_pair(-(dist + 2), make_pair(x, y - 1)));
            }
        } else {
            if (dist + 2 < mm[x][y + 2]) {
                que.push(make_pair(-(dist + 2), make_pair(x, y + 1)));
            }
        }

        if (x == 0 || x == N2 - 1 || y == 0 || y == M2 - 1) continue;

        int r = (x - 1) >> 1, c = (y - 1) >> 1;
        int s = S[r][c], w = W[r][c], t = T[r][c] % (s + w);
        LL d = (dist + s + w - t) % (s + w);

        int p;
        
        if (x & 1) p = 1;
        else p = -1;

        if (d < s) {
            if (dist + 1 < mm[x + p][y]) {
                que.push(make_pair(-(dist + 1), make_pair(x + p, y)));
            }
        } else {
            if (dist + 1 + s + w - d < mm[x + p][y]) {
                que.push(make_pair(-(dist + 1 + s + w - d), make_pair(x + p, y)));
            }
        }

        if (y & 1) p = 1;
        else p = -1;

        if (d < s) {
            if (dist + 1 + s - d < mm[x][y + p]) {
                que.push(make_pair(-(dist + 1 + s - d), make_pair(x, y + p)));
            }
        } else {
            if (dist + 1 < mm[x][y + p]) {
                que.push(make_pair(-(dist + 1), make_pair(x, y + p)));
            }
        }
    }

    printf("%d\n", mm[N2 - 2][M2 - 2]);
    //cout << mm[N2 - 2][M2 - 2] << endl;
}

int main() {
    int C;
    scanf("%d", &C);
    //cin >> C;
    FOR(c,1,C) {
        printf("Case #%d: ", c);
        //cout << "Case #" << c << ": ";
        run();
    }
	return 0;
}
