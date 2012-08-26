#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

typedef long long LL;

int plist[100000],pcount=0;
vector<LL> mm;

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
	for (plist[pcount++]=2,i=3;i<=1000000;i++)
		if (prime(i))
			plist[pcount++]=i;
    mm.clear();
    mm.push_back(1);
    REP(i,pcount) {
        LL t = 1LL * plist[i] * plist[i];
        while (t <= 1000000000000LL) {
            mm.push_back(t);
            t *= plist[i];
        }
    }
    sort(mm.begin(), mm.end());
    //REP(i,10) cout << mm[i] << endl;
}

void run() {
    LL n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    int l = 0, r = mm.size() - 1, m;
    while (true) {
        if (l == r) {
            m = l;
            break;
        }
        if (l + 1 == r) {
            if (mm[r] <= n) m = r;
            else m = l;
            break;
        }
        int m = (l + r) >> 1;
        //cout << l << " - " << r << " - " << m << endl;
        if (mm[m] > n) r = m - 1;
        else l = m;
    }
    cout << m + 1 << endl;
}

int main() {
    initprime();
    //cout << pcount << endl;
    //cout << plist[pcount - 1] << endl;
    int kase;
    cin >> kase;
    FOR(k,1,kase) {
        cout << "Case #" << k << ": ";
        run();
    }
    return 0;
}
