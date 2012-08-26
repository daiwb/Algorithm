#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

int s2i(string s) {
    stringstream ss;
    ss << s;
    int res;
    ss >> res;
    return res;
}

string i2s(int n) {
    stringstream ss;
    ss << n;
    string res;
    ss >> res;
    return res;
}

int v[2000005];

void run() {
    int A, B;
    cin >> A >> B;
    memset(v, 0, sizeof(v));
    int ret = 0;
    string sa = i2s(A), sb = i2s(B);
    FOR(n,A,B) {
        if (v[n] == 1) continue;
        string str = i2s(n);
        int len = str.length();
        int cnt = 0;
        REP(i,len) {
            if (str[i] < sa[0] || str[i] > sb[0]) continue;
            string ts = str.substr(i) + str.substr(0, i);
            int ti = s2i(ts);
            if (ti >= A && ti <= B) {
                if (v[ti] == 0) {
                    ++cnt;
                    v[ti] = 1;
                } else break;
            }
        }
        if (cnt >= 2) ret += cnt * (cnt - 1) / 2;
    }
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
