#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int MAXN = 100;

int n, m;
double rate[MAXN][MAXN];
double weight[MAXN];

void Run() {
    memset(rate, 0, sizeof(rate));
    for (int i = 0; i < n - 1; ++i) scanf("%lf", &weight[i]);
    for (int i = 0; i < m; ++i) {
        int a, b;
        double c;
        scanf("%d %d %lf", &a, &b, &c);
        --a, --b, c = 1 - c;
        if (c > rate[a][b]) {
            rate[a][b] = rate[b][a] = c;
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                double tmp = rate[i][k] * rate[k][j];
                if (tmp > rate[i][j]) {
                    rate[i][j] = rate[j][i] = tmp;
                }
            }
        }
    }
    double ret = 0;
    for (int i = 0; i < n - 1; ++i) {
        ret += weight[i] * rate[i][n - 1];
    }
    printf("%.2lf\n", ret);
}

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        Run();
    }
    return 0;
}
