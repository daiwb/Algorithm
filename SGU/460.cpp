#include <iostream>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)

string doit(string str) {
    int len = str.length();
    if ((str[len - 2] == 'c' && str[len - 1] == 'h') || str[len - 1] == 'x' || str[len - 1] == 's' || str[len - 1] == 'o') {
        return str + "es";
    }

    if (str[len - 2] == 'f' && str[len - 1] == 'e') {
        return str.substr(0, len - 2) + "ves";
    }
    if (str[len - 1] == 'f') {
        return str.substr(0, len - 1) + "ves";
    }

    if (str[len - 1] == 'y') {
        return str.substr(0, len - 1) + "ies";
    }

    return str + "s";
}

int main() {
    int n;
    cin >> n;
    REP(i,n) {
        string str;
        cin >> str;
        cout << doit(str) << endl;
    }
    return 0;
}
