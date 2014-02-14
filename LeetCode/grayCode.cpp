#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

class Solution {
public:
    vector<int> grayCode(int n) {
        int num = (1 << n);
        vector<int> ret;
        REP(i,num) {
            ret.push_back(i ^ (i >> 1));
        }
        return ret;
    }
};

int main() {
    return 0;
}
