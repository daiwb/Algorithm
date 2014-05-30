#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
#define MP make_pair
#define MPI make_pair<int, int>
#define PB push_back
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PI;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int row, col, len;
vector<VI> vv;
bool valid;
vector<vector<char> > board;
string word;

class Solution {
public:
    void dfs(int x, int y, int idx) {
        if (valid) return;
        if (idx == len) {
            valid = true;
            return;
        }
        REP(i,4) {
            int tx = x + dir[i][0], ty = y + dir[i][1];
            if (tx < 0 || tx >= row || ty < 0 || ty >= col) continue;
            if (board[tx][ty] != word[idx]) continue;
            if (vv[tx][ty] == 1) continue;
            vv[tx][ty] = 1;
            dfs(tx, ty, idx + 1);
            vv[tx][ty] = 0;
        }
    }
    bool isok(int x, int y) {
        vv.assign(row, VI(col, 0));
        valid = false;
        vv[x][y] = 1;
        dfs(x, y, 1);
        return valid;
    }
    bool exist(vector<vector<char> >& _board, string _word) {
        board = _board;
        word = _word;
        row = board.size();
        if (row == 0) return false;
        col = board[0].size();
        if (col == 0) return false;
        len = word.length();
        if (len == 0) return false;
        REP(i,row) {
            REP(j,col) {
                if (board[i][j] != word[0]) continue;
                if (isok(i, j)) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<char> > board;
    string t[] = {"ABCE", "SFCS", "ADEE"};
    REP(i,3) {
        vector<char> q;
        REP(j,4) {
            q.PB(t[i][j]);
        }
        board.PB(q);
    }
    //cout << s.exist(board, "ABCCED") << endl;
    //cout << s.exist(board, "SEE") << endl;
    cout << s.exist(board, "ABCB") << endl;
    return 0;
}
