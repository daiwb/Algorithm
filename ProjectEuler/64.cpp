#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

string i2s(int n) {
  stringstream ss;
  ss << n;
  string res;
  ss >> res;
  return res;
}

map<string, int> dic;
map<string, int>::iterator itr;

string getStr(int a, int b, int c) {
  return i2s(a) + "," + i2s(b) + "," + i2s(c);
}

int doit(int n) {
  dic.clear();

  int a = (int) sqrt(n + 0.0);
  if (a * a == n) return 0;

  int b = a, c = 1;

  int idx = 0;
  string s = getStr(a, b, c);
  dic[s] = idx++;

  while (true) {
    int a1 = c, b1 = b, c1 = n - b * b;
    c1 /= a1;
    a = (int)((sqrt(n + 0.0) + b1) / c1);
    b = a * c1 - b1;
    c = c1;

    string s = getStr(a, b, c);
    itr = dic.find(s);
    if (itr == dic.end()) {
      dic[s] = idx++;
    } else {
      return idx - dic[s];
    }
  }
}

void run() {
  int res = 0;
  FOR(i,1,10000) {
    int t = doit(i);
    //if (i % 1000 == 0) cout << i << " " << t << endl;
    if ((t & 1) == 1) ++res;
  }
  cout << res << endl;
}

int main () {
  run();
  return 0;
}
