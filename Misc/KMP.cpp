#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

vector<int> StringMatchKMP(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    // pi[q] = max { k : k < q and Pk is a suffix of Pq }
    vector<int> pi(m, -1);
    int k = -1;
    FOR(q,1,m-1) {
        while (k >= 0 && pattern[k + 1] != pattern[q]) k = pi[k];
        if (pattern[k + 1] == pattern[q]) ++k;
        pi[q] = k;
    }

    vector<int> res;
    k = -1;
    REP(i,n) {
        while (k >= 0 && pattern[k + 1] != text[i]) k = pi[k];
        if (pattern[k + 1] == text[i]) ++k;
        if (k == m - 1) {
            res.push_back(i - m + 1);
            k = pi[k];
        }
    }
    return res;
}
