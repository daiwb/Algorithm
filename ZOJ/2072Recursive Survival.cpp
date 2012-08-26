#include <iostream>
using namespace std;

int out[10000], num;

int main() {
    unsigned long long n, t;
    while (cin >> n >> t) {
        long long ret, last = n;
        num = -1;
        while (n) {
            out[++num] = n % 2;
            n /= 2;
        }
        while (t--) {
            for (int i = num; i >= 1; --i) out[i] = out[i - 1];
            out[0] = 1;
            while (out[num] == 0) --num;
            ret = 0;
            for (int i = num; i >= 0; --i) ret = ret * 2 + out[i];
            if (ret == last) break;
            last = ret;
        }
        cout << ret << endl;
    }
    return 0;
}
