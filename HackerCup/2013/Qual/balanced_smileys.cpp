#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

string str;
int len;
int mm[105][105];

int dp(int st, int ed) {
    int& ret = mm[st][ed];
    if (ret != -1) return ret;

    if (st > ed) return ret = 1;

    FOR(i,st,ed) {
        if (str[i] == '(') {
            if (i - 1 >= st && str[i - 1] == ':') {
                if (dp(i + 1, ed) == 1) return ret = 1;
            }
            FOR(j,i+1,ed) {
                if (str[j] == ')') {
                    if (dp(i + 1, j - 1) == 1 && dp(j + 1, ed) == 1) return ret = 1;
                }
            }
            return ret = 0;
        } else if (str[i] == ')') {
            if (i - 1 >= st && str[i - 1] == ':') {
                return ret = dp(i + 1, ed);
            }
            return ret = 0;
        }
    }

    return ret = 1;
}

bool isvalid(char ch) {
    if ((ch >= 'a' && ch <= 'z') || ch == ' ' || ch == ':' || ch == '(' || ch == ')') return true;
    return false;
}

bool run() {
    REP(i,len) {
        if (!isvalid(str[i])) return false;
    }
    memset(mm, -1, sizeof(mm));
    int ret = dp(0, len - 1);
    return ret == 1;
}

int main() {
    int m;
    cin >> m;
    getline(cin, str);
    FOR(i,1,m) {
        cout << "Case #" << i << ": ";
        getline(cin, str);
        len = str.length();
        if (str.empty()) {
            cout << "YES" << endl;
            continue;
        }
        if (run()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
