#include <vector>
#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;

        int lp = 0, rp = m * n - 1;
        while (lp <= rp) {
            int mp = (lp + rp) >> 1;
            int x = mp / n, y = mp % n;
            if (matrix[x][y] == target) return true;
            else if (matrix[x][y] < target) lp = mp + 1;
            else rp = mp - 1;
        }
        return false;
    }
};

int main() {
    return 0;
}
