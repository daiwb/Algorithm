#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
#define MP make_pair
#define MPI make_pair<int, int>
#define PB push_back
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PI;

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.empty()) return 0;
        int res = 0;
        int n = points.size();
        REP(i,n) {
            map<pair<int, int>, int> mp;
            int dup = 1;
            REP(j,n) {
                if (i == j) continue;
                pair<int, int> p;
                if (points[i].x == points[j].x) {
                    if (points[i].y == points[j].y) {
                        ++dup;
                        continue;
                    } else {
                        p = make_pair<int, int>(1, 0);
                    }
                } else {
                    int dy = points[j].y - points[i].y;
                    int dx = points[j].x - points[i].x;
                    int g = gcd(dy, dx);
                    dy /= g;
                    dx /= g;
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                    p = make_pair(dy, dx);
                }
                if (mp.find(p) == mp.end()) mp[p] = 1;
                else ++mp[p];
                res = max(res, dup + mp[p]);
            }
            res = max(res, dup);
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    vector<Point> vp;
    Point p1 = Point(0, 0);
    Point p2 = Point(0, 0);
    vp.PB(p1);
    vp.PB(p2);
    cout << s.maxPoints(vp) << endl;
    return 0;
}
