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
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ ) {
        int m = atoi(tok[i].c_str());
        if (m != 2) res.push_back(m);
    }
    return res;
}

string str;

int vv[1005][15];
int q2[15];
int mask[1<<8];

int next(int n, int base) {
    int sum = 0;
    while (n) {
        int t = n % base;
        sum += q2[t];
        n /= base;
    }

    return sum;
}

bool ishappy(int n, int base) {
    vv[n][base] = 2;

    vector<int> dd;
    dd.push_back(n);

    int res = 1;

    while (true) {
        int sum = next(n, base);

        dd.push_back(sum);

        if (sum == 1) break;
        else if (vv[sum][base] == 1) break;
        else if (vv[sum][base] == 0) {
            res = 0;
            break;
        } else if (vv[sum][base] == 2) {
            res = 0;
            break;
        } else if (vv[sum][base] == -1) vv[sum][base] = 2;

        n = sum;
    }

    REP(i,dd.size()) {
        vv[dd[i]][base] = res;
    }

    return res;
}

void run() {
    getline(cin, str);
    vector<int> mm = splitInt(str);

    int s = 0;
    REP(i,mm.size()) {
        s |= (1 << (mm[i] - 3));
    }

    cout << mask[s] << endl;
}

void init() {
    memset(vv, -1, sizeof(vv));
    memset(mask, -1, sizeof(mask));
    FOR(i,0,9) q2[i] = i * i;
    int total = (1 << 8) - 1;
    
    FOR(s,1,total) {
        int n = 2;
        REP(i,8) {
            int t = s & ~(1 << i);
            if (t == s) continue;
            if (mask[t] == -1) continue;
            n = max(n, mask[t]);
        }

        while (true) {
            bool flag = true;

            REP(i,8) {
                if ((s & (1 << i)) == 0) continue;
                int t = next(n, i + 3);
                
                if (t == 1) continue;

                if (vv[t][i + 3] == 1) continue;
                else if (vv[t][i + 3] == 0) {
                    flag = false;
                    break;
                }
                if (!ishappy(t, i + 3)) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                mask[s] = n;
                break;
            }

            ++n;
        }
    }
}

int main() {
    init();

    int T;
    cin >> T;
    getline(cin, str);
    FOR(k,1,T) {
        cout << "Case #" << k << ": ";
        run();
    }
    return 0;
}
