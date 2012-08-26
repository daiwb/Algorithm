#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    double a = log(4.0);
    for (int i = 1960; i <= n; i += 10) {
      a *= 2.0;
    }
    int idx = 1;
    double b = 0;
    while (1) {
      b += log(double(++idx));
      if (b >= a) break;
    }
    cout << idx - 1 << endl;
  }
  return 0;
}
