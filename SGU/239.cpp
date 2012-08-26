#include <iostream>
#include <cstdio>
using namespace std;

#define for if(0); else for

int a[1002], b[1002];
int n;
int ret = 0;
int mine[1002];

void dfs(int now) {
    if (now == n + 1) {
        if (b[n] == a[n]) ++ret;
        return;
    }
    if (mine[now] != -1) {
        if (b[now - 1] == a[now - 1]) dfs(now + 1);
        return;
    }
    mine[now] = 0;
    if (b[now - 1] == a[now - 1]) {
        dfs(now + 1);
    }
    mine[now] = 1;
    int flag = 1;
    for (int j = -1; j <= 1; ++j) {
        if (now + j >= 1 && now + j <= n) {
            b[now + j] += 1;
            if (b[now + j] > a[now + j]) flag = 0;
        }
    }
    if (flag) {
        if (b[now - 1] == a[now - 1]) {
            dfs(now + 1);
        }
    }
    for (int j = -1; j <= 1; ++j) {
        if (now + j >= 1 && now + j <= n) {
            b[now + j] -= 1;
        }
    }
    mine[now] = -1;
}

int main() {
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) mine[i] = -1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 3) {
            if (i == 1 || i == n) {
                printf("0\n");
                exit(0);
            }
            for (int j = -1; j <= 1; ++j) {
                if (i + j >= 1 && i + j <= n) {
                    if (mine[i + j] == -1) {
                        mine[i + j] = 1;
                        for (int k = -1; k <= 1; ++k) {
                            if (i + j + k >= 1 && i + j + k <= n) {
                                b[i + j + k] += 1;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 2) {
            if (b[i] >= 3) {
                printf("0\n");
                exit(0);
            } else if (b[i] == 2) {
                for (int j = -1; j <= 1; ++j) {
                    if (i + j >= 1 && i + j <= n) {
                        if (mine[i + j] == -1) {
                            mine[i + j] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1) {
            if (b[i] >= 2) {
                printf("0\n");
                exit(0);
            } else if (b[i] == 1) {
                for (int j = -1; j <= 1; ++j) {
                    if (i + j >= 1 && i + j <= n) {
                        if (mine[i + j] == -1) {
                            mine[i + j] = 0;
                        }
                    }
                }
            }
        }
    }
    ret = 0;
    dfs(1);
    printf("%d\n", ret);
    return 0;
}
