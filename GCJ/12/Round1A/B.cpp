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
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

vector<int> r1, r2, vv;

void run() {
    int n;
    cin >> n;
    vector<int> r1(n), r2(n), vv(n, 0);
    vector<pair<int, int> > pp;
    REP(i,n) {
        int t1, t2;
        cin >> t1 >> t2;
        pp.push_back(make_pair(-t2, t1));
    }
    sort(pp.begin(), pp.end());
    REP(i,n) {
        r1[i] = pp[i].second;
        r2[i] = -pp[i].first;
    }
    int cur = 0, res = 0;
    while (true) {
        bool fl = false;

        REP(i,n) {
            if (vv[i] == 0 && cur >= r2[i]) {
                cur += 2;
                ++res;
                fl = true;
                vv[i] = 2;
            }
        }
        if (fl) continue;

        REP(i,n) {
            if (vv[i] == 1 && cur >= r2[i]) {
                cur += 1;
                ++res;
                fl = true;
                vv[i] = 2;
                break;
            }
        }
        if (fl) continue;

        REP(i,n) {
            if (vv[i] == 0 && cur >= r1[i]) {
                cur += 1;
                ++res;
                fl = true;
                vv[i] = 1;
                break;
            }
        }
        if (fl) continue;

        break;
    }

    if (cur == (n << 1)) cout << res << endl;
    else cout << "Too Bad" << endl;
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
