#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool pos = true;
        if (dividend < 0) pos = !pos;
        if (divisor < 0) pos = !pos;

        LL d1 = abs((LL)dividend);
        LL d2 = abs((LL)divisor);

        LL a = d1, b = d2, c = 1;
        while (a > b) {
            b <<= 1;
            c <<= 1;
        }

        int res = 0;
        while (a >= d2) {
            while (a >= b) {
                a -= b;
                res += c;
            }
            b >>= 1;
            c >>= 1;
        }

        if (!pos) res = -res;
        return res;
    }
};

int main() {
    Solution s = Solution();
    cout << s.divide(13, 5) << endl;
    cout << s.divide(15, 5) << endl;
    cout << s.divide(3, 5) << endl;
    cout << s.divide(13, -5) << endl;
    cout << s.divide(-13, 5) << endl;
    cout << s.divide(-1010369383, -2147483648) << endl;
    return 0;
}
