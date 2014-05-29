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
#define MP make_pair
#define MPI make_pair<int, int>
#define PB push_back
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PI;

class Solution {
public:
    vector<VI> res;
    VI mm;
    void doit(int idx, int n, int k) {
        if (idx == k) {
            res.PB(mm);
        } else {
            int st;
            if (idx == 0) st = 1;
            else st = mm[idx - 1] + 1;
            FOR(i,st,n) {
                mm[idx] = i;
                doit(idx + 1, n, k);
            }
        }
    }
    vector<vector<int> > combine(int n, int k) {
        res.clear();
        mm.resize(k);
        doit(0, n, k);
        return res;
    }
};

int main() {
    Solution s = Solution();
    vector<VI> mm = s.combine(4, 2);
    REP(i,mm.size()) {
        REP(j,mm[i].size()) cout << mm[i][j] << " ";
        cout << endl;
    }
    return 0;
}
