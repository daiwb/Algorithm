/*
  ID: dwb19832
  PROG: ditch
  LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("ditch.in");
ofstream fout("ditch.out");

#define REP(i,n) for(int i=0;i<(n);++i)

#define MAXN 205
#define INF 2000000000

int mm[MAXN][MAXN];
int n;

int max_flow(int n, int mat[][MAXN], int source, int sink) {
    int cap[MAXN], vis[MAXN], pre[MAXN];
    int ret = 0;
    while (true) {
        memset(cap, 0, sizeof(cap));
        memset(vis, 0, sizeof(vis));
        cap[source] = INF;
        int mx, idx;
        while (true) {
            mx = 0, idx = -1;
            REP(i,n) {
                if (!vis[i] && cap[i] > mx) mx = cap[i], idx = i;
            }
            if (idx == -1) return ret;
            if (idx == sink) break;
            vis[idx] = 1;
            REP(i,n) {
                if (cap[i] < min(mm[idx][i], mx)) {
                    cap[i] = min(mm[idx][i], mx);
                    pre[i] = idx;
                }
            }
        }
        mx = cap[sink];
        for (int i = sink; i != source; i = pre[i]) {
            int t = pre[i];
            mm[t][i] -= mx, mm[i][t] += mx;
        }
        ret += mx;
    }
    return ret;
}

int main() {
    int m;
    int p1, p2, c;

    fin >> m >> n;
    memset(mm, 0, sizeof(mm));
    while (m--) {
        fin >> p1 >> p2 >> c;
        --p1; --p2;
        mm[p1][p2] += c;
    }
    
    int ret = max_flow(n, mm, 0, n - 1);
    fout << ret << endl;
    return 0;
}
