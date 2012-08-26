#include <iostream>
#include <algorithm>
#include <vector>
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

int res;

bool isPrime(int n) {
    int mid = (int) sqrt(n + 0.5);
    for (int i = 3; i <= mid; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void doit(int n) {
    vector<int> mm;
    FOR(i,1,n) mm.push_back(i);
    do {
        if ((mm[n - 1] & 1) == 0 || mm[n - 1] == 5) continue;
        int t = 0;
        REP(i,n) t = t * 10 + mm[i];
        if (isPrime(t)) res = max(res, t);
    } while (next_permutation(mm.begin(), mm.end()));
}

void run() {
    res = 2143;
    doit(4);
    doit(7);
    doit(8);
    cout << res << endl;
}

int main() {
    run();
    return 0;
}
