#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

int mat[26][26];
int clr[26][26];

void run() {
    memset(mat, 0, sizeof(mat));
    memset(clr, 0, sizeof(clr));
    int C, D, N;
    string str;
    cin >> C;
    REP(i,C) {
        cin >> str;
        int a = str[0] - 'A', b = str[1] - 'A', c = str[2] - 'A';
        mat[a][b] = mat[b][a] = c;
    }
    cin >> D;
    REP(i,D) {
        cin >> str;
        int a = str[0] - 'A', b = str[1] - 'A';
        clr[a][b] = clr[b][a] = -1;
    }
    cin >> N >> str;
    string res;
    REP(i,N) {
        if (res.length() == 0) {
            res += str[i];
            continue;
        }
        int a = str[i] - 'A', b = res[res.length() - 1] - 'A';
        if (mat[a][b] > 0) {
            res[res.length() - 1] = char(mat[a][b] + 'A');
        } else {
            bool fl = false;
            REP(j,res.length()) {
                if (clr[res[j] - 'A'][a] == -1) {
                    fl = true;
                    break;
                }
            }
            if (fl) res = "";
            else res += str[i];
        }
    }
    cout << "[";
    REP(i,res.length()) {
        if (i) cout << ", ";
        cout << res[i];
    }
    cout << "]" << endl;
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
