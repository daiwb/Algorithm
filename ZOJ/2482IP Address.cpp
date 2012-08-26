#include <iostream>
#include <string>
using namespace std;

int n;
int ret[4];
string ip;

int convert(string ip) {
    int ret = 0;
    for (int i = 0; i < 8; ++i) ret = ret * 2 + ip[i] - '0';
    return ret;
}

void Run() {
    cin >> ip;
    for (int i = 0; i < 4; ++i) {
        ret[i] = convert(ip.substr(i * 8, 8));
    }
    cout << ret[0];
    for (int i = 1; i < 4; ++i) cout << '.' << ret[i];
    cout << endl;
}

int main() {
    for (cin >> n; n; --n) {
        Run();
    }
    return 0;
}
