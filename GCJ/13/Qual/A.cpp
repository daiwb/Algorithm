#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

string mat[4];

bool check(char ch, int x, int y, int dx, int dy) {
    REP(i,4) {
        if (mat[x][y] != ch && mat[x][y] != 'T') return false;
        x += dx;
        y += dy;
    }
    
    return true;
}

bool isok(char ch) {
    REP(i,4) {
        if (check(ch, i, 0, 0, 1)) return true;
    }

    REP(j,4) {
        if (check(ch, 0, j, 1, 0)) return true;
    }

    if (check(ch, 0, 0, 1, 1)) return true;
    if (check(ch, 3, 0, -1, 1)) return true;

    return false;
}

void run() {
    REP(i,4) cin >> mat[i];

    if (isok('X')) {
        cout << "X won" << endl;
        return;
    }

    if (isok('O')) {
        cout << "O won" << endl;
        return;
    }

    REP(i,4) REP(j,4) if (mat[i][j] == '.') {
        cout << "Game has not completed" << endl;
        return;
    }

    cout << "Draw" << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
