/**
 * Problem: Find the sum of all eleven primes that are both truncatable from left to right and right to left.
 * Algorithm: DFS
 * Author: daiwb
 * Date: 2008/08/31
 */

#include <iostream>
#include <sstream>
#include <set>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;

int res;
int num[4] = {1, 3, 7, 9};

int string2int(string str) {
  stringstream ss;
  ss << str;
  int res;
  ss >> res;
  return res;
}

bool isprime(int val) {
  if (val == 2 || val == 3 || val == 5 || val == 7) return true;
  if (val == 1) return false;

  int mid = (int)sqrt(val + 0.5);
  if ((val & 1) == 0) return false;
  for (int i = 3; i <= mid; i += 2) {
    if ((val % i) == 0) return false;
  }
  return true;
}

bool isok(string str) {
  if (str.length() == 1) return false;

  REP(len,str.length()) {
    string s = str.substr(len);
    if (!isprime(string2int(s))) return false;
    s = str.substr(0, len + 1);
    if (!isprime(string2int(s))) return false;
  }
  return true;
}

void dfs(string str) {
  stringstream ss;
  ss << str;
  int val;
  ss >> val;
  if (!isprime(val)) return;

  if (isok(str)) {
    res += val;
  }

  REP(i,4) dfs(str + char(num[i] + '0'));
}

void run() {
  res = 0;
  dfs("2");
  dfs("3");
  dfs("5");
  dfs("7");
  cout << res << endl;
}

int main() {
  run();
}
