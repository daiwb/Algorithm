#include <iostream>
using namespace std;

void run() {
  int n;
  while (cin >> n && n != 42) cout << n << endl;
}

int main() {
  run();
  return 0;
}
