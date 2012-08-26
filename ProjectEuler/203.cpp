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

LL plist[300000],pcount=0;

int prime(LL n){
  LL i;
  if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
    return 0;
  for (i=0;plist[i]*plist[i]<=n;i++)
    if (!(n%plist[i]))
      return 0;
  return n>1;
}

void initprime(){
  LL i;
  for (plist[pcount++]=2,i=3;i<3500000;i++)
    if (prime(i))
      plist[pcount++]=i;
  REP(i,pcount) plist[i] *= plist[i];
}

LL mm[55], dd[55];
vector<LL> nums;

bool op(LL n) {  
  return n % 4 == 0 || n % 9 == 0 || n % 25 == 0 || n % 49 == 0;  
}   

void run() {
  initprime();
  cout << pcount << " " << plist[pcount - 1] << endl;
  nums.clear();
  int idx = 1;
  mm[0] = mm[1] = 1;
  nums.push_back(1);
  while (true) {
    ++idx;
    if (idx > 50) break;
    memcpy(dd, mm, sizeof(mm));
    mm[0] = mm[idx] = 1;
    FOR(i,1,idx-1) {
      mm[i] = dd[i] + dd[i - 1];
      nums.push_back(mm[i]);
    }
  }
  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());
  nums.erase(remove_if(nums.begin(), nums.end(), op), nums.end());
  LL ret = 0;
  REP(i,nums.size()) {
    bool flag = true;
    REP(j,pcount) {
      if (plist[j] > nums[i]) break;
      if (nums[i] % plist[j] == 0) {
	flag = false;
	break;
      }
    }
    if (flag) {
      cout << i << " " << nums[i] << endl;
      ret += nums[i];
    } else {
      cout << "**" << i << " " << nums[i] << "**" << endl;
    }
  }
  cout << ret << endl;
  //cout << nums.size() << endl;
  //REP(i,nums.size()) cout << nums[i] << endl;
}

int main () {
  run();
  return 0;
}
