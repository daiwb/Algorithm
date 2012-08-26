/**
 * zju 1729 Hidden Password
 * 00:00.02 576k
 * 2004.10.15 by adai
 */

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase --) {
        int len;
        char a[200002];
        scanf("%d", &len);
        scanf("%s", a);
        memcpy(a + len, a, len);
        
        int res = 0;
        for (int i = 1; i < len; i ++) {
            if (a[i] < a[res]) res = i;
        }
        
        for (int i = res + 1; i < len; i ++) {
            if (a[i] > a[res]) continue;
            int sign = 1;
            for (int j = res + 1; j <= i; j ++) {
                if (a[j] < a[i + j - res]) {
                    sign = 0;
                    break;
                }
                if (a[j] > a[i + j - res]) {
                    res = i;
                    sign = 0;
                    break;
                }
            }
            if (sign) i = (i - res) * 2 + res - 1;
        }
        printf("%d\n", res);
    }
    return 0;
}

