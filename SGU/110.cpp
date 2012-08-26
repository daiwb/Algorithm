//ac

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define MAXN  50
#define inf 1000000000
#define eps 1e-10
int N;
int px[MAXN], py[MAXN], pz[MAXN], pr[MAXN];

double beg_x0, beg_y0, beg_z0, beg_x1, beg_y1, beg_z1;

void readdata(){
	int i;
	scanf("%i", &N);
	for (i = 0; i < N; i++) {
		scanf("%i %i %i %i", &px[i], &py[i], &pz[i], &pr[i]);
	}
	scanf("%lf %lf %lf %lf %lf %lf", &beg_x0, &beg_y0, &beg_z0, &beg_x1, &beg_y1, &beg_z1);
}

double intersection(double ax, double ay, double az, double vx, double vy, double vz,
		double px, double py, double pz, double pr)
{
	//intersection rea with sphere
	//it returns nearest point of intersection (value of "t" in equation)
	double A, B, C, D;
	double t1, t2, t;
	A = vx*vx + vy*vy + vz*vz;
	B = ax*vx + ay*vy + az*vz - px*vx - py*vy - pz*vz;
	C = px*px + py*py + pz*pz + ax*ax + ay*ay + az*az - 2*(px*ax + py*ay + pz*az) - pr*pr;
	D = B*B - A*C;
	if (D < -eps)
		return inf;
	else{
		if (D < 0)
			D = 0;
		D= sqrt(D);
		t1 = (-B + D) / A;
		t2 = (-B - D) / A;
		t = inf;
		if (t1 > eps)
			t = t1;
		if ((t2 > eps) && (t2 < t))
			t = t2;
		return t;
	}
}

void make_point(double ax, double ay, double az, double vx, double vy, double vz, double t, double& x, double& y, double& z)
{
	x = ax + vx*t;
	y = ay + vy*t;
	z = az + vz*t;
}

double perpendicular(double ax, double ay, double az, double vx, double vy, double vz){
	return (ax*vx + ay*vy + az*vz) / (vx*vx + vy*vy + vz*vz);
}

int main(){
	int i, j;
	double t, vt;
	int ind;
	double sx, sy, sz;
	double hx, hy, hz;
	readdata();
	for (i = 0; i <= 10; i++){
		t = inf;
		for (j = 0; j < N; j++){
			vt = intersection(beg_x0, beg_y0, beg_z0, beg_x1 - beg_x0, beg_y1 - beg_y0, beg_z1 - beg_z0, px[j], py[j], pz[j], pr[j]);
			if (vt < t){
				t = vt;
				ind = j;
			}
		}
		if (fabs(t - inf) < eps)
			return 0;
		if (i == 10)
			break;
		printf("%i ", ind + 1);
		make_point(beg_x0, beg_y0, beg_z0, beg_x1 - beg_x0, beg_y1 - beg_y0, beg_z1 - beg_z0, t, sx, sy, sz);
		t = perpendicular(beg_x0 - px[ind], beg_y0 - py[ind], beg_z0 - pz[ind],
				sx - px[ind], sy - py[ind], sz - pz[ind]);
		make_point(px[ind], py[ind], pz[ind], sx - px[ind], sy - py[ind], sz - pz[ind], t, hx, hy, hz);
		beg_x1 = beg_x0 + 2*(hx - beg_x0);
		beg_y1 = beg_y0 + 2*(hy - beg_y0);
		beg_z1 = beg_z0 + 2*(hz - beg_z0);
		beg_x0 = sx;
		beg_y0 = sy;
		beg_z0 = sz;
	}
	printf("etc.");
	return 0;
}


