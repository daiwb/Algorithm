#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;

int A1, A2, B1, B2;

void run() {
    cin >> A1 >> A2 >> B1 >> B2;

    double f = (1.0 + sqrt(5.0)) / 2.0;

    LL ret = 0;
    
    FOR(b,B1,B2) {
        LL a1 = (LL) (b * f + 1);
        if (a1 < A1) ret += A2 - A1 + 1;
        else if (a1 <= A2) ret += A2 - a1 + 1;

        LL a2 = (LL) (b / f);
        if (a2 > A2) ret += A2 - A1 + 1;
        else if (a2 >= A1) ret += a2 - A1 + 1;
    }

    cout << ret << endl;
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
