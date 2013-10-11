#include <iostream>
#include <climits>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

class Solution {
public:
    string str, s;
    int len;
    vector<string> ret;
    map<char, string> mp;

    void dfs(int idx) {
        if (idx == len) {
            ret.push_back(s);
            return;
        }

        string t = mp[str[idx]];
        REP(i,t.length()) {
            s[idx] = t[i];
            dfs(idx + 1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        mp['0'] = "0";
        mp['1'] = "1";
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        s = str = digits;
        len = str.length();
        ret.clear();
        dfs(0);
        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<string> mm = s.letterCombinations("23");
    REP(i,mm.size()) {
        cout << mm[i] << endl;
    }
    return 0;
}
