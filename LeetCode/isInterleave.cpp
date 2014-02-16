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
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if (l1 + l2 != l3) return false;
        if (l1 == 0) return s2 == s3;
        if (l2 == 0) return s1 == s3;

        vector<vector<int> > mm(l1 + 1, vector<int>(l2 + 1, 0));
        if (s3[l3 - 1] == s2[l2 - 1]) mm[l1][l2 - 1] = 1;
        if (s3[l3 - 1] == s1[l1 - 1]) mm[l1 - 1][l2] = 1;

        RFOR(idx,l3-2,0) {
            FOR(i,0,idx+1) {
                if (i > l1) break;
                int j = idx + 1 - i;
                if (j > l2) continue;
                if (j < 0) break;
                if (mm[i][j] == 0) continue;
                if (i - 1 >= 0 && s3[idx] == s1[i - 1]) mm[i - 1][j] = 1;
                if (j - 1 >= 0 && s3[idx] == s2[j - 1]) mm[i][j - 1] = 1;
            }
        }

        return mm[0][0] == 1;
    }
};

int main() {
    Solution s;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    return 0;
}
