//ac

#pragma warning(disable:4786)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define for if(0); else for

int a[10000], n, m;
int mm[1000];
int bk[1000];
int res[1000];
int out[1000];

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {    
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        memset(mm, 0, m * sizeof(mm[0]));
        mm[1] = 1;
        int ret = 1;
        vector<int> dd;
        dd.push_back(1);
        for (int i = 0; i < n; ++i) {
            int size = dd.size();
            for (int j = 0; j < size; ++j) {
                int now = (dd[j] * a[i]) % m;
                if (mm[now] == 0) {
                    if (now > ret) {
                        ret = now;
                    }
                    dd.push_back(now);
                    mm[now] = dd[j];
                    res[now] = i;
                }
            }
        }
        printf("%d\n", ret);
        if (ret == 1) continue;
        int num = 0;
        while (ret != 1) {
            out[num++] = res[ret];
            ret = mm[ret];
        }
        for (int i = 0; i < num; ++i) {
            if (i) printf(" ");
            printf("%d", out[num - 1 - i] + 1);
        }
        printf("\n");
    }
    return 0;
}
