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
    string getPermutation(int n, int k) {
        vector<int> mm;
        vector<int> num(n + 1);
        num[0] = 1;
        FOR(i,1,n) {
            num[i] = num[i - 1] * i;
            mm.push_back(i);
        }
        string res = "";
        RFOR(i,n,2) {
            int t = num[i - 1];
            int idx = (k + t - 1) / t;
            k -= (idx - 1) * t;
            res += char('0' + mm[idx - 1]);
            mm.erase(mm.begin() + idx - 1);
        }
        res += char('0' + mm[0]);
        return res;
    }
};

int main() {
    Solution s;
    int n = 1;
    FOR(i,1,4) {
        cout << i << endl;
        n *= i;
        FOR(j,1,n) cout << s.getPermutation(i, j) << endl;
        cout << endl;
    }
    return 0;
}
