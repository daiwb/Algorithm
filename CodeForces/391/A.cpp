#include <iostream>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

int main() {
    string str;
    cin >> str;
    int n = 1, res = 0;
    char ch = str[0];
    FOR(i,1,str.length()-1) {
        if (str[i] == ch) ++n;
        else {
            if ((n & 1) == 0) ++res;
            n = 1;
            ch = str[i];
        }
    }
    if ((n & 1) == 0) ++res;
    cout << res << endl;
    return 0;
}
