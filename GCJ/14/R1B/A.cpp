#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

int run() {
    int n;
    cin >> n;
    vector<string> mm(n);
    REP(i,n) cin >> mm[i];

    int res = 0;
    while (true) {
        int emptyCnt = 0;
        REP(i,n) if (mm[i] == "") ++emptyCnt;
        if (emptyCnt == n) break;
        if (emptyCnt > 0) return -1;
        if (mm[0] == "") return -1;

        char ch = mm[0][0];
        vector<int> num(n);
        REP(i,n) {
            while (mm[i] != "" && mm[i][0] == ch) {
                ++num[i];
                mm[i] = mm[i].substr(1);
            }
            if (num[i] == 0) return -1;
        }
        sort(num.begin(), num.end());
        int tmp = -1;
        FOR(m,num.front(),num.back()) {
            int s = 0;
            REP(i,n) {
                s += abs(num[i] - m);
            }
            if ((tmp == -1) || (s < tmp)) tmp = s;
        }
        res += tmp;
    }

    return res;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        int res = run();
        if (res == -1) cout << "Fegla Won" << endl;
        else cout << res << endl;
    }
    return 0;
}
