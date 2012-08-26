/*
 * zju 1450 Minimal Circle
 * 00:01.53 456k
 * 2004.09.22 by adai
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

class point
{
public:
	double x;
	double y;
	point(double tx, double ty)
	{
		x = tx;
		y = ty;
	}
};

#define  EPS 1e-8

//计算cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

//计算三角形面积,输入三顶点
double area_triangle(point p1,point p2,point p3){
	return fabs(xmult(p1,p2,p3))/2;
}

#define INF 1000000
/* 
* calc the circlr from three points,input points a,b,c 
* output o will be the center,return value be the R. 
*/ 
double circle(point a, point b, point c, point& o) 
{ 
	double A,B,C,D,E,F,G; 
	double r; 

	A=b.x-a.x; 
	B=b.y-a.y; 
	C=c.x-a.x; 
	D=c.y-a.y; 

	E=A*(a.x+b.x) + B*(a.y+b.y); 
	F=C*(a.x+c.x) + D*(a.y+c.y); 

	G=2.0*(A*(c.y-b.y)-B*(c.x-b.x)); 

	if (fabs(G) < EPS) 
		return INF; 

	o.x=(D*E - B*F)/G; 
	o.y=(A*F - C*E)/G; 

	r=(a.x-o.x)*(a.x-o.x)+(a.y-o.y)*(a.y-o.y); 
	return r; 
} 

/*double dis(point a, point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}*/
double dis(point a, point b) {
	return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

int main()
{
	int n;
	double x, y, r;
	while (1)
	{
		scanf("%d", &n);
		if (!n) break;

		vector <point> v;
		for (int i = 0; i < n; i ++)
		{
			scanf("%lf %lf", &x, &y);
			v.push_back(point(x, y));
		}
		
		if (n == 1) {
			printf("%.2lf %.2lf %.2lf\n", v[0].x, v[0].y, 0);
			continue;
		}
		
		if (n == 2) {
			x = (v[0].x + v[1].x) / 2, y = (v[0].y + v[1].y) / 2, r = dis(v[0], v[1]);
			printf("%.2lf %.2lf %.2lf\n", x, y, sqrt(r) / 2);
			continue;
		}
		
		r = -EPS;
		double mm;
		for (int i = 0; i < n - 1; i ++) {
			for (int j = i + 1; j < n; j ++) {
				mm = dis(v[i], v[j]);
				if (mm - r > EPS) {
					x = (v[i].x + v[j].x) / 2;
					y = (v[i].y + v[j].y) / 2;
					r = mm;
				}
			}
		}
		r /= 4;
		int sign = 1;
		point temp(x, y);
		for (int i = 0; i < n; i ++) {
			if (dis(v[i], temp) - r > EPS) {
				sign = 0;
				break;
			}
		}
		if (sign) {
			printf("%.2lf %.2lf %.2lf\n", x, y, sqrt(r));
			continue;
		}

		r = INF;
		for (int i = 0; i < n - 2; i ++) {
			for (int j = i + 1; j < n - 1; j ++) {
				for (int t = j + 1; t < n; t ++) {
					if (fabs(area_triangle(v[i], v[j], v[t]) - 0) < EPS) continue;
					mm = circle(v[i], v[j], v[t], temp);
					if (fabs(mm - INF) < EPS) continue;
					if (mm - r > EPS) continue;
					int sign = 1;
					for (int ii = 0; ii < n; ii ++) {
						if (dis(v[ii], temp) - mm > EPS) {
							sign = 0;
							break;
						}
					}
					if (!sign) continue;
					x = temp.x;
					y = temp.y;
					r = mm;
				}
			}
		}
		printf("%.2lf %.2lf %.2lf\n", x, y, sqrt(r));
	}
	return 0;
}
