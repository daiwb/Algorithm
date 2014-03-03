#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

class child {
public:
    int rating;
    int idx;
    bool operator<(const child& rhs) const {
        if (rating != rhs.rating) return rating < rhs.rating;
        return idx < rhs.idx;
    }
};

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        vector<child> mm(n);
        vector<int> num(n, 1);
        REP(i,n) {
            mm[i].rating = ratings[i];
            mm[i].idx = i;
        }
        sort(mm.begin(), mm.end());
        REP(i,n) {
            int now = mm[i].idx;
            if (now > 0 && ratings[now] > ratings[now - 1]) num[now] = max(num[now], num[now - 1] + 1);
            if (now < n - 1 && ratings[now] > ratings[now + 1]) num[now] = max(num[now], num[now + 1] + 1);
        }
        int sum = 0;
        REP(i,n) sum += num[i];
        return sum;
    }
};

int main() {
    return 0;
}
