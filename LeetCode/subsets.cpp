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
    VI mm;
    vector<VI> res;
    int n;
    void doit(int st, VI& S) {
        mm.PB(-1);
        FOR(i,st,n-1) {
            mm.back() = S[i];
            res.PB(mm);
            doit(i + 1, S);
        }
        mm.pop_back();
    }
    vector<vector<int> > subsets(vector<int> &S) {
        n = S.size();
        res.clear();
        mm.clear();
        res.PB(mm);
        sort(S.begin(), S.end());
        doit(0, S);
        return res;
    }
};

int main() {
    Solution s = Solution();
    VI S;
    S.PB(1);
    S.PB(2);
    S.PB(3);
    vector<VI> res = s.subsets(S);
    REP(i,res.size()) {
        REP(j,res[i].size()) cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
