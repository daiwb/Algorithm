#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > mm;
string strs, strp;
int lens, lenp;

int isok(int idxs, int idxp) {
    int& ret = mm[idxs][idxp];
    if (ret != -1) return ret;
    ret = 0;
    if (idxp == lenp) {
        if (idxs == lens) return ret = 1;
        else return ret;
    }
    if (strp[idxp] == '.') {
        if (idxp + 1 < lenp && strp[idxp + 1] == '*') {
            for (int i = idxs; i <= lens; ++i) {
                if (isok(i, idxp + 2)) {
                    return ret = 1;
                }
            }
        } else if (idxs < lens && isok(idxs + 1, idxp + 1)) {
            return ret = 1;
        }
    } else {
        if (idxp + 1 < lenp && strp[idxp + 1] == '*') {
            if (isok(idxs, idxp + 2)) {
                return ret = 1;
            }
            for (int i = idxs; i < lens; ++i) {
                if (strs[i] != strp[idxp]) break;
                if (isok(i + 1, idxp + 2)) {
                    return ret = 1;
                }
            }
        } else if (idxs < lens && strs[idxs] == strp[idxp] && isok(idxs + 1, idxp + 1)) {
            return ret = 1;
        }
    }
    return ret;
}

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        strs = string(s);
        strp = string(p);
        lens = strs.length();
        lenp = strp.length();
        mm.clear();
        mm.resize(lens + 5, vector<int>(lenp + 5, -1));
        return isok(0, 0) == 1;
    }
};

int main() {
    Solution s = Solution();
    cout << s.isMatch("aa", "a") << endl;
    cout << s.isMatch("aa", "aa") << endl;
    cout << s.isMatch("aaa", "aa") << endl;
    cout << s.isMatch("aa", "a*") << endl;
    cout << s.isMatch("aa", ".*") << endl;
    cout << s.isMatch("ab", ".*") << endl;
    cout << s.isMatch("aab", "c*a*b") << endl;
    return 0;
}
