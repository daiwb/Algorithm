#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        vector<pair<int, int> > mm;
        int n = intervals.size();
        if (n == 0) return res;
        REP(i,n) mm.push_back(make_pair(intervals[i].start, intervals[i].end));
        sort(mm.begin(), mm.end());
        int lt = mm[0].first, rt = mm[0].second;
        FOR(i,1,n-1) {
            if (mm[i].first <= rt) rt = max(rt, mm[i].second);
            else {
                res.push_back(Interval(lt, rt));
                lt = mm[i].first;
                rt = mm[i].second;
            }
        }
        res.push_back(Interval(lt, rt));
        return res;
    }
};

int main() {
    return 0;
}
