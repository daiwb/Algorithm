#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

#define MAXN 64000000

LL mm[MAXN + 5];

int main() {
    memset(mm, 0, sizeof(mm));
    int u = (int) sqrt(MAXN + 0.0);
    FOR(i,1,u) {
        int i2 = i * i;
        mm[i2] += i2;
        int end = MAXN / i;
        int n = i2;
        FOR(j,i+1,end) {
            n += i;
            mm[n] += i2 + (LL)j * (LL)j;
        }
    }

    LL res = 0;
    FOR(n,1,MAXN-1) {
        LL nn = (LL) sqrt(mm[n] + 0.0);
        if (nn * nn == mm[n]) res += n;
    }
    cout << res << endl;
    return 0;
}

/*
#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

#define MAXN 64000000

int plist[2000],pcount=0;
int plist2[2000];

LL memo[2000][30];

int prime(int n){
	int i;
	if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
		return 0;
	for (i=0;plist[i]*plist[i]<=n;i++)
		if (!(n%plist[i]))
			return 0;
	return n>1;
}

void initprime(){
	int i;
	for (plist[pcount++]=2,i=3;i<=8000;i++)
		if (prime(i))
			plist[pcount++]=i;
    
    REP(i,pcount) {
        int p2 = plist[i] * plist[i];
        
        plist2[i] = p2;

        LL pp = p2, qq = 1;
        int m = 0;
        while (true) {
            if (qq >= MAXN) break;
            memo[i][m] = (pp - 1) / (p2 - 1);
            ++m;
            pp *= p2;
            qq *= plist[i];
        }
    }
}

LL mm[MAXN + 5];

int main() {
    memset(mm, 0, sizeof(mm));
    
    initprime();

    LL res = 0;
    
    FOR(n,1,MAXN-1) {
        if (n % 100000 == 0) cout << n << endl;
        mm[n] = 1;
        LL t = n;
        REP(i,pcount) {
            int p = plist[i];
            int p2 = plist2[i];
            if (p2 > t) break;
            int m = 0;
            while (t % p2 == 0) {
                m += 2;
                t /= p2;
            }
            if (t % p == 0) {
                ++m;
                t /= p;
            }

            mm[n] *= memo[i][m];
        }

        if (t > 1) mm[n] *= (1 + t * t);

        LL nn = (LL) sqrt(mm[n] + 0.0);
        if (nn * nn == mm[n]) res += n;
    }
    
    cout << res << endl;
    
    return 0;
}
*/
