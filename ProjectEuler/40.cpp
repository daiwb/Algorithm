#include <iostream>
#include <sstream>
#include <cmath>
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

int doit(int n) {
    int m = 9;
    for (int i = 1; ; ++i) {
        if (n <= m * i) {
            int b = m / 9;
            int m = (n - 1) / i + b;
            int d = n % i;
            if (d == 0) d = i;
            string s = i2s(m);
            return s[d - 1] - '0';
        }
        n -= m * i;
        m *= 10;
    }

    return 0;
}

void run() {
    int res = 1;
    int n = 1;
    while (true) {
        res *= doit(n);
        n *= 10;
        if (n > 1000000) break;
    }
    cout << res << endl;
}

int main() {
    run();
    return 0;
}
