/*
zju 1496Best Fit
00:00.00 436k
2004.08.08 by adai
*/

#include <iostream>
#include <cmath>
using namespace std;

#ifdef WIN32
#define for if (0); else for
#endif

#define PI 3.14159

int main() {
	cout.setf(ios::fixed);
	cout.precision(3);
	double f[3], r[9], diameter, d, cir;
	int kase;
	cin >> kase;
	for (int t = 0; t < kase; t ++)	{
		if (t) cout << endl;
		for (int i = 0; i < 3; i ++) cin >> f[i];
		for (int i = 0; i < 9; i ++) cin >> r[i];
		cin >> d >> diameter;
		cir = d * PI;
	
		int indexf, indexr;
		int first = 1;
		double dx;
		for (int i = 0; i < 3; i ++) {
			for (int j = 0; j < 9; j ++) {
				if (first) {
					dx = fabs(f[i] / r[j] * cir - diameter);
					indexf = i;
					indexr = j;
					first = 0;
				}
				else {
					double temp = fabs(f[i] / r[j] * cir - diameter);
					if (temp < dx) {
						dx = temp;
						indexf = i;
						indexr = j;
					}
				}
			}
		}
		double d;
		d = f[indexf] / r[indexr] * cir;
		cout << "A gear selection of " << (int)f[indexf] << "/" << (int)r[indexr] << " produces a gear size of " << d << "." << endl;
	}
	return 0;
}
