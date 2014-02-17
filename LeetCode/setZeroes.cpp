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
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        if (m == 0) return;

        bool f1 = false, f2 = false;
        REP(i,m) {
            if (matrix[0][i] == 0) {
                f1 = true;
                break;
            }
        }
        REP(i,n) {
            if (matrix[i][0] == 0) {
                f2 = true;
                break;
            }
        }
        FOR(i,1,n-1) {
            FOR(j,1,m-1) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        FOR(i,1,m-1) {
            if (matrix[0][i] == 0) {
                FOR(r,1,n-1) matrix[r][i] = 0;
            }
        }
        FOR(i,1,n-1) {
            if (matrix[i][0] == 0) {
                FOR(c,1,m-1) matrix[i][c] = 0;
            }
        }
        if (f1) {
            REP(i,m) matrix[0][i] = 0;
        }
        if (f2) {
            REP(i,n) matrix[i][0] = 0;
        }
    }
};

int main() {
    return 0;
}
