#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

#define see(n) cout << #n << " = " << n << endl
#define seeArray(n, a) cout << #a << " = ";\
for (int __i__ = 0; __i__ < n; ++__i__)\
        cout << a[__i__] << " ";\
        cout << endl;
#define seeArray2(n, m, a) cout << #a << " = " << endl;\
for (int __i__ = 0; __i__ < n; ++__i__) {\
        for (int __j__ = 0; __j__ < m; ++__j__)\
                cout << a[__i__][__j__] << " ";\
                        cout << endl;\
}

#define MAXN 100

int n;
int mat[MAXN][MAXN];

int judge() {
        vector<vector<int> > mm(n);
        for (int i = 0; i < n; ++i) {
                int last = -1;
                for (int j = 0; j < 2 * i + 1; ++j) {
                        if (mat[i][j] != last) {
                                last = mat[i][j];
                                mm[i].push_back(last);
                        }
                }
                if (mm[i].size() > 2) return 0;
        }
        int left = -1, right = -1;
        for (int i = 0; i < n; ++i) {
                if (mm[i].size() == 1) continue;
                if (left == -1) {
                        left = mm[i][0], right = mm[i][1];
                } else {
                        if (left != mm[i][0]) return 0;
                }
        }
        return 1;
}

void tras() {
        int tmp[MAXN][MAXN];
        int idx = n * 2 - 2;
        int ii = 0;
        for (int i = n - 1; i >= 0; --i) {
                int jj = 0;
                tmp[ii][jj++] = mat[i][idx];
                for (int j = i + 1; j < n; ++j) {
                        tmp[ii][jj++] = mat[j][idx + 1];
                        tmp[ii][jj++] = mat[j][idx];
                }
                ++ii;
                idx -= 2;
        }
        memcpy(mat, tmp, sizeof(mat));
}

void run() {
        for (int i = 0; i < n; ++i) {
                string str;
                cin >> str;
                for (int j = 0; j < 2 * i + 1; ++j) {
                        mat[i][j] = str[j] - '0';
                }
        }
        for (int step = 0; step < 3; ++step) {
                if (judge()) {
                        cout << "Parts can be separated" << endl;
                        return;
                }
                tras();
                /*
                cout << "juzhen" << endl;
                for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < 2 * i + 1; ++j) cout << mat[i][j];
                        cout << endl;
                }
                */
        }
        cout << "Parts cannot be separated" << endl;
}

int main() {
        int kase = 0;
        while (cin >> n && n) {
                cout << "Puzzle " << ++kase << endl;
                run();
        }
        return 0;
}
