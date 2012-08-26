#include <iostream>
#include <cstdio>
using namespace std;

int l, m;

void run() {
    int ret = l + 1;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        ret -= b - a + 1;
    }
    printf("%d\n", ret);
}

int main() {
    while (scanf("%d %d", &l, &m) && l + m) {
        run();
    }
    return 0;
}
