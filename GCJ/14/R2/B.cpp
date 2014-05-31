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

void run() {
    int N;
    cin >> N;
    VI mm(N);
    REP(i,N) cin >> mm[i];
    int res = 0;
    REP(i,N) {
        int s1 = 0, s2 = 0;
        FOR(j,0,i-1) if (mm[j] > mm[i]) ++s1;
        FOR(j,i+1,N-1) if (mm[j] > mm[i]) ++s2;
        res += min(s1, s2);
    }
    cout << res << endl;
}

int main() {
    int nk;
    cin >> nk;
    FOR(c,1,nk) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
