#include <iostream>
#include <string>
using namespace std;

int small(int a, int b) {
    return a < b ? a : b;
}

int n;

int h[3]; //the weight, size and defend capabilities of the helm
int a[3]; //the weight, size and defend capabilities of the armor
int b[3]; //the weight, size and defend capabilities of the boot
int e[4]; //the number of helms, armors and boots in a set of equipments and the capability of this set
int w[100]; //the weight limit of a trade caravan
int s[100]; //the size limit of a trade caravan
int F[2][501][501];
int maxh, maxa;
int maxhh, maxaa;
int now;

void Input() {
    for (int i = 0; i < 3; ++i) cin >> h[i];
    for (int i = 0; i < 3; ++i) cin >> a[i];
    for (int i = 0; i < 3; ++i) cin >> b[i];
    for (int i = 0; i < 4; ++i) cin >> e[i];
    for (int i = 0; i < n; ++i) cin >> w[i] >> s[i];
}

void Solve() {
    memset(F, -1, sizeof(F));
    maxh = small(w[0] / h[0], s[0] / h[1]);
    maxa = small(w[0] / a[0], s[0] / a[1]);
    for (int i = 0; i <= maxh; ++i) {
        for (int j = 0; j <= maxa; ++j) {
            if (i * h[0] + j * a[0] <= w[0] && i * h[1] + j * a[1] <= s[0]) {
                F[0][i][j] = small((w[0] - i * h[0] - j * a[0]) / b[0], (s[0] - i * h[1] - j * a[1]) / b[1]);
            }
        }
    }
    now = 1;
    for (int m = 1; m < n; ++m, now = 1 - now) {
        maxhh = small(w[m] / h[0], s[m] / h[1]);
        maxaa = small(w[m] / a[0], s[m] / a[1]);
        maxh += maxhh, maxa += maxaa;
        for (int i = 0; i <= maxh; ++i) {
            for (int j = 0; j <= maxa; ++j) {
                int ret = -1;
                int hh = small(maxhh, i);
                int aa = small(maxaa, j);
                for (int ii = 0; ii <= hh; ++ii) {
                    if (ii * h[0] > w[m] || ii * h[1] > s[m]) break;
                    for (int jj = 0; jj <= aa; ++jj) {
                        if (ii * h[0] + jj * a[0] > w[m] || ii * h[1] + jj * a[1] > s[m]) break;
                        if (F[1 - now][i - ii][j - jj] == -1) continue;
                        int tmp = small((w[m] - ii * h[0] - jj * a[0]) / b[0], (s[m] - ii * h[1] - jj * a[1]) / b[1]);
                        if (tmp + F[1 - now][i - ii][j - jj] > ret) ret = tmp + F[1 - now][i - ii][j - jj];
                    }
                }
                F[now][i][j] = ret;
            }
        }
    }
}

void Output() {
    static int kase = 0;
    if (kase) cout << endl;
    cout << "Case " << ++kase << ": ";
    int ret = 0;
    for (int i = 0; i <= maxh; ++i) {
        for (int j = 0; j <= maxa; ++j) {
            int k = F[1 - now][i][j];
            if (k == -1) continue;
            int num = small(i / e[0], j / e[1]);
            num = small(num, k / e[2]);
            int tmp = num * e[3];
            tmp += (i - num * e[0]) * h[2];
            tmp += (j - num * e[1]) * a[2];
            tmp += (k - num * e[2]) * b[2];
            if (tmp > ret) ret = tmp;
        }
    }
    cout << ret << endl;
}

void Run() {
    Input();
    Solve();
    Output();
}

int main() {
    while (cin >> n && n) {
        Run();
    }
    return 0;
}
