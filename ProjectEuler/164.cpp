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

LL mm[25][10][10];

LL dp(int left, int a, int b) {
    LL& ret = mm[left][a][b];
    if (ret != -1) return ret;

    if (left == 0) return ret = 1;

    ret = 0;
    FOR(i,0,9-a-b) ret += dp(left - 1, b, i);

    return ret;
}

void run() {
    memset(mm, -1, sizeof(mm));
    LL res = 0;
    FOR(i,1,9) {
        FOR(j,0,9-i) {
            res += dp(18, i, j);
        }
    }
    cout << res << endl;
}

int main() {
    run();
}
