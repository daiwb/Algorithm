#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

int s2i(string s) {
    stringstream ss;
    ss << s;
    int res;
    ss >> res;
    return res;
}

string i2s(int n) {
    stringstream ss;
    ss << n;
    string res;
    ss >> res;
    return res;
}

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        REP(i,n-1) {
            s += "0";
            string t = "";
            int len = s.length();
            char last = '0';
            int cnt = 0;
            REP(j,len) {
                if (s[j] != last) {
                    if (cnt != 0) {
                        t += i2s(cnt);
                        t += last;
                    }
                    last = s[j];
                    cnt = 1;
                    
                } else {
                    ++cnt;
                }
            }
            s = t;
        }
        return s;
    }
};

int main() {
    Solution s;
    FOR(i,1,5) {
        cout << s.countAndSay(i) << endl;
    }
    return 0;
}
