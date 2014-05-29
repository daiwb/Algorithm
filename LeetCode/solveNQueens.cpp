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
    vector<VS> res;
    bool isok(VI& mm, int row) {
        REP(i,row) {
            if (mm[i] == mm[row] || (abs(mm[i] - mm[row]) == (row - i))) return false;
        }
        return true;
    }
    void doit(VI& mm, int row, int n) {
        if (row == n) {
            VS t;
            REP(i,n) {
                string s(n, '.');
                s[mm[i]] = 'Q';
                t.PB(s);
            }
            res.PB(t);
        } else {
            REP(i,n) {
                mm[row] = i;
                if (isok(mm, row)) doit(mm, row + 1, n);
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        res.clear();
        VI mm(n, -1);
        doit(mm, 0, n);
        return res;
    }
};

int main() {
    Solution s = Solution();
    return 0;
}
