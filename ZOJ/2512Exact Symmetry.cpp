//ac
#include <iostream>
using namespace std;

char s[2002];

bool check (int m, int n) {
    int half = (n-m + 1) / 2;
    for (int i = m, j = n; i < m+half; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }

    return true;
}

int main() {
    bool flag;
    while (cin >> s) {
        int len = strlen(s);
        int i;

        for (i = 0; i < len; ++i) {
            s[i + len] = s[i];
        }
        s[2*len] = 0;

        for (i = 0; i < len; ++i) {
            if (check(i+1, i+len-1) == true) {
                flag = true;
                break;

            }

            if (i != len - 1) {
            if (check(i+1, i+len) == true) {
                flag = false;
                break;

            }
            }
        }

        if (i == len) {
            cout << "Not symmetric" << endl;
        } else if (flag == true) {
            cout << "Symmetric" << endl;
            cout << i+1 << endl;;
        } else {
            cout << "Symmetric" << endl;
            cout << i+1 << '-' << i+2 << endl;
        }
    }

    return 0;
}
