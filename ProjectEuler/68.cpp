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

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

LL s2i(string s) {
  stringstream ss;
  ss << s;
  LL res;
  ss >> res;
  return res;
}

string i2s(LL n) {
  stringstream ss;
  ss << n;
  string res;
  ss >> res;
  return res;
}

void run() {
  string res;
  vector<int> mm;
  FOR(i,1,10) mm.push_back(i);
  do {
    bool fl = false;
    FOR(i,5,9) {
      if (mm[i] == 10) {
        fl = true;
        break;
      }
    }
    if (fl) continue;
    vector<int> dd;
    vector<string> ss;
    REP(i,5) {
      int sum = mm[i];
      string str = "";
      str += i2s(mm[i]);
      int start = i + 5;
      REP(j,2) {
        sum += mm[start];
        str += i2s(mm[start]);
        ++start;
        if (start > 9) start = 5;
      }
      ss.push_back(str);
      dd.push_back(sum);
      if (dd.size() > 1) {
        int cnt = dd.size();
        if (dd[cnt - 1] != dd[cnt - 2]) {
          fl = true;
          break;
        }
      }
    }
    if (fl) continue;
    string str = "";
    int st = 0;
    FOR(i,1,4) {
        if (mm[i] < mm[st]) st = i;
    }
    REP(i,5) {
        str += ss[st];
        ++st;
        if (st == 5) st = 0;
    }
    cout << str << endl;
    if (res == "") res = str;
    else if (str > res) res = str;
  } while (next_permutation(mm.begin(), mm.end()));
  cout << res << endl;
}

int main () {
  run();
  return 0;
}
