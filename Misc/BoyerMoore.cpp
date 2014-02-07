#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

#define ALPHABET_SIZE 256

void CalBadChar(vector<vector<int> >& bc, string pattern, int m) {
    REP(i,m) {
        if (i == 0) {
            REP(j,ALPHABET_SIZE) bc[i][j] = -1;
        } else {
            bc[i] = bc[i - 1];
            bc[i][pattern[i - 1]] = i - 1;
        }
    }

    REP(i,m) {
        REP(j,ALPHABET_SIZE) {
            bc[i][j] = i - bc[i][j];
        }
    }
}

void CalGoodSuff(vector<int>& gs, string pattern, int m) {
    vector<int> suff(m);
    suff[m - 1] = m;
    RFOR(i,m-2,0) {
        int p1 = i, p2 = m - 1;
        while (p1 >= 0 && pattern[p1] == pattern[p2]) --p1, --p2;
        suff[i] = i - p1;
    }

    int idx = m;
    gs[m - 1] = 1;
    RFOR(p,m-2,0) {
        int len = m - 1 - p;
        if (pattern.substr(0, len) == pattern.substr(p + 1, len)) {
            idx = p + 1;
        }
        gs[p] = idx;
    }

    REP(p,m-1) {
        int len = suff[p];
        if (len == 0) continue;
        if (p < len || pattern[p - len] != pattern[m - 1 - len]) {
            gs[m - 1 - len] = m - 1 - p;
        }
    }
}

int BoyerMoore(string text, string pattern) {
    int n = text.length(), m = pattern.length();

    if (m == 0) return 0;
    if (n == 0) return -1;

    vector<vector<int> > bc(m, vector<int>(ALPHABET_SIZE));
    vector<int> gs(m);
    
    CalBadChar(bc, pattern, m);
    CalGoodSuff(gs, pattern, m);

    int pos = m - 1;
    while (pos < n) {
        int idx = m - 1, p = pos;
        while (idx >= 0 && text[p] == pattern[idx]) {
            --idx;
            --p;
        }

        if (idx < 0) return pos - (m - 1);
        
        pos += max(bc[idx][text[p]], gs[idx]);        
    }

    return -1;
}

int main() {
    string text, pattern;
    while (true) {
        cin >> text;
        cin >> pattern;
        int idx = BoyerMoore(text, pattern);
        cout << "idx = " << idx << endl;
        if (idx != -1) cout << text.substr(idx, pattern.length()) << endl;
    }

    return 0;
}

//abbadcababacab
//babac
//bcabcdababcabaabcbcabababacbacabeeacda
//bcababab
//dieiahgjkriabddioababa
//eigha
