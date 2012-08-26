#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define pi acos(0.0+-1)


int main(void){
	double x1,y1,r1,x2,y2,r2,r,rmin,rmax,area,len,arc1,arc2,s1,s2;
	while(cin>>x1>>y1>>r1>>x2>>y2>>r2){
		r=sqrt(0.0+pow(x1-x2,2)+pow(y1-y2,2));
		rmin=r1<r2?r1:r2;
		rmax=r1+r2-rmin;
		if(rmax<=r){
			if(rmin<=r-rmax) area=0;
			else{
				len=sqrt(0.0+rmin*rmin-pow((r*r+rmin*rmin-rmax*rmax)/2/r,2));
				arc1=2*asin(len/rmax);
				arc2=2*asin(len/rmin);
				s1=arc1*rmax*rmax/2-len*sqrt(0.0+rmax*rmax-len*len);
				s2=arc2*rmin*rmin/2-len*sqrt(0.0+rmin*rmin-len*len);
				area=s1+s2;
			}
		}
		else{
			if(rmin<=rmax-r) area=pi*rmin*rmin;
			else if(rmin<=sqrt(0.0+rmax*rmax-r*r)){
				len=sqrt(0.0+rmin*rmin-pow((rmax*rmax-rmin*rmin-r*r)/2/r,2));
				arc1=2*asin(len/rmax);
				arc2=2*asin(len/rmin);
				s1=arc1*rmax*rmax/2-len*sqrt(0.0+rmax*rmax-len*len);
				s2=arc2*rmin*rmin/2-len*sqrt(0.0+rmin*rmin-len*len);
				s2=pi*rmin*rmin-s2;
				area=s1+s2;
			}
			else{
				len=sqrt(0.0+rmin*rmin-pow((r*r+rmin*rmin-rmax*rmax)/2/r,2));
				arc1=2*asin(len/rmax);
				arc2=2*asin(len/rmin);
				s1=arc1*rmax*rmax/2-len*sqrt(0.0+rmax*rmax-len*len);
				s2=arc2*rmin*rmin/2-len*sqrt(0.0+rmin*rmin-len*len);
				area=s1+s2;
			}
		}
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<area<<endl;
	}
	return 0;
}





		
