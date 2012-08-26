#include <iostream>
#include <string>
using namespace std;

string mat[3];

int win(char ch) {
    int flag;
    for (int i = 0; i < 3; ++i) {
        flag = 1;
        for (int j = 0; j < 3; ++j) {
            if (mat[i][j] != ch) {
                flag = 0;
                break;
            }
        }
        if (flag) return 1;
    }
    for (int i = 0; i < 3; ++i) {
        flag = 1;
        for (int j = 0; j < 3; ++j) {
            if (mat[j][i] != ch) {
                flag = 0;
                break;
            }
        }
        if (flag) return 1;
    }
    flag = 1;
    for (int i = 0; i < 3; ++i) {
        if (mat[i][i] != ch) {
            flag = 0;
            break;
        }
    }
    if (flag) return 1;
    flag = 1;
    for (int i = 0; i < 3; ++i) {
        if (mat[i][2 - i] != ch) {
            flag = 0;
            break;
        }
    }
    if (flag) return 1;
    return 0;
}

int Run() {
    for (int i = 0; i < 3; ++i) cin >> mat[i];
    int x, o;
    x = o = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (mat[i][j] == 'X') ++x;
            else if (mat[i][j] == 'O') ++o;
        }
    }
    if (! (x - o == 0 || x - o == 1)) return 0;
    if (x - o == 0 && win('X')) return 0;
    if (x - o == 1 && win('O')) return 0;
    return 1;
}

int main() {
    int kase;
    for (cin >> kase; kase; --kase) {
        cout << (Run() ? "yes" : "no") << endl;
    }
    return 0;
}
