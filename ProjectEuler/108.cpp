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

int plist[10000],pcount=0;

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
  int i;
  for (plist[pcount++]=2,i=3;i<50000;i++)
    if (prime(i))
      plist[pcount++]=i;
}

int doit(int n) {
  int ret = 1;
  int end = (int) sqrt(n + 0.0);
  FOR(i,0,pcount-1) {
    if (plist[i] > end) break;
    if (n == 1) break;
    int cnt = 0;
    while (n % plist[i] == 0) {
      ++cnt;
      n /= plist[i];
    }
    ret *= (cnt << 1) + 1;
  }
  if (n != 1) ret *= 3;
  return ((ret - 1) >> 1) + 1;
}

void run() {
  initprime();
  FOR(i,1,1000000) {
    int t = doit(i);
    if (t > 1000) {
      cout << i << " " << t << endl;
      break;
    }
  }
}

int main () {
  run();
  return 0;
}
