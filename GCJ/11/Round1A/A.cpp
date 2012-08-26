#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

int gcd(int a, int b) {
    while (a != 0) {
        b %= a;
        a ^= b ^= a ^= b;
    }
    return b;
}

void run() {
    long long N, Pd, Pg;
    cin >> N >> Pd >> Pg;
    if (Pg == 0 || Pg == 100) {
        if (Pd == Pg) cout << "Possible" << endl;
        else cout << "Broken" << endl;
        return;
    }
    int g = gcd(100, Pd);
    int D = 100 / g;
    if (D <= N) cout << "Possible" << endl;
    else cout << "Broken" << endl;
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
