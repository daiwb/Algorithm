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

#define MAXN 1000000

int mm[MAXN + 5];
LL sum[MAXN + 5];
int cnt;

void run() {
    int res = 0;

    cnt = sum[0] = mm[0] = 0;
    while (true) {
        ++cnt;
        mm[cnt] = ((cnt << 1) - 1) << 2;
        sum[cnt] = sum[cnt - 1] + mm[cnt];
        if (mm[cnt] > MAXN) break;
    }

    FOR(i,2,cnt-1) {
        int l = 1, r = i-1, idx;
        while (true) {
            if (l == r) {
                idx = l;
                break;
            }
            if (l + 1 == r) {
                if (sum[i] - sum[l] <= MAXN) idx = l;
                else idx = r;
                break;
            }
            int mid = (l + r) >> 1;
            if (sum[i] - sum[mid] > MAXN) l = mid + 1;
            else r = mid;
        }
        res += i - idx;
    }

    cnt = sum[1] = mm[1] = 1;
    while (true) {
        ++cnt;
        mm[cnt] = ((cnt << 1) - 2) << 2;
        sum[cnt] = sum[cnt - 1] + mm[cnt];
        if (mm[cnt] > MAXN) break;
    }

    FOR(i,2,cnt-1) {
        int l = 1, r = i-1, idx;
        while (true) {
            if (l == r) {
                idx = l;
                break;
            }
            if (l + 1 == r) {
                if (sum[i] - sum[l] <= MAXN) idx = l;
                else idx = r;
                break;
            }
            int mid = (l + r) >> 1;
            if (sum[i] - sum[mid] > MAXN) l = mid + 1;
            else r = mid;
        }
        res += i - idx;
    }

    cout << res << endl;
}

int main() {
    run();
}
