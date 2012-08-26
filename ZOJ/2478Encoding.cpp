#include <iostream>
#include <cstring>
using namespace std;

void Run() {
  char str[150];
  cin >> str;
  int len = strlen(str);
  char last = 'a';
  int num = 0;
  for (int i = 0; i < len; ++i) {
    if (str[i] == last) ++num;
    else {
      if (last != 'a') {
        if (num > 1) cout << num;
        cout << last;
      }
      last = str[i];
      num = 1;
    }
  }
  if (num > 1) cout << num;
  cout << last << endl;
}

int main() {
  int kase;
  cin >> kase;
  while (kase--) {
    Run();
  }
  return 0;
}
