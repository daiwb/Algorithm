#include <algorithm>
#include <iostream>
#include <iomanip>
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

class walkway {
public:
    int b, e, w, d;
    walkway(int bb, int ee, int ww) : b(bb), e(ee), w(ww) {
        d = e - b;
    }
};

bool cmp1(walkway w1, walkway w2) {
    return w1.b < w2.b;
}

bool cmp2(walkway w1, walkway w2) {
    return w1.w < w2.w;
}

void run() {
    int X, S, R, t, N;
    cin >> X >> S >> R >> t >> N;
    vector<walkway> mm;
    REP(i,N) {
        int B, E, w;
        cin >> B >> E >> w;
        mm.push_back(walkway(B, E, w + S));
    }
    sort(mm.begin(), mm.end(), cmp1);
    int len = mm.size();
    if (mm[0].b > 0) {
        mm.push_back(walkway(0, mm[0].b, S));
    }
    int next = 0;
    REP(i,len) {
        if (i == len - 1) next = X;
        else next = mm[i + 1].b;
        if (mm[i].e < next) {
            mm.push_back(walkway(mm[i].e, next, S));
        }
    }
    sort(mm.begin(), mm.end(), cmp2);
    double ret = 0.0, tmp = t;
    REP(i,mm.size()) {
        double dd = mm[i].d;
        double ts = mm[i].w + R - S;
        double tt = dd / ts;
        if (tt >= tmp) {
            ret += tmp;
            ret += (dd - ts * tmp) / mm[i].w;
            tmp = 0;
        } else {
            ret += tt;
            tmp -= tt;
        }
    }
    cout << setprecision(9) << ret << endl;
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
