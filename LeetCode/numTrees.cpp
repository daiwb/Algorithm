#include <vector>
#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

class Solution {
public:
    int numTrees(int n) {
        if (n <= 2) return max(1, n);
        vector<LL> mm(n + 1);
        mm[0] = 1;
        mm[1] = 1;
        mm[2] = 2;
        FOR(m,3,n) {
            mm[m] = 0;
            FOR(i,1,m) {
                mm[m] += mm[i - 1] * mm[m - i];
            }
        }
        return mm[n];
    }
};

int main() {
    return 0;
}
