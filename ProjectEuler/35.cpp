/**
 * Problem: How many circular primes are there below one million?
 * Algorithm: DFS
 * Author: daiwb
 * Date: 2008/08/31
 */

#include <iostream>
#include <sstream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;

int plist[80000], pcount = 0;
int mm[1000005];

int prime(int n){
  int i;
  if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
    return 0;
  for (i=0;plist[i]*plist[i]<=n;i++)
    if (!(n%plist[i]))
      return 0;
  return n>1;
}

void initprime(){
  memset(mm, 0, sizeof(mm));
  int i;
  mm[2] = 1;
  for (plist[pcount++]=2,i=3;i<1000000;i++)
    if (prime(i)) {
      plist[pcount++]=i;
      mm[i] = 1;
    }
}

int res, len;
int num[4] = {1, 3, 7, 9};

bool isCircularPrime(string str) {
  REP(i,len) {
    stringstream ss;
    ss << str;
    int val;
    ss >> val;
    if (mm[val] == 0) return false;
    str = str.substr(1) + str[0];
  }
  return true;
}

void dfs(int idx, string str) {
  if (idx == len) {
    if (isCircularPrime(str)) {
      ++res;
      cout << str << endl;
    }
    return;
  }

  REP(i,4) {
    dfs(idx + 1, str + char(num[i] + '0'));
  }
}

void run() {
  res = 0;

  // 1-9
  res = 4;

  for (len = 2; len <= 6; ++len) {
    dfs(0, "");
  }

  cout << res << endl;
}

int main() {
  initprime();
  run();
}
