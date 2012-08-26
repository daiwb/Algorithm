//ac

#include <iostream>
#include <cstdio>
using namespace std;

double x[10010], y[10010];
double x_1[10010], y_1[10010];
double sx, sy;
int n;

int main() {
	scanf("%d", &n);
	sx = sy = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lf %lf", &x[i], &y[i]);
		if (i % 2 == 0) sx += x[i], sy += y[i];
		else sx -= x[i], sy -= y[i];
	}
	if (n % 2 == 0 && (sx != 0 || sy != 0)) {
		printf("NO\n");
		return 0;
	}
	if (n % 2 == 1) {
		x_1[0] = sx, y_1[0] = sy;
	} else {
		x_1[0] = y_1[0] = 0;
	}
	for (int i = 1; i < n; ++i) {
		x_1[i] = 2 * x[i - 1] - x_1[i - 1];
		y_1[i] = 2 * y[i - 1] - y_1[i - 1];
	}
	printf("YES\n");
	for (int i = 0; i < n; ++i) {
		printf("%.3lf %.3lf\n", x_1[i], y_1[i]);
	}
	return 0;
}

