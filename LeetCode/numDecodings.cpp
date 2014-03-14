#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0) return 0;
        REP(i,n) {
            if (!(s[i] >= '0' && s[i] <= '9')) return 0;
        }
        vector<int> mm(n + 5, 0);
        mm[n] = 1;
        RFOR(i,n-1,0) {
            if (s[i] == '0') {
                mm[i] = 0;
                continue;
            }
            mm[i] = mm[i + 1];
            if (i + 1 < n) {
                int num = (s[i] - '0') * 10 + s[i + 1] - '0';
                if (num <= 26) mm[i] += mm[i + 2];
            }
        }
        return mm[0];
    }
};

int main() {
    Solution s;
    cout << s.numDecodings("12") << endl;
    cout << s.numDecodings("10") << endl;
    return 0;
}
