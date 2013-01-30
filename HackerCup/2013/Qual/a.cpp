#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string str;

void run() {
    int mm[26] = {0};
    getline(cin, str);
    for (int i = 0; i < str.length(); ++i) {
        char ch = tolower(str[i]);
        if (ch < 'a' || ch > 'z') continue;
        ++mm[ch - 'a'];
    }
    vector<int> ct;
    for (int i = 0; i < 26; ++i) {
        if (mm[i] != 0) ct.push_back(mm[i]);
    }
    sort(ct.begin(), ct.end());
    int ret = 0, mu = 26;
    for (int i = ct.size() - 1; i >= 0; --i, --mu) {
        ret += mu * ct[i];
    }
    cout << ret << endl;
}

int main() {
    int m;
    cin >> m;
    getline(cin, str);
    for (int i = 1; i <= m; ++i) {
        cout << "Case #" << i << ": ";
        run();
    }        
    return 0;
}
