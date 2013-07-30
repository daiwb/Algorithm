#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        string ret = s;
        int len = s.length();
        int n = nRows * 2;
        int idx = 0;
        REP(i,nRows) {
            for (int j = i; j < len; j += n - 2) {
                ret[idx++] = s[j];
                int t = j + n - 2 - i - i;
                if (t < len && t != j && t != j + n - 2) ret[idx++] = s[t];
            }
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    cout << s.convert("A", 1) << endl;
    return 0;
}
