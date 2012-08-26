#include <iostream>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

void run() {
    int n, k;
    cin >> n >> k;
    int m = (1 << n) - 1;
    if ((m & k) == m) cout << "ON" << endl;
    else cout << "OFF" << endl;
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
