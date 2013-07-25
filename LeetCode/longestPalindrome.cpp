#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        RFOR(lt,len,2) {
            FOR(i,0,len-lt) {
                int l = i, r = i + lt - 1;
                bool flag = true;
                while (l < r) {
                    if (s[l] != s[r]) {
                        flag = false;
                        break;
                    }
                    ++l, --r;
                }
                if (flag) return s.substr(i, lt);
            }
        }
        return s.substr(0, 1);
    }
};
