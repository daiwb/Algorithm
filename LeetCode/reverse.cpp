#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int s2i(string s) {
    stringstream ss;
    ss << s;
    int res;
    ss >> res;
    return res;
}

string i2s(int n) {
    stringstream ss;
    ss << n;
    string res;
    ss >> res;
    return res;
}

class Solution {
public:
    int reverse(int x) {
        string str = i2s(x);
        if (str[0] == '-') std::reverse(str.begin() + 1, str.end());
        else std::reverse(str.begin(), str.end());
        return s2i(str);
    }
};

int main() {
    Solution s = Solution();
    cout << s.reverse(123) << endl;
    cout << s.reverse(-123) << endl;
    return 0;
}
