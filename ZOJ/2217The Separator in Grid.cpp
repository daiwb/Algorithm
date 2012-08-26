//ac

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int n, m;

void run() {
        vector<string> mm(n);
        for (int i = 0; i < n; ++i) cin >> mm[i];
        for (int i = 0; i < n; ++i) {
                int j;
                for (j = m - 1; j >= 0; --j) {
                        if (mm[i][j] == 'S') break;
                }
                if (j != m - 1) mm[i][j + 1] = 'S';
        }
        vector<vector<int> > dd(2, vector<int>(m, -1));
        int flag = 0;
        for (int i = 0; i < m; ++i) {
                if (mm[0][i] == 'S') dd[0][i] = 1;
        }
        for (int kk = 1; kk < n; ++kk) {
                flag = 1 - flag;
                dd[flag].assign(m, -1);
                for (int i = 0; i < m; ++i) {
                        if (mm[kk][i] == 'S') {
                                if (mm[kk - 1][i] == 'S') {
                                        dd[flag][i] = dd[1 - flag][i] + 1;
                                }
                        }
                }
                vector<int> tmp(m, -1);
                for (int i = 0; i < m; ++i) {
                        if (mm[kk][i] == 'S' && dd[flag][i] == -1) {
                                int step = 1000000000;
                                for (int j = 0; j < m; ++j) {
                                        if (dd[flag][j] > 0) {
                                                if (dd[flag][j] + abs(j - i) < step) step = dd[flag][j] + abs(j - i);
                                        }
                                }
                                tmp[i] = step;
                        }
                }
                for (int i = 0; i < m; ++i) {
                        if (tmp[i] > 0) dd[flag][i] = tmp[i];
                }
        }
        int ret = 1000000000;
        for (int i = 0; i < m; ++i) {
                if (dd[flag][i] > 0) {
                        if (dd[flag][i] < ret) ret = dd[flag][i];
                }
        }
        cout << ret << endl;
}

int main() {
        while (cin >> n >> m && n + m) {
                run();
        }
        return 0;
}