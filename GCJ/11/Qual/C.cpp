#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

void run() {
    int N, mi = 1000000000, state = 0, total = 0;
    cin >> N;
    vector<int> mm(N);
    REP(i,N) {
        cin >> mm[i];
        mi = min(mi, mm[i]);
        total += mm[i];
        state ^= mm[i];
    }
    if (state != 0) cout << "NO" << endl;
    else cout << total - mi << endl;
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