#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;

#define MAXN 50

LL mm[MAXN + 1];

LL dp(int n) {
    LL& ret = mm[n];
    if (ret != -1) return ret;

    if (n == 0) return ret = 1;

    ret = dp(n - 1);

    FOR(i,2,4) {
        if (i > n) break;
        ret += dp(n - i);
    }

    return ret;
}

void run() {
    memset(mm, -1, sizeof(mm));
    cout << dp(MAXN) << endl;
}

int main() {
    run();
}
