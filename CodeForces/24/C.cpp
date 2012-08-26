#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
typedef long long LL;

void run() {
    LL n, idx;
    cin >> n >> idx;
    LL mx, my;
    vector<LL> xx(n), yy(n);
    cin >> mx >> my;
    REP(i,n) cin >> xx[i] >> yy[i];

    idx %= (n << 1);
    REP(i,idx) {
        int ii = (i % n);
        mx = (xx[ii] << 1) - mx;
        my = (yy[ii] << 1) - my;
    }

    cout << mx << " " << my << endl;
}

int main() {
    run();
    return 0;
}
