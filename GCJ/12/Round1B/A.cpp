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
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

void run() {
    int n;
    cin >> n;
    vector<int> s(n);
    int total = 0;
    REP(i,n) {
        cin >> s[i];
        total += s[i];
    }
    vector<double> mm(n);
    REP(i,n) {
        double lt = 0.0, rt = 1.0;
        while (true) {
            double mi = (lt + rt) / 2;
            if (fabs(lt - rt) < 1e-10) {
                mm[i] = mi;
                break;
            }
            double p = s[i] + total * mi;
            double t = 0.0;
            REP(j,n) {
                if (s[j] < p) t += (p - s[j]) / total;
            }
            if (t < 1.0) lt = mi;
            else rt = mi;
        }
    }
    //cout.precision(9);
    REP(i,n) {
        if (i) cout << " ";
        printf("%.8lf", mm[i] * 100.0);
        //cout << mm[i] * 100.0;
    }
    cout << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout <<  "Case #" << c << ": ";
        run();
    }
    return 0;
}
