#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdio>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

class point {
public:
    double x;
    double y;
    point() {
    }
    point(double xx, double yy) {
        x = xx;
        y = yy;
    }
    point &operator=(const point& cc) {
        x = cc.x;
        y = cc.y;
        return *this;
    }
};

double dis(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int n;

void Run() {
    vector<double> tmp(n);
    for (int i = 0; i < n; ++i) {
        cin >> tmp[i];
    }
    sort(tmp.begin(), tmp.end());
    deque<point> a;
    for (int i = 0; i < n; ++i) {
        a.push_back(point(tmp[i], 1.0));
    }
    int size = a.size();
    while (size > 1) {
        for (int i = 0; i < size - 1; ++i) {
            point l = a[i];
            point r = a[i + 1];
            double len = dis(l, r) / 2;
            double angle = acos(len / 2.0);
            point c;
            c.x = (l.x + r.x) / 2;
            c.x = ((r.x - l.x) * cos(angle) - (r.y - l.y) * sin(angle)) / len + l.x;
            c.y = ((r.y - l.y) * cos(angle) + (r.x - l.x) * sin(angle)) / len + l.y;
            a.push_back(c);
        }
        for (int i = 0; i < size; ++i) a.pop_front();
        --size;
    }
    cout << setiosflags(ios::fixed) << setprecision(4);
    cout << a[0].x << ' ' << a[0].y << endl;
    //printf("%.4lf %.4lf\n", a[0].x, a[0].y);
}

int main() {
    while (cin >> n && n) {
        Run();
    }
    return 0;
}
