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

int mm[105][105][105];
int N, H, C1, C2;

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

int doit(int n, int c1, int c2) {
    int& ret = mm[n][c1][c2];
    if (ret != -1) return ret;

    LL sum = 0;
    int s = c1 + c2;
    FOR(b1,1,n) {
        if (b1 == c1 || b1 == c2) continue;
        FOR(b2,b1+1,n) {
            if (b2 == c1 || b2 == c2) continue;
            FOR(b3,b2+1,n) {
                if (b3 == c1 || b3 == c2) continue;

                int m1 = min(b1 - 1, s - b1 - (int)(b1 > c2));
                m1 -= (int)(m1 >= c1) + (int)(m1 >= c2);

                int m2 = min(b2 - 1, s - b2 - (int)(b2 > c2));
                m2 -= (int)(m2 >= c1) + (int)(m2 >= c2) + (int)(m2 >= b1);

                int m3 = min(b3 - 1, s - b3 - (int)(b3 > c2));
                m3 -= (int)(m3 >= c1) + (int)(m3 >= c2) + (int)(m3 >= b1) + (int)(m3 >= b2);

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
    
    if (sum * 4 > total) ret = 1;
    else ret = 0;

    return ret;
}

void run() {
    scanf("%d %d", &N, &H);
    REP(i,H) {
        scanf("%d %d", &C1, &C2);
        if (C1 > C2) swap(C1, C2);
        if (doit(N, C1, C2)) printf("B");
        else printf("F");
    }
    printf("\n");
}

int main() {
    //showtime();
    memset(mm, -1, sizeof(mm));
    int kase;
    scanf("%d", &kase);
    FOR(k,1,kase) {
        printf("Case #%d: ", k);
        run();
    }
    //showtime();
    return 0;
}
