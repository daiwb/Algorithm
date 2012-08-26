#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

int W, H;
string text;
vector<string> mm;

bool isok(int s) {
    int mx = H / s, c = 1, t = 0;
    REP(i,mm.size()) {
        int len = mm[i].length() * s;
        int add = len;
        if (i != 0) add += s;
        if (t + add <= W) t += add;
        else {
            if (len > W) return false;
            ++c;
            if (c > mx) return false;
            t = len;
        }
    }
    return true;
}

void run() {
    cin >> W >> H;
    getline(cin, text);
    mm = split(text, " ");
    int l = 1, r = min(W, H);
    while (l <= r) {
        int m = (l + r) / 2;
        if (isok(m)) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << l - 1 << endl;
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
