#include <iostream>
#include <map>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int n = s.length();
        int ret = mp[s[n - 1]];
        RFOR(i,n-2,0) {
            if (mp[s[i]] >= mp[s[i + 1]]) ret += mp[s[i]];
            else ret -= mp[s[i]];
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    cout << s.romanToInt("MMCDLVI") << endl;
    return 0;
}
