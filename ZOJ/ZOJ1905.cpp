/*
  ZOJ 1905 Power Strings
  KMP
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

string str;

void run() {
    int len = str.length();
    vector<int> pi(len, -1);
    int k = -1;
    FOR(q,1,len-1) {
        while (k >= 0 && str[k + 1] != str[q]) k = pi[k];
        if (str[k + 1] == str[q]) ++k;
        pi[q] = k;
    }
    if (pi[len - 1] == -1) cout << 1 << endl;
    else {
        int d = len - 1 - pi[len - 1];
        if (len % d == 0) cout << len / d << endl;
        else cout << 1 << endl;
    }
}

int main() {
    while (cin >> str && str != ".") {
        run();
    }
    return 0;
}
