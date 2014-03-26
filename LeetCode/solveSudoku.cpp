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
    bool done;
    void doit(vector<vector<char> > &board, int now) {
        if (done) return;
        if (now == 81) {
            done = true;
            return;
        }
        int x = now / 9, y = now % 9;
        if (board[x][y] != '.') {
            doit(board, now + 1);
            return;
        }
        int r = x / 3 * 3, c = y / 3 * 3;
        vector<bool> valid(10, true);
        REP(i,9) {
            if (board[x][i] != '.') valid[board[x][i] - '0'] = false;
            if (board[i][y] != '.') valid[board[i][y] - '0'] = false;
        }
        REP(i,3) {
            REP(j,3) {
                if (board[r + i][c + j] != '.') valid[board[r + i][c + j] - '0'] = false;
            }
        }
        FOR(i,1,9) {
            if (!valid[i]) continue;
            board[x][y] = i + '0';
            doit(board, now + 1);
            if (done) return;
        }
        board[x][y] = '.';
    }
    void solveSudoku(vector<vector<char> > &board) {
        done = false;
        doit(board, 0);
    }
};

int main() {
    string data[9] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"};
    vector<vector<char> > board(9);
    REP(i,9) REP(j,9) board[i].push_back(data[i][j]);
    Solution s;
    s.solveSudoku(board);
    REP(i,9) {
        REP(j,9) cout << board[i][j];
        cout << endl;
    }
    return 0;
}
