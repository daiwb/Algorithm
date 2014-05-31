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

#pragma warning(disable: 4996)

void run() {
    int X, N;
    scanf("%d %d", &N, &X);
    vector<int> mm(N);
    REP(i,N) scanf("%d", &mm[i]);

    int res = 0;
    
    sort(mm.begin(), mm.end());
    while (!mm.empty()) {
        if (mm.size() == 1) {
            ++res;
            break;
        }

        ++res;
        int rt = mm.back();
        mm.pop_back();
        int v = X - rt;
        if (mm.front() > v) continue;

        int lp = 0;
        int rp = mm.size() - 1;
        while (lp <= rp) {
            int mp = (lp + rp) / 2;
            if (mm[mp] > v) rp = mp - 1;
            else lp = mp + 1;
        }

        if (rp != -1) {
            mm.erase(mm.begin() + rp, mm.begin() + rp + 1);
        }
    }

    printf("%d\n", res);
}

int main() {
    int nk;
    scanf("%d", &nk);
    FOR(c,1,nk) {
        printf("Case #%d: ", c);
        run();
    }
    return 0;
}
