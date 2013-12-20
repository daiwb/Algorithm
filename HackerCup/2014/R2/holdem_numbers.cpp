#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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
#include <ctime>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define INF 1000000000;
typedef long long LL;

int N, H, C1, C2;

vector<pair<int, int> > ans;

void showtime() {
    time_t now = time(0);
   
   // convert now to string form
   char* dt = ctime(&now);

   cout << "The local date and time is: " << dt << endl;

   // convert now to tm struct for UTC
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "The UTC date and time is:"<< dt << endl;
}

int isok(int n, int c1, int c2) {
    LL sum = 0;
    int s = c1 + c2;
    FOR(b1,1,n) {
        if (b1 == c1 || b1 == c2) continue;
        FOR(b2,b1+1,n) {
            if (b2 == c1 || b2 == c2) continue;
            FOR(b3,b2+1,n) {
                if (b3 == c1 || b3 == c2) continue;

                int m1 = min(b1 - 1, s - b1 - (int)(b1 > c2));
                m1 -= (int)(m1 >= c1);

                int m2 = min(b2 - 1, s - b2 - (int)(b2 > c2));
                m2 -= (int)(m2 >= c1) + (int)(m2 >= b1);

                int m3 = min(b3 - 1, s - b3 - (int)(b3 > c2));
                m3 -= (int)(m3 >= c1) + (int)(m3 >= b1) + (int)(m3 >= b2);

                if (m1 > m2) swap(m1, m2);
                if (m1 > m3) swap(m1, m3);
                if (m2 > m3) swap(m2, m3);
                if (m1 < 1 || m2 < 2 || m3 < 3) continue;
                sum += m1 * (m2 - 1) * (m3 - 2);
            }
        }
    }

    LL total = 1;
    REP(i,6) total *= (n - 2 - i);
    total /= 6 * 8;
    
    if (sum * 4 > total) return 1;
    else return 0;
}

void doit(int n) {
    if (ans[n].first != -1) return;

    vector<pair<int, int> > all;
    FOR(s,3,n+n-1) {
        RFOR(i,(s-1)/2,max(1,s-n)) {
            all.push_back(make_pair(i, s - i));
        }
    }

    int lt = 0, rt = all.size() - 1;
    while (lt < rt) {
        int mt = (lt + rt) >> 1;
        if (isok(N, all[mt].first, all[mt].second)) rt = mt;
        else lt = mt + 1;
    }

    ans[n] = make_pair(all[lt].first, all[lt].second);
}

bool cmp(int a, int b, int c, int d) {
    if (a + b > c + d) return true;
    if (a + b < c + d) return false;
    return b >= d;
}

void run() {
    scanf("%d %d", &N, &H);
    doit(N);
    REP(i,H) {
        scanf("%d %d", &C1, &C2);
        if (C1 > C2) swap(C1, C2);
        if (cmp(C1, C2, ans[N].first, ans[N].second)) printf("B");
        else printf("F");
    }
    printf("\n");
}

int main() {
    //showtime();
    ans.assign(105, make_pair(-1, -1));
    int kase;
    scanf("%d", &kase);
    FOR(k,1,kase) {
        printf("Case #%d: ", k);
        run();
    }
    //showtime();
    return 0;
}
