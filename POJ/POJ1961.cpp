/*
  POJ 1961 Period
  KMP
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

int len;
string str;

void run() {
    vector<int> pi(len, -1);
    int k = -1;
    FOR(q,1,len-1) {
        while (k >= 0 && str[k + 1] != str[q]) k = pi[k];
        if (str[k + 1] == str[q]) ++k;
        pi[q] = k;
    }
    REP(i,len) {
        if (pi[i] == -1) continue;
        else {
            int d = i - pi[i];
            if ((i + 1) % d == 0) cout << i + 1 << " " << (i + 1) / d << endl;
        }
    }
}

int main() {
    int kase = 1;
    while (cin >> len && len != 0) {
        cin >> str;
        cout << "Test case #" << kase++ << endl;
        run();
        cout << endl;
    }
    return 0;
}
