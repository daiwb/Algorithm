#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

int main() {
    string str;
    cin >> str;
    vector<vector<int> > mm(26, vector<int>());
    REP(i,str.length()) mm[str[i] - 'A'].push_back(i);
    int res = 1;
    REP(i,26) {
        if (mm[i].empty()) continue;
        REP(j,mm[i].size()) {
            int st = mm[i][j];
            int n = 1;
            FOR(k,j+1,mm[i].size()-1) {
                int d = mm[i][k] - st;
                if (d & 1) {
                    ++n;
                    st = mm[i][k];
                }
            }
            res = max(res, n);
        }
    }
    cout << res << endl;
    return 0;
}
