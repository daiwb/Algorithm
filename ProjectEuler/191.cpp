#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

typedef long long LL;

#define MAXN 30

LL mm[MAXN + 1][2][2][2];

LL dp(int left, int late, int a, int b) {
    LL& ret = mm[left][late][a][b];
    if (ret != -1) return ret;

    if (left == 0) return ret = 1;

    ret = 0;

    if (late == 0) ret += dp(left - 1, 1, b, 0);

    if (a + b <= 1) ret += dp(left - 1, late, b, 1);

    ret += dp(left - 1, late, b, 0);

    return ret;
}

void run() {
    memset(mm, -1, sizeof(mm));
    cout << dp(MAXN, 0, 0, 0) << endl;
}

int main() {
    run();
}
