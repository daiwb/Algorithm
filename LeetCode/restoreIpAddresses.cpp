#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

string str;
int n;
vector<vector<int> > flag;
vector<vector<vector<string> > > mm;

vector<string> dp(int idx, int m) {
    if (flag[idx][m] != 0) return mm[idx][m];

    if (idx == n || m == 0) {
        if (idx == n && m == 0) mm[idx][m].push_back("");
        flag[idx][m] = 1;
        return mm[idx][m];
    }

    int num = 0;
    string t = "";
    FOR(i,idx,n-1) {
        t += str[i];
        num = num * 10 + str[i] - '0';
        if (num > 255) break;
        if (i == idx + 1 && str[i - 1] == '0') break;
        vector<string> q = dp(i + 1, m - 1);
        REP(j,q.size()) {
            if (q[j] == "") mm[idx][m].push_back(t);
            else mm[idx][m].push_back(t + "." + q[j]);
        }
    }

    flag[idx][m] = 1;
    return mm[idx][m];
}

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        str = s;
        n = str.length();
        flag.assign(n + 5, vector<int>(5, 0));
        mm.assign(n + 5, vector<vector<string> >(5, vector<string>()));
        return dp(0, 4);
    }
};

int main() {
    Solution s;
    vector<string> ret = s.restoreIpAddresses("010010");
    REP(i,ret.size()) cout << ret[i] << endl;
    return 0;
}
