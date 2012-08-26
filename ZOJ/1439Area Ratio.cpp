#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(void)
{
	double x1,x2,x3,y1,y2,y3,z1,z2,z3;
	double a,b,c,cos1,cos2,cos3,sin1,r1,r2,temp1,temp2,temp3,cos21,sin21;
	while(cin>>x1>>y1>>z1>>x2>>y2>>z2>>x3>>y3>>z3){
		a=sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));
		b=sqrt(pow(x1-x3,2)+pow(y1-y3,2)+pow(z1-z3,2));
		c=sqrt(pow(x2-x3,2)+pow(y2-y3,2)+pow(z2-z3,2));
		cos1=(b*b+c*c-a*a)/(2*b*c);
		cos2=(a*a+c*c-b*b)/(2*a*c);
		cos3=(a*a+b*b-c*c)/(2*a*b);
		sin1=sqrt(1-pow(cos1,2));
		r2=a/(2*sin1);
		temp1=sqrt(2*pow((b+c-a)/2,2)*(1-cos1));
		temp2=sqrt(2*pow((a+c-b)/2,2)*(1-cos2));
		temp3=sqrt(2*pow((a+b-c)/2,2)*(1-cos3));
		cos21=(temp2*temp2+temp3*temp3-temp1*temp1)/(2*temp2*temp3);
		sin21=sqrt(1-pow(cos21,2));
		r1=temp1/(2*sin21);
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<pow(r1,2)/pow(r2,2)<<endl;
	}
		return 0;
}
	