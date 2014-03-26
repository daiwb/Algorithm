#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

vector<int> cc;
int n;
vector<vector<bool> > flag;
vector<vector<vector<vector<int> > > > mm;

class Solution {
public:
    vector<vector<int> > doit(int idx, int t) {
        if (flag[idx][t]) return mm[idx][t];

        if (idx == n) {
            flag[idx][t] = true;
            return mm[idx][t];
        }

        mm[idx][t] = doit(idx + 1, t);
        int now = cc[idx], cnt = 1;
        while (now < t) {
            vector<vector<int> > tmp = doit(idx + 1, t - now);
            REP(i,tmp.size()) {
                vector<int> tt;
                REP(j,cnt) tt.push_back(cc[idx]);
                REP(j,tmp[i].size()) tt.push_back(tmp[i][j]);
                mm[idx][t].push_back(tt);
            }
            now += cc[idx];
            ++cnt;
        }
        if (now == t) {
            vector<int> tt;
            REP(i,cnt) tt.push_back(cc[idx]);
            mm[idx][t].push_back(tt);
        }
        flag[idx][t] = true;
        return mm[idx][t];
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        cc = candidates;
        sort(cc.begin(), cc.end());
        cc.erase(unique(cc.begin(), cc.end()), cc.end());
        n = cc.size();
        flag.assign(n + 5, vector<bool>(target + 5, false));
        mm.assign(n + 5, vector<vector<vector<int> > >(target + 5));
        vector<vector<int> > res = doit(0, target);
        return res;
    }
};

int main() {
    int data[] = {2,3,6,7};
    vector<int> can;
    REP(i,4) can.push_back(data[i]);
    Solution s;
    vector<vector<int> > res = s.combinationSum(can, 7);
    REP(i,res.size()) {
        REP(j,res[i].size()) cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
