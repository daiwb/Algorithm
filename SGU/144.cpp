//ac

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	double x, y, z;
	scanf("%lf %lf %lf", &x, &y, &z);
	z /= 60.0;
	double area = (y - x) * (y - x);
	double s = (y - x - z) * (y - x - z);
	printf("%.7lf\n", (area - s) / area);
	return 0;
}

