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
#define INF 1000000000;
typedef long long LL;

LL N, M;
LL x1, a1, b1, c1, r1;
LL x2, a2, b2, c2, r2;
LL bd1[1000005];
LL bd2[1000005];

LL run() {
    cin >> N >> M;
    cin >> x1 >> a1 >> b1 >> c1 >> r1;
    cin >> x2 >> a2 >> b2 >> c2 >> r2;

    bd1[0] = x1;
    bd2[0] = x2;
    LL mx = max(N - 1, M - 1);
    FOR(i,1,mx) {
        if (i <= N - 1) {
            bd1[i] = (a1 * bd1[(i - 1) % N] + b1 * bd2[(i - 1) % M] + c1) % r1;
        }
        if (i <= M - 1) {
            bd2[i] = (a2 * bd1[(i - 1) % N] + b2 * bd2[(i - 1) % M] + c2) % r2;
        }
    }

    map<LL, int> mp1;
    map<LL, int> mp2;
    int idx1 = 0, idx2 = 0;
    LL ret = 0;
    while (idx1 < N && idx2 < M) {
        LL v1 = bd1[idx1];
        LL v2 = bd2[idx2];
        
        mp1[v1] = 1;
        mp2[v2] = 1;
        
        deque<LL> need1, need2;
        if (mp2.find(v1) == mp2.end()) need2.push_back(v1);
        if (mp1.find(v2) == mp1.end()) need1.push_back(v2);
        
        while (!need1.empty() || !need2.empty()) {
            while (!need1.empty()) {
                LL t = need1.front();
                if (mp1.find(t) != mp1.end()) {
                    need1.pop_front();
                    continue;
                }
                while (true) {
                    ++idx1;
                    if (idx1 == N) return ret;
                    LL tv = bd1[idx1];
                    mp1[tv] = 1;
                    if (tv == t) {
                        need1.pop_front();
                        break;
                    }
                    if (mp2.find(tv) == mp2.end()) need2.push_back(tv);
                }
            }
            while (!need2.empty()) {
                LL t = need2.front();
                if (mp2.find(t) != mp2.end()) {
                    need2.pop_front();
                    continue;
                }
                while (true) {
                    ++idx2;
                    if (idx2 == M) return ret;
                    LL tv = bd2[idx2];
                    mp2[tv] = 1;
                    if (tv == t) {
                        need2.pop_front();
                        break;
                    }
                    if (mp1.find(tv) == mp1.end()) need1.push_back(tv);
                }
            }
        }

        LL c1 = 1, c2 = 1;
        while (idx1 < N - 1 && mp1.find(bd1[idx1 + 1]) != mp1.end()) {
            ++idx1;
            ++c1;
        }
        while (idx2 < M - 1 && mp2.find(bd2[idx2 + 1]) != mp2.end()) {
            ++idx2;
            ++c2;
        }
        ret += c1 * c2;

        ++idx1;
        ++idx2;
    }

    return ret;
}

int main() {
    int kase;
    cin >> kase;
    FOR(k,1,kase) {
        cout << "Case #" << k << ": ";
        cout << run() << endl;
    }
    return 0;
}
