/**
 * ZOJ 1806 This Takes the Cake
 *
 * 2005/05/04 By adai
 */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

class point {
public:
	double x;
	double y;
};

//计算cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

//计算三角形面积,输入三顶点
double area_triangle(point p1,point p2,point p3){
	return fabs(xmult(p1,p2,p3))/2;
}

double x[3], y[3];
point p[8];
int kase = 0;

int Run() {
	for (int i = 1; i <= 7; i += 2) {
		p[i].x = (p[(i + 7) % 8].x + p[(i + 1) % 8].x) / 2;
		p[i].y = (p[(i + 7) % 8].y + p[(i + 1) % 8].y) / 2;
	}
	double total = area_triangle(p[0], p[2], p[4]) + area_triangle(p[4], p[6], p[0]);
	double a, b, reta, retb, minn = total;
	
	for (int i = 0; i <= 2; i += 2) {
		a = area_triangle(p[i], p[i + 2], p[i + 4]);
		b = total - a;
		if (fabs(a - b) < minn) {
			minn = fabs(a - b);
			reta = a, retb = b;
		}
	}
	
	for (int i = 1; i <= 3; i += 2) {
		a = area_triangle(p[i], p[i + 1], p[i + 3]) + area_triangle(p[i], p[i + 3], p[i + 4]);
		b = total - a;
		if (fabs(a - b) < minn) {
			minn = fabs(a - b);
			reta = a, retb = b;
		}
	}
	
	for (int i = 1; i <= 7; i += 2) {
		a = area_triangle(p[i], p[(i + 1) % 8], p[(i + 2) % 8]);
		b = total - a;
		if (fabs(a - b) < minn) {
			minn = fabs(a - b);
			reta = a, retb = b;
		}
	}
	
	for (int i = 0; i <= 6; i += 2) {
		a = area_triangle(p[i], p[(i + 2) % 8], p[(i + 3) % 8]);
		b = total - a;
		if (fabs(a - b) < minn) {
			minn = fabs(a - b);
			reta = a, retb = b;
		}
		
		a = area_triangle(p[i], p[(i + 5) % 8], p[(i + 6) % 8]);
		b = total - a;
		if (fabs(a - b) < minn) {
			minn = fabs(a - b);
			reta = a, retb = b;
		}
	}
	
	if (reta > retb) {
		double temp = reta;
		reta = retb;
		retb = temp;
	}
	printf("Cake %d: %.3lf %.3lf\n", ++kase, reta, retb);
	
	return 0;
}

int main() {
	while (1) {
		for (int i = 0; i <= 6; i += 2) {
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		int quit = 1;
		for (int i = 0; i <= 6; i += 2) {
			if (p[i].x != 0 || p[i].y != 0) {
				quit = 0;
				break;
			}
		}
		if (quit) break;
		Run();
	}
	return 0;
}
