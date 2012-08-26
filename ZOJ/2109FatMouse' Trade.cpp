/*
zju 2109 FatMouse' Trade
00:00.11 484k
2004.08.04 by adai
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

class fatmouse{
public:
	int javabean;
	int food;
	double ratio;
};

double eps = 1e-8;

int cmp(const void *t1,const void *t2) 
{ 
	fatmouse *a, *b; 
	a = (fatmouse *)t1;
	b = (fatmouse *)t2;
	if(fabs((*a).ratio - (*b).ratio) < eps) return 0;
	else if((*a).ratio - (*b).ratio > eps) return -1; 
	return 1;
} 

int main(){
	cout.setf(ios::fixed);
	cout.precision(3);
	int m, n;
	while(1){
		cin >> m >> n;
		if(m == -1 && n == -1) break;
		fatmouse* a = new fatmouse[n];
		for(int i = 0; i < n; i ++){
			cin >> a[i].javabean >> a[i].food;
			a[i].ratio = 1.0 * a[i].javabean / a[i].food;
		}
		qsort(a, n, sizeof(fatmouse), cmp);
		double max = 0;
		for(int i = 0; i < n; i ++){
			if(m < a[i].food){
				max += m * a[i].ratio;
				break;
			}
			max += a[i].javabean;
			m -= a[i].food;
		}
		cout << max << endl;
		delete []a;
	}
	return 0;
}
