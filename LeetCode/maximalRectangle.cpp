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
    int maximalRectangle(vector<vector<char> > &matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        
        vector<vector<int> > hh(n, vector<int>(m, 0)), vv(n, vector<int>(m, 0));
        REP(i,n) {
            hh[i][m - 1] = matrix[i][m - 1] - '0';
            RFOR(j,m-2,0) {
                if (matrix[i][j] == '1') hh[i][j] += hh[i][j + 1] + 1;
            }
        }
        REP(j,m) {
            vv[n - 1][j] = matrix[n - 1][j] - '0';
            RFOR(i,n-2,0) {
                if (matrix[i][j] == '1') vv[i][j] += vv[i + 1][j] + 1;
            }
        }

        int res = 0;
        REP(i,n) {
            if ((n - i) * m <= res) break;
            REP(j,m) {
                if ((n - i) * (m - j) <= res) break;

                int t = vv[i][j];
                int num = hh[i][j];
                REP(k,num) {
                    t = min(t, vv[i][j + k]);
                    if (t * num <= res) break;
                    res = max(res, t * (k + 1));
                }
            }
        }

        return res;
    }
};

int main() {
    int data[6][4] = {{0,1,0,0},{0,1,1,1},{0,1,1,1},{0,1,1,1},{0,1,1,0},{0,0,0,0}};
    vector<vector<char> > input(6, vector<char>(4));
    REP(i,6) {
        REP(j,4) {
            input[i][j] = data[i][j] + '0';
        }
    }

    Solution s;
    cout << s.maximalRectangle(input) << endl;
    return 0;
}
