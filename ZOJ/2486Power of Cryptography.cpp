#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double k, p;
    int n;
    while (cin >> k >> p) {
        n = int(pow(p, 1.0 / k) + 0.5);
        cout << n << endl;
    }
    return 0;
}
