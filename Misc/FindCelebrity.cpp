#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define MAXN 50

// If no such celebrity exists, return -1.
int FindCelebrity(int mat[][MAXN], int n) {
    int candidate = 0;
    FOR(i,1,n-1) {
        if (candidate == -1) {
            candidate = i;
            continue;
        }
        bool f1 = mat[candidate][i] > 0;
        bool f2 = mat[i][candidate] > 0;
        if (f1 == f2) candidate = -1;
        else if (f1 && !f2) candidate = i;
    }

    if (candidate == -1) return -1;
    REP(i,n) {
        if (candidate == i) continue;
        if (mat[candidate][i] > 0 || mat[i][candidate] == 0) return -1;
    }

    return candidate;
}

int main() {
    int mat[4][MAXN] = {{0, 0, 1, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};
    int res = FindCelebrity(mat, 4);
    cout << res << endl;
    return 0;
}
