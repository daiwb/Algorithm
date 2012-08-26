//ac
#include <cstdio>
#include <map>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

#define inf (numeric_limits<int>::max()/2)

struct point {
    int x, y, z;
    bool operator < (const point& pp) const {
        if (x != pp.x) {
            return x < pp.x;
        } else if (y != pp.y) {
            return y < pp.y;
        } else {
            return z < pp.z;
        }
    }
    point() {}
    point(int xx, int yy, int zz) : x(xx), y(yy), z(zz){}
};


int main() {
    int n, m;
    while (scanf("%d", &m) != EOF) {
        map<point, int> pipes;
        vector<vector<pair<int, int> > > link;
        int kpipe = 0;
        while (m--) {
            int x1, y1, z1, x2, y2, z2;
            scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
            
            if (pipes.find(point(x1, y1, z1)) == pipes.end()) {
                pipes[point(x1, y1, z1)] = kpipe++;
                link.push_back(vector<pair<int, int> >());
            }
            if (pipes.find(point(x2, y2, z2)) == pipes.end()) {
                pipes[point(x2, y2, z2)] = kpipe++;
                link.push_back(vector<pair<int, int> >());
            }
            
            int i1 = pipes[point(x1, y1, z1)], i2 = pipes[point(x2, y2, z2)];
            int ww = z1 > z2 ? z1 : z2;
            link[i1].push_back(make_pair(i2, ww));
            link[i2].push_back(make_pair(i1, ww));
        }
        n = kpipe;
        int istart = pipes[point(0, 0, 0)];
        vector<int> s(n, inf);
        vector<bool> flag(n, false);
        s[istart] = 0;
        for (int i = 0; i < n; ++i) {
            int node = -1;
            for (int j = 0; j < n; ++j) {
                if (flag[j] == false && (node == -1 || s[node] > s[j])) {
                    node = j;
                }
            }
            flag[node] = true;
            for (int j = 0, m = link[node].size(); j < m; ++j) {
                int dest = link[node][j].first, ww = link[node][j].second;
                if (flag[dest] == true) continue;
                int maxw = ww > s[node] ? ww : s[node];
                if (maxw < s[dest]) {
                    s[dest] = maxw;
                }
            }
        }
        int towers;
        scanf("%d", &towers);
        vector<bool> isTower(n, false);
        while (towers--) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            isTower[pipes[point(x, y, z)]] = true;
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (isTower[i] == true && s[i] < inf  && s[i] > result)
            {
                result = s[i];
            }
        }
        printf("%d\n", result);
    }
}
