#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define PI acos(-1.0)

int n;

void Run() {
    double ret = 1 / (1 - cos(2.0 * PI / n));
    printf("%.3lf\n", ret);
}

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        scanf("%d", &n);
        Run();
    }
    return 0;
}
