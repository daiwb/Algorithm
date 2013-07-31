#include <iostream>
#include <climits>
#include <string>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

class Solution {
public:
    int atoi(const char *str) {
        string s(str);
        int len = s.length();
        LL num = 0;
        int idx = 0;
        while (idx < len && s[idx] == ' ') ++idx;
        int m = 1;
        if (idx < len) {
            if (s[idx] == '+') ++idx;
            else if (s[idx] == '-') {
                ++idx;
                m = -1;
            }
        }
        for (; idx < len; ++idx) {
            if (!(s[idx] >= '0' && s[idx] <= '9')) return num * m;
            num = num * 10 + s[idx] - '0';
            if (num * m > INT_MAX) return INT_MAX;
            if (num * m < INT_MIN) return INT_MIN;
        }
        return num * m;
    }
};

int main() {
    Solution sol = Solution();
    char *str = "   10000000000000000000000ad";
    cout << sol.atoi(str) << endl;
    return 0;
}
