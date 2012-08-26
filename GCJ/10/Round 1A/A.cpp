#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

void run() {
    int n, k;
    cin >> n >> k;
    vector<string> dd(n);
    REP(i,n) {
        cin >> dd[i];
    }
    vector<string> mm = dd;
    REP(i,n) {
        REP(j,n) {
            mm[i][j] = dd[n - 1 - j][i];
        }
    }

    REP(c,n) {
        int r = n - 1;
        RFOR(i,n-1,0) {
            if (mm[i][c] != '.') {
                mm[r--][c] = mm[i][c];
            }
        }
        RFOR(i,r,0) mm[i][c] = '.';
    }

    bool isRed = false, isBlue = false;

    REP(i,n) {
        int cr = 0, cb = 0;
        REP(j,n) {
            if (mm[i][j] == 'R') {
                ++cr;
                if (cr >= k) isRed = true;
                cb = 0;
            } else if (mm[i][j] == 'B') {
                ++cb;
                if (cb >= k) isBlue = true;
                cr = 0;
            } else {
                cr = 0, cb = 0;
            }
        }
    }

    REP(j,n) {
        int cr = 0, cb = 0;
        REP(i,n) {
            if (mm[i][j] == 'R') {
                ++cr;
                if (cr >= k) isRed = true;
                cb = 0;
            } else if (mm[i][j] == 'B') {
                ++cb;
                if (cb >= k) isBlue = true;
                cr = 0;
            } else {
                cr = 0, cb = 0;
            }
        }
    }

    REP(i,n) {
        REP(j,n) {
            if (i == 0 || j == 0) {
                int dr = 1, dc = 1;
                int cr = 0, cb = 0;
                int ti = i, tj = j;
                while (true) {
                    if (mm[ti][tj] == 'R') {
                        ++cr;
                        if (cr >= k) isRed = true;
                        cb = 0;
                    } else if (mm[ti][tj] == 'B') {
                        ++cb;
                        if (cb >= k) isBlue = true;
                        cr = 0;
                    } else {
                        cr = 0, cb = 0;
                    }
                    ti += dr, tj += dc;
                    if (ti < 0 || ti >= n || tj < 0 || tj >= n) break;
                }
            }

            if (i == n - 1 || j == 0) {
                int dr = -1, dc = 1;
                int cr = 0, cb = 0;
                int ti = i, tj = j;
                while (true) {
                    if (mm[ti][tj] == 'R') {
                        ++cr;
                        if (cr >= k) isRed = true;
                        cb = 0;
                    } else if (mm[ti][tj] == 'B') {
                        ++cb;
                        if (cb >= k) isBlue = true;
                        cr = 0;
                    } else {
                        cr = 0, cb = 0;
                    }
                    ti += dr, tj += dc;
                    if (ti < 0 || ti >= n || tj < 0 || tj >= n) break;
                }
            }
        }
    }

    if (isRed && isBlue) cout << "Both" << endl;
    else if (isRed) cout << "Red" << endl;
    else if (isBlue) cout << "Blue" << endl;
    else cout << "Neither" << endl;
}

int main() {
    int kase;
    cin >> kase;
    FOR(k,1,kase) {
        cout << "Case #" << k << ": ";
        run();
    }
    return 0;
}
