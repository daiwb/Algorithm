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
    int sqrt(int x) {
        if (x <= 1) return x;
        LL lt = 1, rt = (x >> 1) + 1;
        while (lt <= rt) {
            LL mt = (lt + rt) >> 1;
            LL m = mt * mt;
            if (m <= x) lt = mt + 1;
            else rt = mt - 1;
        }
        return lt - 1;
    }
};

int main() {
    return 0;
}
