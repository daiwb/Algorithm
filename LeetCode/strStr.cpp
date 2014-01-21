#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int n = strlen(haystack);
        int m = strlen(needle);

        if (m == 0) return haystack;

        vector<int> pi(m, -1);
        int k = -1;
        FOR(q,1,m-1) {
            while (k >= 0 && needle[k + 1] != needle[q]) k = pi[k];
            if (needle[k + 1] == needle[q]) ++k;
            pi[q] = k;
        }

        k = -1;
        REP(i,n) {
            while (k >= 0 && needle[k + 1] != haystack[i]) k = pi[k];
            if (needle[k + 1] == haystack[i]) ++k;
            if (k == m - 1) return haystack + i - m + 1;
        }

        return NULL;
    }
};

int main() {
    char pattern[] = "afds";
    char text[] = "";
    Solution s = Solution();
    char *ret = s.strStr(text, pattern);
    if (ret == NULL) cout << "NULL" << endl;
    else {
        int m = strlen(pattern);
        REP(i,m) cout << ret[i];
        cout << endl;
    }
    return 0;
}
