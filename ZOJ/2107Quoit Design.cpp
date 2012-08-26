/*
 * ZJU 2107 Quoit Design
 * 00:01.63 1976K
 * Algo : Divide and Conquer
 * 2004.12.05 BY ADAI
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

class point {
public:
	double x;
	double y;
}mm[100000];

int cmp(const void *t1, const void *t2) {
	point *a, *b; 
	a = (point *)t1;
	b = (point *)t2;
	if ((*a).x > (*b).x) return 1;
	if ((*a).x < (*b).x) return -1;
	//if ((*a).y > (*b).y) return 1;
	//if ((*a).y < (*b).y) return -1;
	return 0;
} 

double dis(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double f(int left, int right) {
	double len = -1;
	if (right - left <= 2) {
		for (int i = left; i < right; i ++) {
			for (int j = i + 1; j <= right; j ++) {
				double temp = dis(mm[i], mm[j]);
				if (temp < len || len < 0) len = temp;
			}
		}
		return len;
	}
	int middle = (left + right) / 2;
	double lenf, lenr;
	lenf = f(left, middle);
	lenr = f(middle, right);
	len = lenf < lenr ? lenf : lenr;
	for (int i = middle - 1; i >= left && middle - i <= 4; i --) {
		if (mm[middle].x - mm[i].x >= len) break;
		for (int j = middle + 1; j <= right && right - middle <= 4; j ++) {
			if (mm[j].x - mm[i].x >= len) break;
			double temp = dis(mm[i], mm[j]);
			if (temp < len) len = temp;
		}
	}
	return len;
}

int main() {
	int n;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		for (int i = 0; i < n; i ++) scanf("%lf %lf", &mm[i].x, &mm[i].y);
		qsort(mm, n, sizeof(mm[0]), cmp);
		double res = f(0, n - 1);
		printf("%.2lf\n", res / 2);
	}
	return 0;
}
