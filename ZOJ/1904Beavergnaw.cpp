/*
ZJU 1904 Beavergnaw
2004.06.29 By adai
00:00.00 444K
*/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define PI 3.1415926

int main(void){
    double d,v,r;
    while(cin>>d>>v){
		if(d==0&&v==0) break;
		r=pow(d*d*d-v*6/PI,1.0/3.0);
		printf("%.3lf\n",r);
    }
    return 0;
}
        
