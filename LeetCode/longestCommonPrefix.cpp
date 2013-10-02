#include <iostream>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        REP(i,strs[0].length()) {
            FOR(j,1,strs.size()-1) {
                if (i >= strs[j].length() || strs[0][i] != strs[j][i]) return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};

int main() {
    vector<string> mm;
    mm.push_back("abc");
    mm.push_back("abd");
    mm.push_back("aaa");
    Solution s = Solution();
    cout << s.longestCommonPrefix(mm) << endl;
    return 0;
}
