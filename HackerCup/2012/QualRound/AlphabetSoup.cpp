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

string str;
map<char, int> mp;
string hackcup = "HACKERCUP";

void run() {
    getline(cin, str);
    mp.clear();
    REP(i,26) {
        mp[char('A' + i)] = 0;
    }
    REP(i,str.length()) {
        mp[str[i]] += 1;
    }
    int ret = str.length();
    REP(i,hackcup.length()) {
        if (hackcup[i] == 'C') ret = min(ret, mp[hackcup[i]] / 2);
        else ret = min(ret, mp[hackcup[i]]);
    }
    cout << ret << endl;
}

int main() {
    int kase;
    cin >> kase;
    getline(cin, str);
    FOR(k,1,kase) {
        cout << "Case #" << k << ": ";
        run();
    }
    return 0;
}
