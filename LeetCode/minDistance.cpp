#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

string w1, w2;
int n1, n2;
vector<vector<int> > mm;

int dp(int i1, int i2) {
    int& res = mm[i1][i2];
    if (res != -1) return res;

    if (i1 == n1) return res = n2 - i2;
    if (i2 == n2) return res = n1 - i1;

    if (w1[i1] == w2[i2]) return res = dp(i1 + 1, i2 + 1);

    res = 1 + dp(i1 + 1, i2 + 1);
    res = min(res, 1 + dp(i1, i2 + 1));
    res = min(res, 1 + dp(i1 + 1, i2));

    return res;
}

class Solution {
public:
    int minDistance(string word1, string word2) {
        w1 = word1, w2 = word2;
        if (w1.length() > w2.length()) swap(w1, w2);
        n1 = w1.length(), n2 = w2.length();
        if (n1 == 0) return n2;
        mm.assign(n1 + 5, vector<int>(n2 + 5, -1));
        return dp(0, 0);
    }
};

int main() {
    Solution s;
    cout << s.minDistance("acde", "abcd") << endl;
    return 0;
}
