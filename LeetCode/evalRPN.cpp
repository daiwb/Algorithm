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
    bool isop(string str) {
        return str == "+" || str == "-" || str == "*" || str == "/";
    }
    int evalRPN(vector<string> &tokens) {
        vector<string> mm = tokens;
        while (mm.size() > 1) {
            for (int i = 0; i < mm.size(); ++i) {
                if (isop(mm[i])) {
                    int v1 = s2i(mm[i - 2]);
                    int v2 = s2i(mm[i - 1]);
                    int v3;
                    if (mm[i] == "+") v3 = v1 + v2;
                    else if (mm[i] == "-") v3 = v1 - v2;
                    else if (mm[i] == "*") v3 = v1 * v2;
                    else if (mm[i] == "/") v3 = v1 / v2;
                    mm[i] = i2s(v3);
                    mm.erase(mm.begin() + i - 2, mm.begin() + i);
                    break;
                }
            }
        }
        return s2i(mm[0]);
    }
};