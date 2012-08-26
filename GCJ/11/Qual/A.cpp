#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

void run() {
    int N, current_o = 1, current_b = 1, time_o = 0, time_b = 0;
    cin >> N;
    REP(i,N) {
        char ch;
        int p;
        cin >> ch >> p;
        if (ch == 'O') {
            time_o += abs(p - current_o) + 1;
            time_o = max(time_o, time_b + 1);
            current_o = p;
        } else {
            time_b += abs(p - current_b) + 1;
            time_b = max(time_b, time_o + 1);
            current_b = p;
        }
    }
    cout << max(time_o, time_b) << endl;
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
