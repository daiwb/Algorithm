//ac

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

#define PI acos(-1.0)

class point {
public:
	double x, y;
};

double dis(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void prt(double a) {
	//if (fabs(a) < 1e-8) printf("0.000000");
	//else 
	printf("%.6lf", a);
}

int main() {
	int n, n1, n2;
	double len, r;
	scanf("%d %d %d", &n, &n1, &n2);
	vector<point> pos(n);
	--n1, --n2;
	scanf("%lf %lf %lf %lf", &pos[n1].x, &pos[n1].y, &pos[n2].x, &pos[n2].y);
	if (n1 > n2) swap(n1, n2);
	len = dis(pos[n1], pos[n2]);
	double alpha = (n2 - n1) * 2.0 * PI / n;
	if (alpha > PI + 1e-6) alpha = 2 * PI - alpha;
	alpha = (PI - alpha) / 2.0;
	r = len / 2.0 / cos(alpha);
	point c;
	if (n2 - n1 <= n / 2) {
		c.x = (+(pos[n2].x - pos[n1].x) * cos(alpha) + (pos[n2].y - pos[n1].y) * sin(alpha)) * r / len + pos[n1].x;
		c.y = (-(pos[n2].x - pos[n1].x) * sin(alpha) + (pos[n2].y - pos[n1].y) * cos(alpha)) * r / len + pos[n1].y;
	} else {
		c.x = ((pos[n2].x - pos[n1].x) * cos(alpha) - (pos[n2].y - pos[n1].y) * sin(alpha)) * r / len + pos[n1].x;
		c.y = ((pos[n2].x - pos[n1].x) * sin(alpha) + (pos[n2].y - pos[n1].y) * cos(alpha)) * r / len + pos[n1].y;
	}
	int idx = n1, next;
	double beta = 2 * PI / n;
	for (int i = 1; i < n; ++i) {
		next = (idx + 1) % n;
		pos[next].x = +(pos[idx].x - c.x) * cos(beta) + (pos[idx].y - c.y) * sin(beta) + c.x;
		pos[next].y = -(pos[idx].x - c.x) * sin(beta) + (pos[idx].y - c.y) * cos(beta) + c.y;
		idx = next;
	}
	for (int i = 0; i < n; ++i) {
		prt(pos[i].x);
		printf(" ");
		prt(pos[i].y);
		printf("\n");
	}
	return 0;
}

