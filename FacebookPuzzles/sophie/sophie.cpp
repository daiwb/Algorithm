#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

#define INF 1000000000
#define eps 1e-8

int m;
map<string, int> mp;
vector<double> pro;
vector<vector<double> > dis;
vector<vector<bool> > links;
double ret;
vector<int> vv;

void init(const char* argv[]) {
    ifstream input(argv[1]);
    input >> m;

    REP(i,m) {
        string loc;
        double p;
        input >> loc >> p;
        mp[loc] = i;
        pro.push_back(p);
    }

    dis.assign(m, vector<double>(m, INF));
    links.assign(m, vector<bool>(m, false));

    int c;
    input >> c;
    REP(i,c) {
        string f, t;
        double s;
        input >> f >> t >> s;
        int idx1 = mp[f], idx2 = mp[t];
        dis[idx1][idx2] = dis[idx2][idx1] = s;
        links[idx1][idx2] = links[idx2][idx1] = true;
    }

    REP(k,m) {
        REP(i,m) {
            REP(j,m) {
                if (links[i][k] && links[k][j]) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    links[i][j] = true;
                }
            }
        }
    }

    vv.assign(m, 0);
}

void dfs(int now, double cur, double r, double r2) {
    if (cur >= ret && ret > eps) return;    
    
    double nextr = r - pro[now];

    if (fabs(nextr) < eps) {
        if (ret < eps) ret = cur;
        else ret = min(ret, cur);
        return;
    }
    
    double rp = 1 - pro[now] / r;
    double nextr2 = r2 * rp;
    rp *= r2;
    REP(i,m) {
        if (vv[i] == 1) continue;
		if (!links[now][i]) continue;
        if (pro[i] < eps) continue;
        vv[i] = 1;
        dfs(i, cur + dis[now][i] * rp, nextr, nextr2);
        vv[i] = 0;
    }
}

void run() {
    FOR(i,1,m-1) {
        if (!links[0][i] && fabs(pro[i]) > eps) {
            cout << "-1.00" << endl;
            return;
        }
    }

    ret = -1.0;
    
    vv[0] = 1;
    dfs(0, 0.0, 1.0, 1.0);

    printf("%.2lf\n", ret);
}

int main(int argc, const char* argv[]) {
    init(argv);
    run();
}
