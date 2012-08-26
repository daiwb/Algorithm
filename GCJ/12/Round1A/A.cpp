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
    int A, B;
    scanf("%d %d", &A, &B);
    vector<double> P(A);
    REP(i,A) scanf("%lf", &P[i]);

    double res = 1 + B + 1;
    double pro = 1.0;
    FOR(cnt,0,A) {
        int c1 = A - cnt + B - cnt + 1;
        int c2 = c1 + B + 1;
        double exp = pro * c1 + (1.0 - pro) * c2;
        res = min(res, exp);
        pro *= P[cnt];
    }
    printf("%.7lf\n", res);
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
