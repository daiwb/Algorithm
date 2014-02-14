#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        REP(i,9) {
            vector<int> r(10, 0), c(10, 0);
            REP(j,9) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (r[num] == 1) return false;
                    r[num] = 1;
                }
                if (board[j][i] != '.') {
                    int num = board[j][i] - '0';
                    if (c[num] == 1) return false;
                    c[num] = 1;
                }
            }
        }

        for (int rr = 0; rr < 9; rr += 3) {
            for (int cc = 0; cc < 9; cc += 3) {
                vector<int> m(10, 0);
                REP(i,3) {
                    REP(j,3) {
                        if (board[rr + i][cc + j] != '.') {
                            int num = board[rr + i][cc + j] - '0';
                            if (m[num] == 1) return false;
                            m[num] = 1;
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    return 0;
}
