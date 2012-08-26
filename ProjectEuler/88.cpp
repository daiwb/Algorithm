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

#define MAXN 12000
#define INF 1000000000

int mul, sum, idx;
int mm[MAXN + 5];

void go(int n) {
  int dest = mul - sum + idx;
  if (dest > MAXN) return;
  mm[dest] = min(mm[dest], mul);

  FOR(i,n,MAXN) {
    mul *= i, sum += i, ++idx;
    if (mul - sum + idx <= MAXN) go(i);
    mul /= i, sum -= i, --idx;
  }
}

set<int> dd;

void run() {
  FOR(i,2,MAXN) mm[i] = INF;
  FOR(i,2,MAXN) {
    //cout << i << endl;
    mul = i, sum = i, idx = 1;
    go(i);
  }

  dd.clear();
  FOR(i,2,MAXN) {
    //cout << i << " " << mm[i] << endl;
    dd.insert(mm[i]);
  }

  int res = 0;
  for (set<int>::iterator itr = dd.begin(); itr != dd.end(); ++itr) res += *itr;
  cout << res << endl;
}

int main () {
  run();
  return 0;
}
