/**
 * ZOJ 2414 Index of Prime
 */

#include <cstdio>
#include <string>
#include <fstream>
using namespace std;

int plist[10005], pcount = 0;
int mm[10005];


int prime(int n) {
    int i;
    if ((n != 2 && !(n%2)) || (n!=3 && !(n%3)) || (n!=5 && !(n%5)) || (n!=7 && !(n%7)))
        return 0;

    for (i = 0; plist[i]*plist[i] <= n; ++i) {
        if (!(n%plist[i]))
            return 0;
    }



    return n > 1;
}

void initprime() {
    int i;
    memset(mm, 0, sizeof(mm));
    mm[1] = 0;
    mm[2] = 1;
    for (plist[pcount++] = 2, i = 3; i < 50000; ++ i) {
        if (prime(i)) {
            if (i <= 10000) {
                mm[i] = 1;
            }
            plist[pcount++] = i;
        }
    }
}

int n;

int Run() {
    int hn;
    if (n <= 1) {
        printf("0\n");
        return 0;
    }
    if (mm[n] == 1) {
        printf("1\n%d\n", n);
        return 0;
    }
    if (n== 4) {
        printf("2\n2 2\n");
        return 0;
    }
    if (n % 2 == 0) {
        printf("2\n");
        hn = n >> 1;
        while (mm[hn] == 0) ++ hn;
        for (; hn <= 10000; hn += 2) {
            if (mm[hn] && mm[n-hn]) {
                printf("%d %d\n", hn, n - hn);
                return 0;
            }
        }
    }
    if (mm[n-2] == 1) {
        printf("2\n%d %d\n", n - 2, 2);
        return 0;
    }

    hn = (n + 2) / 3;
    while (mm[hn] == 0) ++ hn;
    int i1, i2;
    for (i1 = 0; i1 < pcount; ++ i1) if (plist[i1] == hn) break;
        int half = (n - plist[i1] + 1) / 2;
    for (; plist[i1] < n; ++ i1) {
        int half = (n - plist[i1] + 1) / 2;
        for (; half < n - plist[i1] && half <= plist[i1]; ++half)
            if (mm[half] && mm[n-plist[i1]-half]) {
                printf("3\n%d %d %d\n", plist[i1], half, n - plist[i1] - half);
                return 0;
            }
    }
    return 0;
}

int main() {
    initprime();

    while (scanf("%d", &n) != EOF) {
        Run();
    }

    return 0;
}
