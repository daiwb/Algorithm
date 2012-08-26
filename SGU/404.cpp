#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int idx = (n + m - 1) % m;
    string str;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if (i == idx) str = s;
    }
    cout << str << endl;
    return 0;
}
