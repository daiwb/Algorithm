/*
zju 1081 Points Within
00:00.00 452k
2004.09.09 by adai
*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

/*
注意一条线段的某一个端点在另一条线段上不算相交
若要判断以上情况将两个multi的乘积改成>=0即可
*/

#define MAXN 1000

#define ZERO(a) (fabs(a) < 1e-8)

class pos{
public:
	double x;
	double y;
	pos(double xx, double yy) {
		x = xx, y = yy;
	}
	pos() {}
	pos &operator = (const pos &cc){
		x = cc.x;
		y = cc.y;
		return *this;
	}
};

class line{
public:
	pos a;
	pos b;
	line(pos aa, pos bb) {
		a = aa, b = bb;
	}
	line() {}
};

double multi(pos p1, pos p2, pos p0){
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

double area(pos p1, pos p2, pos p3) {
	return fabs(multi(p1, p2, p3)) / 2;
}

double max(double a,double b){
	return a > b ? a : b;
}

double min(double a,double b){
	return a < b ? a : b;
}

bool across(line u,line v){
	if(
		(max(u.a.x, u.b.x) >= min(v.a.x, v.b.x)) &&
		(max(v.a.x, v.b.x) >= min(u.a.x, u.b.x)) &&
		(max(u.a.y, u.b.y) >= min(v.a.y, v.b.y)) &&
		(max(v.a.y, v.b.y) >= min(u.a.y, u.b.y)) &&
		(multi(v.a, u.b, u.a) * multi(u.b, v.b, u.a) > 0) &&
		(multi(u.a, v.b, v.a) * multi(v.b, u.b, v.a) > 0)
	) return 1;
	else return 0;
}

bool online(line l, pos p) {
	pos a = l.a, b = l.b;
	if (ZERO(area(a, b, p)) && p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) && p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y)) return 1;
	return 0;
}

int n, m;
double x, y, mx, my;
pos mp;

int main () {
	int kase = 0;
	while (1) {
		cin >> n;
		if (n == 0) break;
		cin >> m;
		vector <pos> pp;
		pp.clear();
		mx = my = -1;
		for (int i = 0; i < n; i ++) {
			cin >> x >> y;
			if (x > mx) mx = x;
			if (y > my) my = y;
			pp.push_back(pos(x, y));
		}
		mx += 999999;
		my += 1000000;
		mp.x = mx;
		mp.y = my;
		
		if (kase) cout << endl;
		cout << "Problem " << ++ kase << ":" << endl;
		
		vector <line> ll;
		ll.clear();
		for (int i = 0; i < n; i ++) {
			ll.push_back(line(pos(pp[i % n].x, pp[i % n].y), pos(pp[(i + 1) % n].x, pp[(i + 1) % n].y)));
		}

		for (int i = 0; i < m; i ++) {
			cin >> x >> y;
			pos test(x, y);
			int valid = 0;
			for (int j = 0; j < n; j ++) {
				if (online(ll[j], test)) {
					valid = 1;
					break;
				}
			}
			if (valid) {
				cout << "Within" << endl;
				continue;
			}
			int count = 0;
			for (int j = 0; j < n; j ++) {
				if (across(ll[j], line(test, mp))) count ++;
			}
			if (count & 1) cout << "Within" << endl;
			else cout << "Outside" << endl;
		}
	}
	return 0;
}
