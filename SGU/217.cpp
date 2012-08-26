//ac

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double Romberg (double a, double b, double (*f)(double x, double y, double z), double eps, 
		double l, double t)
{
#define MAX_N  1000

	int i, j, temp2, min;
	double h, R[2][MAX_N], temp4;

	for (i=0; i<MAX_N; i++) {
		R[0][i] = 0.0;
		R[1][i] = 0.0;
	}
	h = b-a;
	min = (int)(log(h*10.0)/log(2.0)); //h should be at most 0.1
	R[0][0] = ((*f)(a, l, t)+(*f)(b, l, t))*h*0.50;
	i = 1;
	temp2 = 1;
	while (i<MAX_N){
		i++;
		R[1][0] = 0.0;
		for (j=1; j<=temp2; j++)
			R[1][0] += (*f)(a+h*((double)j-0.50), l, t);
		R[1][0] = (R[0][0] + h*R[1][0])*0.50;
		temp4 = 4.0;
		for (j=1; j<i; j++) {
			R[1][j] = R[1][j-1] + (R[1][j-1]-R[0][j-1])/(temp4-1.0);
			temp4 *= 4.0;
		}
		if ((fabs(R[1][i-1]-R[0][i-2])<eps)&&(i>min))
			return R[1][i-1];
		h *= 0.50;
		temp2 *= 2;
		for (j=0; j<i; j++)
			R[0][j] = R[1][j];
	}
	return R[1][MAX_N-1];
}

double r1, r2;

double f(double x, double l, double t) {
	return sqrt((r1 * r1 - x * x) * (r2 * r2 - x * x));
}

int main() {
	scanf("%lf %lf", &r1, &r2);
	if (r1 > r2) {
		double t = r1; r1 = r2; r2 = t;
	}
	double ret = 8 * Romberg(0, r1, f, 1e-5, 0, 0);
	printf("%.4lf\n", ret);
	return 0;
}
