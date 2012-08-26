#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

inline int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

inline int lcm(int a,int b){
	return a/gcd(a,b)*b;
}

int g, l;

void Run() {
    double ratio = g * 1.0 / l;
    int end = gcd(g, l);
    end = l / end;
    int m;
    m = g / l;
    int a = m + 1;
    if (fabs(a - ratio) <= fabs(m - ratio)) m = a;
    double last = fabs(m - ratio);
    cout << m << '/' << 1 << endl;
    for (int n = 2; n <= end; ++n) {
        m = n * g / l;
        a = m + 1;
        if (fabs(a * 1.0 / n - ratio) <= fabs(m * 1.0 / n - ratio)) m = a;
        double now = fabs(m * 1.0 / n - ratio);
        if (now < last) {
            cout << m << '/' << n << endl;;
            last = now;
        }
    }
}

int main() {
    int kase = 0;
    while (cin >> g >> l) {
        if (kase++) cout << endl;
        Run();
    }
    return 0;
}
