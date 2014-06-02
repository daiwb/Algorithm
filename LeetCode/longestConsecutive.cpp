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
#include <unordered_map>
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
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> mp;
        REP(i,num.size()) mp[num[i]] = true;
        int res = 0;
        REP(i,num.size()) {
            int cur = num[i];
            if (mp.find(cur) == mp.end()) continue;
            int cnt = 1;
            mp.erase(cur);
            while (mp.find(cur + 1) != mp.end()) {
                ++cnt;
                mp.erase(cur++);
            }
            cur = num[i];
            while (mp.find(cur - 1) != mp.end()) {
                ++cnt;
                mp.erase(cur--);
            }
            res = max(res, cnt);
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    return 0;
}
