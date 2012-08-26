//ac

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double ff(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3) {
	double ret = 0;
	ret += a1 * b2 * c3;
	ret += a2 * b3 * c1;
	ret += a3 * b1 * c2;
	ret -= a1 * b3 * c2;
	ret -= a2 * b1 * c3;
	ret -= a3 * b2 * c1;
	return ret;
}

double s(double a) {
	return a * a;
}

int main() {
	double a, b, c, d, e, f;
	scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);
	double v = ff(2 * s(a), s(a) + s(b) - s(d), s(a) + s(c) - s(e),
			s(a) + s(b) - s(d), 2 * s(b), s(b) + s(c) - s(f),
			s(a) + s(c) - s(e), s(b) + s(c) - s(f), 2 * s(c));
	v = sqrt(2.0 * v / 24.0 / 24.0);
	//printf("%lf\n", v);
	printf("%.4lf\n", v);
	return 0;
}

