#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define INF 1000000000;

int plist[10000],pcount=0;

int prime(int n){
	int i;
	if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
		return 0;
	for (i=0;plist[i]*plist[i]<=n;i++)
		if (!(n%plist[i]))
			return 0;
	return n>1;
}

vector<int> p1, p2, st;

void initprime(){
	int i;
	for (plist[pcount++]=2,i=3;i<50000;i++)
		if (prime(i))
			plist[pcount++]=i;
    REP(i,pcount) {
        if (plist[i] <= 50) p1.push_back(plist[i]);
        else {
            p2.push_back(plist[i]);
            if (p2.size() >= 20) break;
        }
    }
    int mx = p2.back();
    st.assign(mx + 1, 0);
    REP(i,p1.size()) {
        int p = p1[i];
        while (p <= mx) {
            st[p] |= (1 << i);
            p += p1[i];
        }
    }
    FOR(i,2,mx) {
        int t = i;
        REP(j,p1.size()) {
            while ((t % p1[j]) == 0) t /= p1[j];
        }
        if (t > 1) st[i] = -1;
    }
}

int N, K;
int A[20];
int mm[20][1 << 15];

int dp(int idx, int mask) {
    if (idx >= N) return 0;

    int& ret = mm[idx][mask];
    if (ret != -1) return ret;

    ret = INF;
    FOR(i,A[idx],p2.back()) {
        if (st[i] == -1) continue;
        if (mask & st[i]) continue;
        ret = min(ret, dp(idx + 1, mask | st[i]) + i * K);
    }

    int tmp = 0;
    REP(i,N-idx) tmp += p2[i];

    ret = min(ret, tmp * K);

    return ret;
}

void run() {
    cin >> N >> K;
    int s = 0;
    REP(i,N) {
        cin >> A[i];
        s += A[i];
    }
    sort(A, A + N);
    FOR(i,1,N-1) {
        if (A[i] == 0) A[i] = 1;
        else break;
    }
    REP(i,N) A[i] = (A[i] + K - 1) / K;
    if (A[0] == 0) {
        if (A[N - 1] <= 1) {
            cout << K * (N - 1) - s << endl;
            return;
        } else {
            A[0] = 1;
        }
    }
    if (A[0] == 1 && A[N - 1] == 1) {
        cout << K * N - s << endl;
        return;
    }

    memset(mm, -1, sizeof(mm));
    int start = 0, add = 0;
    while (A[start] == 1) {
        add += K;
        ++start;
    }
    int ret = dp(start, 0);
    cout << ret + add - s << endl;
}

int main() {
    initprime();
    int kase;
    cin >> kase;
    FOR(k,1,kase) {
        cout << "Case #" << k << ": ";
        run();
    }
    return 0;
}
