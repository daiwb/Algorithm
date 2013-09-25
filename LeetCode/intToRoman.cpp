#include <iostream>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

class Solution {
public:
    string intToRoman(int num) {
        string s = "IVXLCDM#";
        int i1 = 0, i5 = 1;
        string ret = "";
        while (num > 0) {
            int t = (num % 10);
            num /= 10;

            string ts = "";
            if (t == 0) {
            } else if (t >= 1 && t <= 3) {
                REP(i,t) {
                    ts += s[i1];
                }
            } else if (t == 4) {
                ts += s[i1];
                ts += s[i5];
            } else if (t <= 8) {
                ts += s[i5];
                REP(i,t - 5) ts += s[i1];
            } else {
                ts += s[i1];
                ts += s[i1 + 2];
            }

            ret = ts + ret;

            i1 += 2;
            i5 += 2;
        }
        
        return ret;
    }
};

int main() {
    Solution s = Solution();
    FOR(i,1,20) cout << s.intToRoman(i) << endl;
    cout << s.intToRoman(3999) << endl;
    cout << s.intToRoman(3645) << endl;
    cout << s.intToRoman(2300) << endl;
    cout << s.intToRoman(2444) << endl;
    return 0;
}
