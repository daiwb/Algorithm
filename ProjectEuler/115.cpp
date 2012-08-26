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

#define MILLION 1000000
#define MAXN 1000
#define START 50

LL mm[MAXN + 1];

LL dp(int n) {
    LL& ret = mm[n];
    if (ret != -1) return ret;

    if (n == 0) return ret = 1;

    ret = dp(n - 1);

    if (n >= START) ++ret;
    FOR(i,START,n-1) ret += dp(n - i - 1);

    return ret;
}

void run() {
    memset(mm, -1, sizeof(mm));
    FOR(i,3,MAXN) {
        LL t = dp(i);
        if (t >= MILLION) {
            cout << i << endl;
            break;
        }
    }
}

int main() {
    run();
}
