//ac

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int sum = 0;
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    sum += a;
  }
  sum %= n;
  cout << sum << endl;
  return 0;
}
