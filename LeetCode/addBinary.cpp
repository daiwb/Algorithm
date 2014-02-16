#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() > b.length()) swap(a, b);
        int la = a.length(), lb = b.length();
        int add = 0;
        REP(i,la) {
            int s = a[la - 1 - i] - '0' + b[lb - 1 - i] - '0' + add;
            add = s / 2;
            s %= 2;
            b[lb - 1 - i] = s + '0';
        }
        FOR(i,la,lb-1) {
            int s = b[lb - 1 - i] - '0' + add;
            add = s / 2;
            s %= 2;
            b[lb - 1 - i] = s + '0';
            if (add == 0) break;
        }
        if (add == 1) b = "1" + b;
        return b;
    }
};

int main() {
	return 0;
}
