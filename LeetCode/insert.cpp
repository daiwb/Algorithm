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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        int n = intervals.size();

        int lt, rt, mt;

        lt = 0, rt = n - 1;
        while (lt <= rt) {
            mt = (lt + rt) / 2;
            if (intervals[mt].end >= newInterval.start) rt = mt - 1;
            else lt = mt + 1;
        }

        int idx1 = rt;
        FOR(i,0,idx1) res.push_back(intervals[i]);

        lt = rt + 1, rt = n - 1;
        while (lt <= rt) {
            mt = (lt + rt) / 2;
            if (intervals[mt].start <= newInterval.end) lt = mt + 1;
            else rt = mt - 1;
        }

        int idx2 = lt;
        if (idx2 - idx1 >= 2) {
            newInterval.start = min(newInterval.start, intervals[idx1 + 1].start);
            newInterval.end = max(newInterval.end, intervals[idx2 - 1].end);
        }
        res.push_back(newInterval);
        FOR(i,idx2,n-1) res.push_back(intervals[i]);

        return res;
    }
};

int main() {
    Solution s;

    vector<Interval> mm;
    mm.push_back(Interval(1, 3));
    mm.push_back(Interval(6, 9));

    vector<Interval> ret = s.insert(mm, Interval(2, 5));
    REP(i,ret.size()) cout << "[" << ret[i].start << "," << ret[i].end << "] ";
    cout << endl;

    mm.clear();
    mm.push_back(Interval(1, 2));
    mm.push_back(Interval(3, 5));
    mm.push_back(Interval(6, 7));
    mm.push_back(Interval(8, 10));
    mm.push_back(Interval(12, 16));

    ret = s.insert(mm, Interval(4, 9));
    REP(i,ret.size()) cout << "[" << ret[i].start << "," << ret[i].end << "] ";
    cout << endl;

    mm.clear();

    ret = s.insert(mm, Interval(4, 9));
    REP(i,ret.size()) cout << "[" << ret[i].start << "," << ret[i].end << "] ";
    cout << endl;

    mm.clear();
    mm.push_back(Interval(1, 3));

    ret = s.insert(mm, Interval(4, 9));
    REP(i,ret.size()) cout << "[" << ret[i].start << "," << ret[i].end << "] ";
    cout << endl;

    mm.clear();
    mm.push_back(Interval(1, 2));
    mm.push_back(Interval(3, 5));
    mm.push_back(Interval(6, 7));
    mm.push_back(Interval(8, 10));
    mm.push_back(Interval(12, 16));

    ret = s.insert(mm, Interval(17, 19));
    REP(i,ret.size()) cout << "[" << ret[i].start << "," << ret[i].end << "] ";
    cout << endl;

    mm.clear();
    mm.push_back(Interval(1, 2));
    mm.push_back(Interval(3, 5));
    mm.push_back(Interval(6, 7));
    mm.push_back(Interval(8, 10));
    mm.push_back(Interval(12, 16));

    ret = s.insert(mm, Interval(-14, -9));
    REP(i,ret.size()) cout << "[" << ret[i].start << "," << ret[i].end << "] ";
    cout << endl;
    
    return 0;
}
