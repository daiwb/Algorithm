#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

int mm[55][55];
int R, C, M, S;
bool rotate;

char convert(int val) {
    if (val == -1) return 'c';
    else if (val == 1) return '*';
    else return '.';
}

void setValues(int val) {
    REP(i,55) {
        REP(j,55) mm[i][j] = val;
    }
}

void print(bool rotate) {
    if (rotate) {
        REP(i,C) {
            REP(j,R) {
                cout << convert(mm[j][i]);
            }
            cout << endl;
        }
    } else {
        REP(i,R) {
            REP(j,C) {
                cout << convert(mm[i][j]);
            }
            cout << endl;
        }
    }
}

void run() {
    cin >> R >> C >> M;
    S = R * C - M;

    if (M == 0) {
        memset(mm, 0, sizeof(mm));
        mm[0][0] = -1;
        print(false);
        return;
    }

    if (S == 1) {
        setValues(1);
        mm[0][0] = -1;
        print(false);
        return;
    }

    bool rotate = false;
    if (R > C) {
        swap(R, C);
        rotate = true;
    }

    if (R == 1) {
        setValues(1);
        REP(i,S) mm[0][i] = 0;
        mm[0][0] = -1;
        print(rotate);
        return;
    }

    if (R == 2) {
        if (S & 1) cout << "Impossible" << endl;
        else if (S < 4) cout << "Impossible" << endl;
        else {
            setValues(1);
            REP(i,S/2) mm[0][i] = mm[1][i] = 0;
            mm[0][0] = -1;
            print(rotate);
        }
        return;
    }

    if (S <= 3) {
        cout << "Impossible" << endl;
        return;
    }

    RFOR(p,C,2) {
        if (p * R < S) break;
        
        int rest = S - p * 2;

        setValues(1);
        REP(i,p) mm[0][i] = mm[1][i] = 0;

        if (rest == 0) {
            mm[0][0] = -1;
            print(rotate);
            return;
        }

        if (rest <= 1) continue;

        int r = R - 2;
        int num = rest / r;
        if (num >= 2) {
            REP(i,r) {
                REP(j,num) {
                    mm[2 + i][j] = 0;
                }
            }
            rest -= num * r;
            REP(i,rest) {
                mm[2 + i][num] = 0;
            }
        } else {
            REP(i,(rest/2)) mm[2 + i][0] = mm[2 + i][1] = 0;
            if (rest & 1) {
                if (2 >= p) continue;
                else mm[2][2] = 0;
            }
        }
        mm[0][0] = -1;
        print(rotate);

        return;
    }
    
    cout << "Impossible" << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ":" << endl;
        run();
    }
    return 0;
}
