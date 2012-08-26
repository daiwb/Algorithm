#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int score[10][10][10];
int f[2][10][10];
int s[10001][10][10];
int n, m;

void Run() {
    memset(score, 0, sizeof(score));
    while (m--) {
        string num;
        int penalty;
        cin >> num >> penalty;
        score[num[0] - '0'][num[1] - '0'][num[2] - '0'] = penalty;
    }
    if (n == 1) {
        cout << "0" << endl;
        return;
    }
    if (n == 2) {
        cout << "00" << endl;
        return;
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int w = 0;
            for (int k = 1; k < 10; ++k) {
                if (score[i][j][k] > score[i][j][w]) {
                    w = k;
                }
            }
            f[0][i][j] = score[i][j][w];
            s[3][i][j] = w;
        }
    }
    int flag = 0;
    for (int len = 4; len <= n; ++len) {
        flag = 1 - flag;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                int tmp = score[i][j][0] + f[1 - flag][j][0];
                int w = 0;
                for (int k = 1; k < 10; ++k) {
                    if (score[i][j][k] + f[1 - flag][j][k] > tmp) {
                        tmp = score[i][j][k] + f[1 - flag][j][k];
                        w = k;
                    }
                }
                f[flag][i][j] = tmp;
                s[len][i][j] = w;
            }
        }
    }
    int wi = 0, wj = 0;
    int tmp = f[flag][0][0];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (f[flag][i][j] > tmp) {
                tmp = f[flag][i][j];
                wi = i, wj = j;
            }
        }
    }
    cout << wi << wj << s[n][wi][wj];
    for (int ii = 4; ii <= n; ++ii) {
        int tt = s[n + 4 - ii][wi][wj];
        wi = wj, wj = tt;
        cout << s[n + 3 - ii][wi][wj];
    }
    cout << endl;
}

int main() {
    while (cin >> m >> n) {
        Run();
    }
    return 0;
}
