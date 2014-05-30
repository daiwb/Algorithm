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
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
#define MP make_pair
#define MPI make_pair<int, int>
#define PB push_back
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PI;

class Solution {
public:
    bool isok2(string str) {
        if (str.length() == 0) return false;
        REP(i,str.length()) {
            if (!(str[i] >= '0' && str[i] <= '9')) return false;
        }
        return true;
    }
    bool isok(string str) {
        int idx = -1;
        REP(i,str.length()) {
            if (str[i] == '.') {
                if (idx == -1) idx = i;
                else idx = -2;
            }
        }
        if (idx == -2) return false;
        if (idx == -1) return isok2(str);
        if (str.length() == 1) return false;
        return (idx == 0 || isok2(str.substr(0, idx))) && (idx == str.length() - 1 || isok2(str.substr(idx + 1)));
    }
    bool isNumber(const char *s) {
        string str = string(s);
        while (str.length() > 0 && str[0] == ' ') str.erase(str.begin(), str.begin() + 1);
        while (str.length() > 0 && str[str.length() - 1] == ' ') str.erase(str.end() - 1);
        if (str.length() > 0 && (str[0] == '-' || str[0] == '+')) str.erase(str.begin(), str.begin() + 1);
        int idx = -1;
        REP(i,str.length()) {
            if (str[i] == 'e' || str[i] == 'E') {
                if (idx == -1) idx = i;
                else idx = -2;
            }
        }
        if (idx == -2) return false;
        if (idx == -1) return isok(str);
        FOR(i,idx+1,str.length()-1) {
            if (str[i] == '.') return false;
        }
        if (idx + 1 < str.length() && (str[idx + 1] == '+' || str[idx + 1] == '-')) str.erase(str.begin() + idx + 1, str.begin() + idx + 2);
        return isok(str.substr(0, idx)) && isok(str.substr(idx + 1));
    }
};

int main() {
    Solution s = Solution();
    cout << s.isNumber("0") << endl;
    cout << s.isNumber(" 0.1 ") << endl;
    cout << s.isNumber("abc") << endl;
    cout << s.isNumber("1 a") << endl;
    cout << s.isNumber("2e10") << endl;
    cout << s.isNumber(".1") << endl;
    cout << s.isNumber("3.") << endl;
    cout << s.isNumber(".") << endl;
    cout << s.isNumber("+.8") << endl;
    cout << s.isNumber("6e6.5") << endl;
    cout << s.isNumber(" 005047e+6") << endl;
    return 0;
}
