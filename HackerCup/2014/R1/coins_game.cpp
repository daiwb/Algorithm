#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

void run() {
    int n, k, c;
    cin >> n >> k >> c;
    int avg = k / n;
    int ret = c;
    if (avg * n < c) ret += n - k / (avg + 1);
    cout << ret << endl;
}

int main() {
    int T;
    cin >> T;
    FOR(t,1,T) {
        cout << "Case #" << t << ": ";
        run();
    }
    return 0;
}
