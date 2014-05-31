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
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        int len = s1.length();
        if (len == 0) return true;
        vector<vector<VI> > mm(len, vector<VI>(len, VI(len + 5)));
        REP(i,len) {
            REP(j,len) {
                mm[i][j][0] = 1;
                mm[i][j][1] = (s1[i] == s2[j]);
            }
        }
        FOR(sz,2,len) {
            FOR(i,0,len-sz) {
                FOR(j,0,len-sz) {
                    mm[i][j][sz] = 0;
                    FOR(k,1,sz-1) {
                        if (mm[i][j][k] && mm[i + k][j + k][sz - k]) {
                            mm[i][j][sz] = 1;
                            break;
                        }
                        if (mm[i][j + sz - k][k] && mm[i + k][j][sz - k]) {
                            mm[i][j][sz] = 1;
                            break;
                        }
                    }
                }
            }
        }
        return (mm[0][0][len] == 1);
    }
};

int main() {
    Solution s = Solution();
    cout << s.isScramble("rgtae", "great") << endl;
    return 0;
}
