#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
#define MP make_pair
#define MPI make_pair<int, int>
#define PB push_back
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PI;

class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int len1 = num1.length(), len2 = num2.length();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        REP(i,len1*len2+5) res += "0";
        REP(i,len2) {
            int v2 = num2[i] - '0';
            int add = 0;
            REP(j,len1) {
                int idx = i + j;
                int v1 = num1[j] - '0';
                int v3 = res[idx] - '0';
                int v = v1 * v2 + add + v3;
                add = v / 10;
                v %= 10;
                res[idx] = v + '0';
            }
            int idx = len1 + i;
            while (add > 0) {
                int v = res[idx] - '0' + add;
                add = v / 10;
                v %= 10;
                res[idx++] = v + '0';
            }
        }
        while (res.length() > 1 && res[res.length() - 1] == '0') res.erase(res.end() - 1);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    cout << s.multiply("123", "56") << endl;
    return 0;
}
