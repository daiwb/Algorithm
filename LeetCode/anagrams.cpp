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
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        int n = strs.size();
        map<string, int> mp;
        REP(i,n) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (mp.find(s) == mp.end()) mp[s] = i;
            else {
                if (mp[s] >= 0) res.PB(strs[mp[s]]);
                res.PB(strs[i]);
                mp[s] = -1;
            }
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    return 0;
}
