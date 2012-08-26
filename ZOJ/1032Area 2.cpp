#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

struct point {
    double x,y;
}mm[105];

//计算多边形面积,顶点按顺时针或逆时针给出
double area_polygon(int n,point* p){
	double s1=0,s2=0;
	int i;
	for (i=0;i<n;i++)
		s1+=p[(i+1)%n].y*p[i].x,s2+=p[(i+1)%n].y*p[(i+2)%n].x;
	return fabs(s1-s2)/2;
}

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int n;
double I, E, A;

void Run() {
    cin >> n;
    mm[0].x = mm[0].y = 0;
    for (int i = 1; i <= n; ++i) {
        int tx, ty;
        cin >> tx >> ty;
        mm[i].x = mm[i - 1].x + tx;
        mm[i].y = mm[i - 1].y + ty;
    }
    A = area_polygon(n, mm);
    E = n;
    for (int i = 0; i < n; ++i) {
        int xx = (int)abs(mm[i].x - mm[i + 1].x);
        int yy = (int)abs(mm[i].y - mm[i + 1].y);
        if (xx == 0 || yy == 0) {
            E += xx + yy - 1;
        } else {
            E += gcd(xx, yy) - 1;
        }
    }
    I = A + 1 - E * 1.0 / 2;
    printf("%.0lf %.0lf %.1lf\n\n", I, E, A);
}

int main() {
    int kase;
    cin >> kase;
    for (int kk = 1; kk <= kase; ++kk) {
        cout << "Scenario #" << kk << ":" << endl;
        Run();
    }
    return 0;
}
