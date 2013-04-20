#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

bool run() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > > mm(105, vector<pair<int, int> >());
    REP(i,n) REP(j,m) {
        int t;
        cin >> t;
        mm[t].push_back(make_pair(i, j));
    }
    vector<int> row(n, -1), col(m, -1);
    RFOR(cur,100,1) {
        REP(i,mm[cur].size()) {
            int x = mm[cur][i].first, y = mm[cur][i].second;
            bool flag = false;
            if (row[x] == -1 || row[x] == cur) {
                row[x] = cur;
                flag = true;
            }

            if (col[y] == -1 || col[y] == cur) {
                col[y] = cur;
                flag = true;
            }

            if (!flag) return false;
        }
    }
    return true;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        if (run()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
