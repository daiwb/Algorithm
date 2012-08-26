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
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;

#define MOD 4207849484LL

int M, len;
string status;

LL mm[1005];

LL dp(int idx) {
    LL& ret = mm[idx];
    if (ret != -1) return ret;
    if (idx >= len) return ret = 1;
    ret = 0;
    LL tmp = 0;
    FOR(i,idx,len-1) {
        tmp = tmp * 10 + status[i] - '0';
        if (tmp < 1 || tmp > M) break;
        ret = (ret + dp(i + 1)) % MOD;
    }
    return ret;
}

void run() {
    cin >> M >> status;
    len = status.length();
    REP(i,1005) mm[i] = -1;
    LL ret = dp(0);
    cout << ret << endl;
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
