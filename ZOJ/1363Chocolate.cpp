// ac

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define eps 1e-8

int c, n, m;

void run() {
        if (m > c || n < m) {
                printf("0.000\n");
                return;
        }
        if (n == 0) {
                printf("1.000\n");
                return;
        }
        vector<vector<double > > mm(2, vector<double>(c + 1, 0.0));
        mm[0][1] = 1.0;
        int flag = 0;
        if (n > 1000) {
                if (n % 2) n = 1001;
                else n = 1000;
        }
        for (int i = 1; i < n; ++i) {
                flag = 1 - flag;
                mm[flag].assign(c + 1, 0.0);
                for (int j = 0; j <= c; ++j) {
                        if (j + 1 <= c) mm[flag][j + 1] += mm[1 - flag][j] * (c - j) / c;
                        if (j - 1 >= 0) mm[flag][j - 1] += mm[1 - flag][j] * j / c;
                }
        }
        printf("%.3lf\n", mm[flag][m]);
}

int main() {
        while (scanf("%d", &c) && c) {
                scanf("%d %d", &n, &m);
                run();
        }
        return 0;
}
