#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        REP(i,s.length()) {
            if (s[i] >= '0' && s[i] <= '9') str += s[i];
            else if (s[i] >= 'a' && s[i] <= 'z') str += s[i];
            else if (s[i] >= 'A' && s[i] <= 'Z') str += (s[i] - 'A' + 'a');
        }
        int len = str.length();
        REP(i,(len/2)) {
            if (str[i] != str[len - 1 - i]) return false;
        }
        return true;
    }
};

int main() {
    return 0;
}
