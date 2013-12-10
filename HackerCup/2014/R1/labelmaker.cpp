#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;

void run() {
    string letters;
    LL n;
    cin >> letters >> n;
    int len = letters.length();
    string ret = "";
    while (n > 0) {
        ret = letters[--n % len] + ret;
        n /= len;
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
