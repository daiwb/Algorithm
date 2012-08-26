#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

void Run() {
    int kk = 1, cc = 0;
    double p, i, u;
    p = i = u = -1;
    string in;
    while (cin >> in) {
        if (in[1] != '=') continue;
        double mm = 1, value;
        int j = 2;
        while (! ((in[j] >= 'a' && in[j] <= 'z') || (in[j] >= 'A' && in[j] <= 'Z'))) ++j;
        value = atof(in.substr(2, j - 2).c_str());
        if (in[j] == 'm') {
            mm = 0.001;
        } else if (in[j] == 'k') {
            mm = 1000;
        } else if (in[j] == 'M') {
            mm = 1000000;
        }
        if (in[0] == 'P') {
            p = mm * value;
            ++cc;
        } else if (in[0] == 'I') {
            i = mm * value;
            ++cc;
        } else {
            u = mm * value;
            ++cc;
        }
        if (cc == 2) {
            cc = 0;
            cout << "Problem #" << kk++ << endl;
            if (p == -1) {
                p = u * i;
                printf("P=%.2lfW\n\n", p);
            } else if (i == -1) {
                i = p / u;
                printf("I=%.2lfA\n\n", i);
            } else {
                u = p / i;
                printf("U=%.2lfV\n\n", u);
            }
            p = u = i = -1;
        }
    }
}

int main() {
    int kase;
    cin >> kase;
    Run();
    return 0;
}
