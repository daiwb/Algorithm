#include <iostream>
#include <sstream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;

string i2s(int n) {
    stringstream ss;
    ss << n;
    string res;
    ss >> res;
    return res;
}

LL s2ll(string str) {
    stringstream ss;
    ss << str;
    LL res;
    ss >> res;
    return res;
}

LL res;
int mm[10];

void doit(int n) {
    string s;
    for (int i = 1; ; ++i) {
        int t = n * i;
        s += i2s(t);
        if (s.length() >= 9) break;
    }

    if (s.length() > 9) return;

    memset(mm, 0, sizeof(mm));
    REP(i,9) {
        int c = s[i] - '0';
        if (c == 0) return;
        if (mm[c] == 1) return;
        mm[c] = 1;
    }

    LL m = s2ll(s);
    res = max(res, m);
}

void run() {
    FOR(i,1,9999) {
        doit(i);
    }
}

int main() {
    res = 0;
    run();
    cout << res << endl;
    return 0;
}
