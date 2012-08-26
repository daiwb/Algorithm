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
int len;

LL dp(int n) {
    LL& ret = mm[n];
    if (ret != -1) return ret;

    if (n == 0) return ret = 1;

    ret = dp(n - 1);

    if (n >= len) ret += dp(n - len);

    return ret;
}

void run() {
    LL res = 0;
    for (len = 2; len <= 4; ++len) {
        memset(mm, -1, sizeof(mm));
        res += dp(MAXN) - 1;
    }
    cout << res << endl;
}

int main() {
    run();
}
