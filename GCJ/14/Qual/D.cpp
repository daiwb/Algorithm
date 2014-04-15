#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

#define MAXN 1005
#define _clr(x) memset(x,0xff,sizeof(int)*MAXN)

int mt1[MAXN], mt2[MAXN], mat[MAXN][MAXN];

int hungary(int m,int n,int mat[][MAXN],int* mt1,int* mt2){
	int s[MAXN], t[MAXN], p, q, ret = 0;
    _clr(mt1);
    _clr(mt2);
    REP(i,m) {
        _clr(t);
		for (s[p=q=0]=i;p<=q&&mt1[i]<0;p++) {
            int k = s[p];
            REP(j,n) {
                if (mt1[i] >= 0) break;
				if (mat[k][j] && t[j]<0){
					s[++q] = mt2[j];
                    t[j] = k;
					if (s[q] < 0) {
						for (p = j; p >= 0; j = p) {
							mt2[j] = k = t[j];
                            p = mt1[k];
                            mt1[k] = j;
                        }
                    }
				}
            }
        }
        if (mt1[i] >= 0) ++ret;
    }
	return ret;
}

int doit1(vector<double> mm, vector<double> dd, int n) {
    REP(i,n) {
        REP(j,n) {
            if (mm[i] > dd[j]) mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }
    return hungary(n, n, mat, mt1, mt2);
}

int doit2(vector<double> mm, vector<double> dd, int n) {
    reverse(mm.begin(), mm.end());
    int win = 0;
    vector<int> used(n, false);
    REP(i,n) {
        bool found = false;
        int idx = -1;
        REP(j,n) {
            if (used[j]) continue;
            if (idx == -1) idx = j;
            if (dd[j] > mm[i]) {
                found = true;
                used[j] = true;
                break;
            }
        }
        if (!found) {
            ++win;
            used[idx] = true;
        }
    }
    return win;
}

void run() {
    int n;
    scanf("%d", &n);
    vector<double> mm(n), dd(n);
    REP(i,n) scanf("%llf", &mm[i]);
    REP(i,n) scanf("%llf", &dd[i]);
    sort(mm.begin(), mm.end());
    sort(dd.begin(), dd.end());
    printf("%d %d\n", doit1(mm, dd, n), doit2(mm, dd, n));
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
