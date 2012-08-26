//ac
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int s[4096];
int num[4096];
int ret;

void Run() {
    ret = 0;
    memset(s, 0, sizeof(s));
    int n;
    scanf("%d", &n);
    while (n--) {
        int a;
        scanf("%d", &a);
        --a;
        s[a] = 1 - s[a];
        if (s[a] == 0) {
            num[a] = 0;
            int tt = a;
            int sss = 0;
            while (1) {
                ++tt;
                if (tt == 4096 || s[tt] == 0) break;
                else ++sss;
            }
            tt = a;
            while (1) {
                ++tt;
                if (tt == 4096 || s[tt] == 0) break;
                else num[tt] = sss;
            }
            sss = 0;
            tt = a;
            while (1) {
                --tt;
                if ( tt == -1 || s[tt] == 0) break;
                else ++sss;
            }
            tt = a;
            while (1) {
                --tt;
                if ( tt == -1 || s[tt] == 0) break;
                else num[tt] = sss;
            }
        } else {
            int tmp = 1;
            if (a - 1 >= 0 && s[a - 1] == 1) tmp += num[a - 1];
            if (a + 1 < 4096 && s[a + 1] == 1) tmp += num[a + 1];
            if (tmp > ret) ret = tmp;
            num[a] = tmp;
            int tt = a;
            while (1) {
                ++tt;
                if (tt == 4096 || s[tt] == 0) break;
                else num[tt] = tmp;
            }
            tt = a;
            while (1) {
                --tt;
                if (tt == -1 || s[tt] == 0) break;
                else num[tt] = tmp;
            }
        }
    }
    printf("%d\n", ret);
}

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        Run();
    }
    return 0;
}
