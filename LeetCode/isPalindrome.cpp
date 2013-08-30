#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;

        int d = 10;
        while (x / d >= 10) d *= 10;

        while (x >= 10) {
            if ((x / d) != (x % 10)) return false;
            x = (x % d) / 10;
            d /= 100;
        }

        return true;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.isPalindrome(-1) << endl;
    cout << sol.isPalindrome(5) << endl;
    cout << sol.isPalindrome(22) << endl;
    cout << sol.isPalindrome(54345) << endl;
    cout << sol.isPalindrome(123456) << endl;
    return 0;
}
