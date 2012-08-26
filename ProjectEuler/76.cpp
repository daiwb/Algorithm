#include <iostream>
using namespace std;

int mm[105][105];

int dp(int n, int s) {
    int& ret = mm[n][s];
    if (ret != -1) return ret;

    if (n == 0) return ret = 1;
    if (s > n) return 0;

    ret = 0;
    int t = n;
    while (true) {
        if (t < 0) break;
        ret += dp(t, s + 1);
        t -= s;
    }

    return ret;
}

int main() {
    memset(mm, -1, sizeof(mm));
    cout << dp(100, 1) - 1 << endl;
    return 0;
}
