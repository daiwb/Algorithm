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
    int res;
    bool isok(int mm[], int row) {
        REP(i,row) {
            if (mm[i] == mm[row] || (abs(mm[i] - mm[row]) == (row - i))) return false;
        }
        return true;
    }
    void doit(int mm[], int row, int n) {
        if (row == n) {
            ++res;
        } else {
            REP(i,n) {
                mm[row] = i;
                if (isok(mm, row)) doit(mm, row + 1, n);
            }
        }
    }

    int totalNQueens(int n) {
        res = 0;
        int *mm = new int[n];
        doit(mm, 0, n);
        return res;
    }
};

int main() {
    Solution s = Solution();
    return 0;
}
