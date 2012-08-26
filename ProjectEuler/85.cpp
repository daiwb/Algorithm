#include <iostream>
using namespace std;

#define DEST 2000000
typedef long long LL;

LL doit(LL width, LL len) {
    LL ret = 0;

    for (LL i = 1; i <= len; ++i) {
        for (LL j = 1; j <= width; ++j) {
            ret += (len - i + 1) * (width - j + 1);
        }
    }

    return ret;
}

void run() {
    LL diff = DEST, area = DEST;
    for (LL i = 1; ; ++i) {
        bool flag = true;
        for (LL j = i; ; ++j) {
            LL temp = doit(i, j);
            LL t = temp - DEST;
            if (t < 0) t *= -1;
            if (t < diff) {
                diff = t;
                area = i * j;
            }
            if (temp > DEST) {
                break;
            } else {
                flag = false;
            }
        }
        if (flag) break;
    }
    cout << area << endl;
}

int main() {
    run();
    return 0;
}
