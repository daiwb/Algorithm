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
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

#define MAXN 1000000

int mm[MAXN + 5];
LL sum[MAXN + 5];
int cc[MAXN + 5];
int cnt;

void run() {
    memset(cc, 0, sizeof(cc));

    cnt = sum[0] = mm[0] = 0;
    while (true) {
        ++cnt;
        mm[cnt] = ((cnt << 1) - 1) << 2;
        sum[cnt] = sum[cnt - 1] + mm[cnt];
        if (mm[cnt] > MAXN) break;
    }

    FOR(i,2,cnt-1) {
        RFOR(j,i-1,1) {
            if (sum[i] - sum[j] <= MAXN) cc[sum[i] - sum[j]] += 1;
            else break;
        }
    }

    cnt = sum[1] = mm[1] = 1;
    while (true) {
        ++cnt;
        mm[cnt] = ((cnt << 1) - 2) << 2;
        sum[cnt] = sum[cnt - 1] + mm[cnt];
        if (mm[cnt] > MAXN) break;
    }

    FOR(i,2,cnt-1) {
        RFOR(j,i-1,1) {
            if (sum[i] - sum[j] <= MAXN) cc[sum[i] - sum[j]] += 1;
            else break;
        }
    }

    int res = 0;
    FOR(i,1,MAXN) {
        if (cc[i] >= 1 && cc[i] <= 10) ++res;
    }
    cout << res << endl;
}

int main() {
    run();
}
