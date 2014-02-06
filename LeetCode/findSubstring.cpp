#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int n = L.size(), len = L[0].length();
        map<string, int> mm;
        map<string, int> t;
        REP(i,n) {
            if (mm.find(L[i]) == mm.end()) mm[L[i]] = 1;
            else ++mm[L[i]];
        }

        vector<int> ret;
        RFOR(pos,S.length() - n * len, 0) {
            t.clear();
            bool isok = true;
            for (int i = (n - 1) * len; i >= 0; i -= len) {
                string str = S.substr(i + pos, len);
                if (mm.find(str) == mm.end()) {
                    isok = false;
                    break;
                }
                ++t[str];
                if (t[str] > mm[str]) {
                    isok = false;
                    break;
                }
            }
            if (isok) ret.push_back(pos);
        }

        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<string> L;
    L.push_back("a");
    L.push_back("b");
    L.push_back("a");
    vector<int> ret = s.findSubstring("abababab", L);
    REP(i,ret.size()) cout << ret[i] << endl;
    return 0;
}
