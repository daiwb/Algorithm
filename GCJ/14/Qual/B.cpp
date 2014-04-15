#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

void run() {
    double C, F, X;
    cin >> C >> F >> X;
    double res = X / 2.0, now = 0.0, rate = 2.0;
    while (now < res) {
        now += C / rate;
        rate += F;
        res = min(res, now + X / rate);
    }
    cout.precision(7);
    cout.setf(ios::fixed, ios::floatfield);
    cout << res << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
