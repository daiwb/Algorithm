#include <iostream>
#include <climits>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        REP(i,s.length()) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') sk.push(s[i]);
            else if (s[i] == ')') {
                if (!sk.empty() && sk.top() == '(') sk.pop();
                else return false;
            } else if (s[i] == ']') {
                if (!sk.empty() && sk.top() == '[') sk.pop();
                else return false;
            } else if (s[i] == '}') {
                if (!sk.empty() && sk.top() == '{') sk.pop();
                else return false;
            }
        }
        return sk.empty();
    }
};

int main() {
    Solution s = Solution();
    cout << s.isValid("()[]{}") << endl;
    cout << s.isValid("([)]") << endl;
    return 0;
}
