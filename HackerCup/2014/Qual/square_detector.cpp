#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

int n;

bool run() {
    vector<pair<int, int> > mm;
    cin >> n;
    string str;
    REP(i,n) {
        cin >> str;
        REP(j,n) {
            if (str[j] == '#') mm.push_back(make_pair(i, j));
        }
    }
    int m = mm.size();
    if (m <= 1) return true;
    int q = sqrt(m + 0.5);
    if (q * q != m) {
        return false;
    }
    int idx = 0, sx = mm[0].first, sy = mm[0].second;
    REP(i,q) {
        REP(j,q) {
            if (mm[idx].first != sx + i || mm[idx].second != sy + j) return false;
            ++idx;
        }
    }
    return true;
}

int main() {
    int kase;
    cin >> kase;
    FOR(i,1,kase) {
        cout << "Case #" << i << ": ";
        if (run()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
