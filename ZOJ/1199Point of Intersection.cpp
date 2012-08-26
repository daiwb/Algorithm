#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(void){
	long n,i;
	double x1,y1,r1,x2,y2,r2,r,rmin,ratio,xr,yr;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x1>>y1>>r1;
		cin>>x2>>y2>>r2;
		if(r1==r2){
			cout<<"Impossible."<<endl;
			continue;
		}
		r=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
		if(r<=fabs(r2-r1)){
			cout<<"Impossible."<<endl;
			continue;
		}
		rmin=r1<r2?r1:r2;
		ratio=rmin/fabs(r2-r1);
		if(r2<r1){
			xr=x2+ratio*(x2-x1);
			yr=y2+ratio*(y2-y1);
		}
		else{
			xr=x1+ratio*(x1-x2);
			yr=y1+ratio*(y1-y2);
		}
		cout<<setiosflags(ios::fixed)<<setprecision(2)
			<<xr<<" "<<yr<<endl;
	}
	return 0;
}


		
		
