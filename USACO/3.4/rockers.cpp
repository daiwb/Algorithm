/*
ID: dwb19832
PROG: rockers
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("rockers.in");
ofstream fout("rockers.out");

int n, t, m;
int mm[405][25];
int len[25];

int dp(int left, int idx) {
    int& ret = mm[left][idx];
    if (ret != -1) return ret;

    if (left == 0) return ret = 0;
    if (idx == n) return ret = 0;

    ret = dp(left, idx + 1);
    int q = left % t;
    if (q == 0) q = t;
    for (int i = idx; i < n; ++i) {
        if (len[i] <= q) {
            ret = max(ret, 1 + dp(left - len[i], i + 1));
        } else if (len[i] <= t && left > q) {
            ret = max(ret, 1 + dp(left - q - len[i], i + 1));
        }
    }

    return ret;
}

int main() {
    fin >> n >> t >> m;
    for (int i = 0; i < n; ++i) fin >> len[i];
    memset(mm, -1, sizeof(mm));
    int ret = dp(t * m, 0);
    fout << ret << endl;
    return 0;
}
