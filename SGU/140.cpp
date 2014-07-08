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
typedef long long LL;
typedef vector<long long> VI;

LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}

LL ext_gcd(LL a,LL b,LL& x,LL& y){
	LL t,ret;
	if (!b){
		x=1,y=0;
		return a;
	}
	ret=ext_gcd(b,a%b,x,y);
	t=x,x=y,y=t-a/b*y;
	return ret;
}

int main() {
    int n, p, b;
    cin >> n >> p >> b;
    VI a(n);
    LL g = p;
    REP(i,n) {
        cin >> a[i];
        g = gcd(g, a[i]);
    }

    if (b % g != 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        VI mod(n), x(n);
        mod[0] = p;
        FOR(i,1,n-1) mod[i] = gcd(mod[i - 1], a[i - 1]);

        LL tmp;
        RFOR(i,n-1,0) {
            LL ret = ext_gcd(a[i], mod[i], x[i], tmp);
            x[i] *= b / ret;
            x[i] = (x[i] % p + p) % p;
            b = ((b - a[i] * x[i]) % p + p) % p;
        }

        REP(i,n) {
            if (i) cout << " ";
            cout << x[i];
        }
        cout << endl;
    }
    return 0;
}
