#include <vector>
#include <deque>
#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

int dx[][8] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution {
public:
    void bfs(vector<vector<char> > &board, int x, int y, int& m, int& n) {
        deque<pair<int, int> > que;
        board[x][y] = '!';
        que.push_back(make_pair(x, y));
        while (!que.empty()) {
            int nx = que.front().first;
            int ny = que.front().second;
            que.pop_front();
            REP(i,4) {
                int tx = nx + dx[i][0];
                int ty = ny + dx[i][1];
                if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
                if (board[tx][ty] != 'O') continue;
                board[tx][ty] = '!';
                que.push_back(make_pair(tx, ty));
            }
        }
    }
    void solve(vector<vector<char> > &board) {
        int m = board.size();
        if (m <= 2) return;
        int n = board[0].size();
        if (n <= 2) return;
        REP(i,n) {
            if (board[0][i] == 'O') bfs(board, 0, i, m, n);
            if (board[m - 1][i] == 'O') bfs(board, m - 1, i, m, n);
        }
        REP(i,m) {
            if (board[i][0] == 'O') bfs(board, i, 0, m, n);
            if (board[i][n - 1] == 'O') bfs(board, i, n - 1, m , n);
        }
        REP(i,m) {
            REP(j,n) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '!') board[i][j] = 'O';
            }
        }
    }
};

int main() {
    return 0;
}
