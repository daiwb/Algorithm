/**
 * Problem: Find the sum of all numbers less than one million, which are palindromic in base 10 and base 2.
 * Algorithm: Brute Force
 * Author: daiwb
 * Date: 2008/08/31
 */

#include <iostream>
#include <sstream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;

bool isPal(string str) {
  int len = str.length();
  REP(i,len >> 1) {
    if (str[i] != str[len - 1 - i]) return false;
  }
  return true;
}

bool isPalDec(int val) {
  stringstream ss;
  ss << val;
  string str;
  ss >> str;
  return isPal(str);
}

bool isPalBin(int val) {
  string str = "";
  do {
    str += char((val & 1) + '0');
    val >>= 1;
  } while (val != 0);
  return isPal(str);
}

void run() {
  int res = 0;
  for (int i = 1; i < 1000000; i += 2) {
    if (isPalDec(i) && isPalBin(i)) res += i;
  }
  cout << res << endl;
}

int main() {
  run();
}
