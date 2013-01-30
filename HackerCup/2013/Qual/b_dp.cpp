#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

string str;
int len;
int mm[105][105];

bool isvalid(char ch) {
    if ((ch >= 'a' && ch <= 'z') || ch == ' ' || ch == ':' || ch == '(' || ch == ')') return true;
    return false;
}

bool run() {
    REP(i,len) {
        if (!isvalid(str[i])) return false;
    }
    REP(i,105) {
        REP(j,105) {
            mm[i][j] = 1;
        }
    }
    REP(i,len) {
        if (str[i] == '(' || str[i] == ')') mm[i][i] = 0;
    }
    FOR(step,2,len) {
        FOR(st,0,len-1) {
            int ed = st + step - 1;
            if (ed >= len) break;

            bool fl = true;
            FOR(i,st,ed) {
                if (str[i] == '(') {
                    fl = false;
                    if (i - 1 >= st && str[i - 1] == ':') {
                        if (mm[i + 1][ed] == 1) {
                            fl = true;
                            break;
                        }
                    }
                    FOR(j,i+1,ed) {
                        if (str[j] == ')') {
                            if (mm[i + 1][j - 1] == 1 && mm[j + 1][ed] == 1) {
                                fl = true;
                                break;
                            }
                        }
                    }
                    break;
                } else if (str[i] == ')') {
                    fl = false;
                    if (i - 1 >= st && str[i - 1] == ':') {
                        if (mm[i + 1][ed] == 1) fl = true;
                    }
                    break;
                }
            }
            if (!fl) mm[st][ed] = 0;
        }
    }
    return mm[0][len - 1] == 1;
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
