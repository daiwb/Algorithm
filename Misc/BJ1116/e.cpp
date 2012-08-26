#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define for if(0); else for
#define MAXN 1000

int n, num;
int dis[MAXN][MAXN];
int link[MAXN][MAXN];

int ok(int idx, int now) {
    for (int i = 0; i < idx; ++i) {
        for (int j = i + 1; j < idx; ++j) {
            if (dis[idx][i] - dis[idx][j] != dis[now][i] - dis[now][j]) {
                return 0;
            }
        }
    }
    return 1;
}

void run() {
    memset(link, 0, sizeof(link));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &dis[i][j]);
        }
    }
    num = n;
    int s = dis[0][1];
    for (int i = 0; i < s - 1; ++i) {
        dis[num][0] = i + 1, dis[num][1] = s - i - 1;
        ++num;
    }
    link[0][n] = link[n][0] = link[num - 1][1] = link[1][num - 1] = 1;
    for (int i = n; i < num - 1; ++i) {
        link[i][i + 1] = link[i + 1][i] = 1;
    }
    for (int i = 0; i < s - 1; ++i) {
        for (int j = 0; j < s - 1; ++j) {
            dis[i + n][j + n] = abs(i - j);
        }
    }
    for (int idx = 2; idx < n; ++idx) {
        for (int i = n; i < num; ++i) {
            if (ok(idx, i)) {
                int len = dis[idx][0] - dis[i][0];
                int nn = num;
                for (int ii = 0; ii < len - 1; ++ii) {
                    for (int jj = 0; jj < num; ++jj) {
                        dis[num][jj] = dis[i][jj] + ii + 1;
                    }
                    ++num;
                }
                for (int ii = nn; ii < num; ++ii) {
                    for (int jj = nn; jj < num; ++jj) {
                        dis[ii][jj] = dis[jj][ii] = abs(ii - jj);
                    }
                }
                for (int ii = nn; ii < num - 1; ++ii) {
                    link[ii][ii + 1] = link[ii + 1][ii] = 1;
                }
                if (nn != num) {
                    link[nn][i] = link[i][nn] = 1;
                    link[num - 1][idx] = link[idx][num - 1] = 1;
                }
                break;
            }
        }
    }
    int addi = 1;
}

int main() {
    while (scanf("%d", &n) && n) {
        run();
    }
    return 0;
}