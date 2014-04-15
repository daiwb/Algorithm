#include <iostream>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

int mm[55][55], R, C, M, S, rotate;

char convert(int val) {
    if (val == -1) return 'c';
    else if (val == 1) return '*';
    else return '.';
}

void setValues(int val) {
    REP(i,55) REP(j,55) mm[i][j] = val;
}

void print(int rotate) {
    mm[0][0] = -1;
    if (rotate == 1) {
        REP(i,C) {
            REP(j,R) cout << convert(mm[j][i]);
            cout << endl;
        }
    } else {
        REP(i,R) {
            REP(j,C) cout << convert(mm[i][j]);
            cout << endl;
        }
    }
}

void run() {
    cin >> R >> C >> M;
    S = R * C - M;
    if (M == 0) {
        memset(mm, 0, sizeof(mm));
        print(0);
        return;
    }
    if (S == 1) {
        setValues(1);
        print(0);
        return;
    }

    int rotate = 0;
    if (R > C) {
        swap(R, C);
        rotate = 1;
    }
    if (R == 1) {
        setValues(1);
        REP(i,S) mm[0][i] = 0;
        print(rotate);
        return;
    }
    if (R == 2) {
        if ((S & 1) || (S < 4)) cout << "Impossible" << endl;
        else {
            setValues(1);
            REP(i,S/2) mm[0][i] = mm[1][i] = 0;
            print(rotate);
        }
        return;
    }

    RFOR(p,C,2) {
        if (p * R < S) break;
        int rest = S - p * 2;
        setValues(1);
        REP(i,p) mm[0][i] = mm[1][i] = 0;

        if (rest == 0) {
            print(rotate);
            return;
        }
        if (rest <= 1) continue;

        int r = R - 2;
        int num = rest / r;
        if (num >= 2) {
            REP(i,r) REP(j,num) mm[2 + i][j] = 0;
            rest -= num * r;
            REP(i,rest) mm[2 + i][num] = 0;
        } else {
            REP(i,(rest/2)) mm[2 + i][0] = mm[2 + i][1] = 0;
            if (rest & 1) {
                if (2 >= p) continue;
                else mm[2][2] = 0;
            }
        }
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
