#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const double E = 2.71828;

double a;

void Run() {
    if (a >= E) {
        printf("-1\n");
        return;
    }
    double fa = log(a) / a;
    double left = E, right = 50, mid;
    while (1) {
        mid = (left + right) / 2;
        double fb = log(mid) / mid;
        if (fabs(fa - fb) < 1e-10) {
            printf("%.5lf\n", mid);
            return;
        }
        if (fa < fb) left = mid;
        else right = mid;
    }
}

int main() {
    while (scanf("%lf", &a) != EOF) {
        Run();
    }
    return 0;
}
