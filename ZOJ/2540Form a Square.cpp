//ac
#include <iostream>
#include <cmath>
using namespace std;

#define for if(0); else for

double dis(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double x[4], y[4];

int isok(int now) {
  double len = dis(x[0], y[0], x[now], y[now]);
  for (int i = 1; i < 4; ++i) {
    if (i == now) continue;
    double d = dis(x[i], y[i], x[0], y[0]);
    if (fabs(d * sqrt(2.0) - len) > 1e-4) return 0;
    d = dis(x[i], y[i], x[now], y[now]);
    if (fabs(d * sqrt(2.0) - len) > 1e-4) return 0;
  }
  return 1;
}

void run() {
  for (int i = 0; i < 4; ++i) cin >> x[i] >> y[i];
  for (int i = 1; i < 4; ++i) {
    if (isok(i)) {
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" << endl;
}

int main() {
  int kase;
  cin >> kase;
  for (int kk = 0; kk < kase; ++kk) {
    if (kk) cout << endl;
    cout << "Case " << kk + 1 << ":" << endl;
    run();
  }
  return 0;
}
