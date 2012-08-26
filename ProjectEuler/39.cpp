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

int mm[1000];

void run() {
    memset(mm, 0, sizeof(mm));
    FOR(i,1,500) {
        FOR(j,i,500) {
            int k = (int) sqrt(i * i + j * j + 0.5);
            if (i * i + j * j != k * k) continue;
            if (i + j + k >= 1000) continue;
            mm[i + j + k] += 1;
        }
    }
    int idx = 0;
    FOR(i,1,999) {
        if (mm[i] > mm[idx]) idx = i;
    }
    cout << idx << endl;
}

int main() {
    run();
    return 0;
}
