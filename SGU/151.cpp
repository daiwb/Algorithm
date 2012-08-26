//ac

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	double a, b, m;
	scanf("%lf %lf %lf", &a, &b, &m);
	int rev = 0;
	if (a < b) {
		rev = 1;
		swap(a, b);
	}
	if (m < fabs(a - b) / 2.0 || m > fabs(a + b) / 2.0) {
		printf("Mission impossible\n");
		return 0;
	}
	if (a * a + b * b - 2 * m * m == 0) {
		printf("%.5lf %.5lf\n%.5lf %.5lf\n%.5lf %.5lf\n", 0.0, m, 0.0, 0.0, 0.0, 0.0);
		return 0;
	}
	double cosa = (a * a - b * b) * (a * a - b * b) / (8 * m * m * (a * a + b * b - 2 * m * m));
	cosa = sqrt(cosa);
	cosa = acos(cosa);
	if (rev)
		printf("%.5lf %.5lf\n", -m * cos(cosa), m * sin(cosa));
	else
		printf("%.5lf %.5lf\n", m * cos(cosa), m * sin(cosa));
	double r = sqrt(a * a - m * m * sin(cosa) * sin(cosa)) - m * cos(cosa);
	printf("%.5lf %.5lf\n%.5lf %.5lf\n", -r, 0.0, r, 0.0);
	return 0;
}

