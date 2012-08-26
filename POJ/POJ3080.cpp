/*
  POJ 3080 Blue Jeans
  KMP
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

vector<int> pi;

void build(string pattern) {
    int lp = pattern.length();
    pi.assign(lp, -1);
    vector<int> pi(lp, -1);
    int k = -1;
    FOR(q,1,lp-1) {
        while (k >= 0 && pattern[k + 1] != pattern[q]) k = pi[k];
        if (pattern[k + 1] == pattern[q]) ++k;
        pi[q] = k;
    }
}

bool StringMatchKMP(string text, string pattern) {
    int lt = text.length(), lp = pattern.length();
    int k = -1;
    REP(i,lt) {
        while (k >= 0 && pattern[k + 1] != text[i]) k = pi[k];
        if (pattern[k + 1] == text[i]) ++k;
        if (k == lp - 1) return true;
    }
    return false;
}

void run() {
    int n;
    cin >> n;
    vector<string> mm(n);
    REP(i,n) cin >> mm[i];
    RFOR(len,60,3) {
        string seq = "";
        REP(i,60-len+1) {
            string pat = mm[0].substr(i,len);
            build(pat);
            bool match = true;
            FOR(j,1,n-1) {
                if (!StringMatchKMP(mm[j], pat)) {
                    match = false;
                    break;
                }
            }
            if (match) {
                if (seq == "" || pat < seq) seq = pat;
            }
        }
        if (seq != "") {
            cout << seq << endl;
            return;
        }
    }
    cout << "no significant commonalities" << endl;
}

int main() {
    int kase;
    cin >> kase;
    while (kase--) {
        run();
    }
    return 0;
}
