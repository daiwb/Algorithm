#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int a[21];

void run() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int mm = 1;
    int kk = 0;
    int idx = 0;
    sort(a, a + n);
    while (1) {
        if (idx < n) {
            while (1) {
                if (idx == n) break;
                if (a[idx] <= mm) {
                    mm += a[idx];
                    ++idx;
                } else {
                    break;
                }
            }
            if (idx == n) continue;
            if (kk == k) {
                cout << mm << endl;
                return;
            }
            ++kk;
            mm *= 2;
            while (1) {
                if (idx == n) break;
                if (a[idx] <= mm) {
                    mm += a[idx];
                    ++idx;
                } else {
                    break;
                }
            }
            if (idx == n) continue;
        }
        if (kk == k) {
            cout << mm << endl;
            return;
        }
        mm = mm * 2;
        ++kk;
    }
}
int main() {
    int kase;
    cin >> kase;
    for (int kk = 0; kk < kase; ++kk) {
        if (kk) cout << endl;
        cout << "Case " << kk + 1 << ":" << endl;
        run();
    }
    return 0;
}