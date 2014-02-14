#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n <= 1) return 0;
        int ret = 0;
        vector<int> mm(n, 0);
        RFOR(i,n-2,0) {
            if (s[i] == ')') continue;
            int rt = i + mm[i + 1] + 1;
            if (rt < n && s[rt] == ')') {
                mm[i] = mm[i + 1] + 2;
                if (++rt < n) mm[i] += mm[rt];
            }
            ret = max(ret, mm[i]);
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.longestValidParentheses("(()") << endl;
    cout << s.longestValidParentheses(")()())") << endl;
    cout << s.longestValidParentheses("(((()(()") << endl;
    return 0;
}
