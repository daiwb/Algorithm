#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

void run() {
    string str;
    cin >> str;
    int len = str.length();
    
    int res = 0;
    REP(i,len-res) {
        FOR(j,i+1,len-1-res) {
            int ct = 0;
            while (j + ct < len && str[i + ct] == str[j + ct]) ++ct;
            res = max(res, ct);
        }
    }

    cout << res << endl;
}

int main() {
    run();
    return 0;
}
