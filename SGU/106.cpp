//ac

#include <iostream>
#include <cstdio>
using namespace std;

long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}

inline long long lcm(long long a,long long b){
	return a/gcd(a,b)*b;
}

long long ext_gcd(long long a,long long b,long long& x,long long& y){
	long long t,ret;
	if (!b){
		x=1,y=0;
		return a;
	}
	ret=ext_gcd(b,a%b,x,y);
	t=x,x=y,y=t-a/b*y;
	return ret;
}

long long a, b, c, x1, x2, y11, y22;
long long x, y;
long long ret;

int main() {
	cin >> a >> b >> c >> x1 >> x2 >> y11 >> y22;
	//scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &x1, &x2, &y11, &y22);
	if (!a && !b) {
		if (c == 0) ret = (x2 - x1 + 1) * (y22 - y11 + 1);
		else ret = 0;
		cout << ret << endl;
		//printf("%lld\n", ret);
		return 0;
	}
	if (a == 0) {
		long long m = -c / b;
		if (m >= y11 && m <= y22 && b * m + c == 0) {
			ret = 1;
		} else {
			ret = 0;
		}
		cout << ret << endl;
		//printf("%lld\n", ret);
		return 0;
	}
	if (b == 0) {
		long long m = -c / a;
		if (m >= x1 && m <= x2 && a * m + c == 0) {
			ret = 1;
		} else {
			ret = 0;
		}
		cout << ret << endl;
		//printf("%lld\n", ret);
		return 0;
	}
	long long g = ext_gcd(a, b, x, y);
	c *= -1;
	if (c % g != 0) {
		cout << 0 << endl;
		//printf("0\n");
		return 0;
	}
	x *= c / g, y *= c / g;
	long long l = lcm(a, b);
	long long dx = l / a, dy = l / b;
	long long a1, a2, b1, b2;
	if (dx > 0) {
		a1 = (x1 - x) / dx, a2 = (x2 - x) / dx;
		a1 -= 2, a2 += 2;
		while (x + a1 * dx < x1) ++a1;
		while (x + a2 * dx > x2) --a2;
	} else {
		a1 = (x2 - x) / dx, a2 = (x1 - x) / dx;
		a1 -= 2, a2 += 2;
		while (x + a1 * dx > x2) ++a1;
		while (x + a2 * dx < x1) --a2;
	}
	if (dy > 0) {
		b1 = (y - y22) / dy, b2 = (y - y11) / dy;
		b1 -= 2, b2 += 2;
		while (y - b1 * dy > y22) ++b1;
		while (y - b2 * dy < y11) --b2;
	} else {
		b1 = (y - y11) / dy, b2 = (y - y22) / dy;
		b1 -= 2, b2 += 2;
		while (y - b1 * dy < y11) ++b1;
		while (y - b2 * dy > y22) --b2;
	}
	long long ll = max(a1, b1), rr = min(a2, b2);
	if (ll > rr) ret = 0;
	else ret = rr - ll + 1;
	//printf("%lld\n", ret);
	cout << ret << endl;
	return 0;
}

