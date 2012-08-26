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
#define SQR(x) ((x)*(x))
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

double GetR(double val) {
    return (val * rand()) / RAND_MAX;
}

void run() {
    int n, w, l;
    scanf("%d %d %d", &n, &w, &l);
    vector<pair<int, int> > r(n);
    REP(i,n) {
        scanf("%d", &r[i].first);
        r[i].second = i;
    }
    sort(r.begin(), r.end());
    reverse(r.begin(), r.end());
    vector<pair<double, double> > mm;
    REP(i,n) {
        while (true) {
            bool fl = true;
            double x = GetR(w);
            double y = GetR(l);
            FOR(j,0,i-1) {
                double len = hypot(x - mm[j].first, y - mm[j].second);
                if (len < r[i].first + r[j].first) {
                    fl = false;
                    break;
                }
            }
            if (fl) {
                mm.push_back(make_pair(x, y));
                break;
            }
        }
    }
    vector<pair<double, double> > res(n);
    REP(i,n) {
        res[r[i].second] = mm[i];
    }
    REP(i,n) {
        if (i) printf(" ");
        printf("%lf %lf", res[i].first, res[i].second);
    }
    printf("\n");
}

int main() {
    int k;
    scanf("%d", &k);
    FOR(c,1,k) {
        printf("Case #%d: ", c);
        run();
    }
    return 0;
}
