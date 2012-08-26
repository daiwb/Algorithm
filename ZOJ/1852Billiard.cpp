/*
ZJU 1852 Billiard
00:00.00 388K
*/

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

#define PI 3.1415926

main() {
	int a, b, s, m, n;
	double x, y, z;
	for(;;) {
		scanf( " %d %d %d %d %d", &a, &b, &s, &m, &n );
		if( a+b+s+m+n == 0 ) break;
		x = a*(double)m;
		y = b*(double)n;
		z = sqrt(x*x+y*y);
		//z = hypot( x, y );
		printf( "%.2lf %.2lf\n", atan2(y,x)*180.0/PI, z/s );
	}
	return 0;
}