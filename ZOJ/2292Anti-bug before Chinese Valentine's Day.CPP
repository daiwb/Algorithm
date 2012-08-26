#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
char a[10][10];
int result;

void f(int, int, int);

void next(int i, int j, int current) {
    while (a[i][j] == '.') {
        if (j == m) {
            j = 1;
            ++i;
            if (i == n+1) {
                break;
            }
        }
        else {
            ++j;
        }
    }

    f(i, j, current);
}

void f(int i, int j, int current) {
    if (current >= result) return;
    if (i == n+1) {
        if (current < result) {
            result = current;
        }
        return;
    }

    if (a[i][j] == 'o') {
        char tmp = a[i+1][j];
        a[i][j] = a[i+1][j] = '.';

        if (a[i][j+1] == 'o' || a[i+1][j+1] == 'o') {
            char tmp1 = a[i][j+1];
            char tmp2 = a[i+1][j+1];
            a[i][j+1] = a[i+1][j+1] = '.';

            next(i, j, current+1);

            a[i][j+1] = tmp1;
            a[i+1][j+1] = tmp2;
        }
        char tt = a[i+1][j-1];
        a[i+1][j-1] = '.';

        next(i, j, current+1);

        a[i+1][j-1] = tt;
            

        a[i][j] = 'o';
        a[i+1][j] = tmp;
    }
    else {
        next(i, j, current);
    }
}

int main() {


    while (scanf("%d %d", &n, &m) && n) {
        for (int i = 1; i <= n; ++i) {
            scanf("%s", a[i] + 1);
        }

        for (int i = 0; i <= n+1; ++i) {
            a[i][0] = a[i][m+1] = '.';
        }

        for (int j = 0; j <= m+1; ++j) {
            a[0][j] = a[n+1][j] = '.';
        }

				result = (n + 1) / 2 * (m + 1) / 2;
        f(1, 1, 0);

        printf("%d\n", result);
    }
}
