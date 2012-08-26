#include <iostream>
#include <cstdio>
using namespace std;

#define for if(0); else for
#define inf 1000000000

int t, x, m;

void run() {
    scanf("%d", &m);
    int ret = inf;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        int tmp;
        if (a % b == 0) tmp = a / b;
        else tmp = a / b + 1;
        if (tmp < ret) ret = tmp;
    }
    
    if (t == 0 || ret == 1) {
        printf("0\n");
        return;
    }
    if (m == 0 || ret < t) {
        printf("%d\n", t * x);
        return;
    }
    int res = 0;
    t -= ret - 1;
    res = ret - 1 + t / 2;
    res *= x;
    printf("%d\n", res);
}

int main() {
    while (scanf("%d %d", &t, &x) != EOF) {
        run();
    }
    return 0;
}