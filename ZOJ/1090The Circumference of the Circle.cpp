#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void){
	const double pi=3.141592653589793;
	double x1,y1,x2,y2,x3,y3,a,b,c,cos,sin,diameter;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3){
		a=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
		b=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
		c=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
		cos=(a*a+b*b-c*c)/(2*a*b);
		sin=sqrt(1-pow(cos,2));
		diameter=c/sin;
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<diameter*pi<<endl;
	}
	return 0;
}



