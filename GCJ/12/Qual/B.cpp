#include <iostream>
#include <string>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

void run() {
    int n, s, p, m, ret = 0, t = 0;
    cin >> n >> s >> p;
    int a = p + max(0, p - 1) * 2, b = p + max(0, p - 2) * 2;
    REP(i,n) {
        cin >> m;
        if (m >= a) ++ret;
        else if (m >= b) ++t;
    }
    ret += min(s, t);
    cout << ret << endl;
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
