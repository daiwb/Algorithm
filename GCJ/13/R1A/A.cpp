#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;

LL A, N, ret;
LL mm[105];

void run() {
    cin >> A >> N;
    REP(i,N) cin >> mm[i];
    if (A == 1) {
        cout << N << endl;
        return;
    }
    sort(mm, mm + N);
    ret = N;
    LL cur = A, num = 0;
    REP(i,N) {
        if (num >= ret) break;
        ret = min(ret, num + N - i);
        while (cur <= mm[i]) {
            cur += cur - 1;
            ++num;
        }
        cur += mm[i];
    }
    ret = min(ret, num);
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
