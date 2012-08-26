// ac

#include <iostream>
#include <string>
using namespace std;

string run(string str) {
    string ret = "";
    int len = str.length();
    int idx = 0;
    while (idx < len) {
        if (str[idx] >= 'a' && str[idx] <= 'z') {
            ret += str[idx++];
            continue;
        }
        int num = str[idx] - '0';
        while (1) {
            ++idx;
            if (str[idx] >= '0' && str[idx] <= '9')
                num = num * 10 + str[idx] - '0';
            else
                break;
        }
        if (str[idx] == '(') {
            int pos = idx + 1, cnt = 1;
            while (1) {
                if (str[pos] == '(') {
                    ++cnt;
                } else if (str[pos] == ')') {
                    --cnt;
                    if (cnt == 0) break;
                }
                ++pos;
            }
            string s = str.substr(idx + 1, pos - idx - 1);
            string ss = run(s);
            for (int i = 0; i < num; ++i) {
                ret += ss;
            }
            idx = pos + 1;
        } else {
            for (int i = 0; i < num; ++i) ret += str[idx];
            ++idx;
        }
    }
    return ret;
}

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        char ch[500];
        scanf("%s", ch);
        string str(ch);
        printf("%s\n", run(str).c_str());
    }
    return 0;
}
