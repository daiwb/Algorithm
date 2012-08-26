//ZOJ Monthly, September 2003 Contest
//1008 Circuit Board
//ZJU 1648 Circuit Board
//2003.09.21 BY adai
//00:00.24 504K

#include <iostream>

using namespace std;

int main(void){
	int n,i,j;
	while(cin>>n){
		double* x1=new double[n];
		double* y1=new double[n];
		double* x2=new double[n];
		double* y2=new double[n];
		double temp;
		int t=0;
		for(i=0;i<n;i++){
			cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
			if(x1[i]>x2[i]){
				temp=x1[i];
				x1[i]=x2[i];
				x2[i]=temp;
				temp=y1[i];
				y1[i]=y2[i];
				y2[i]=temp;
			}
			if(y1[i]>y2[i]){
				temp=y1[i];
				y1[i]=y2[i];
				y2[i]=temp;
			}
		}
		for(i=0;i<n-1;i++){
			if(t==1) break;
			for(j=i+1;j<n;j++){
				if(x1[i]==x2[i]&&x1[j]==x2[j]){
					if(x1==x2){
						t=1;
						break;
					}
				}
				else if(x1[i]==x2[i]){
					double a,b,c;
					a=(y2[j]-y1[j])/(x2[j]-x1[j]);
					b=y1[j]-a*x1[j];
					c=a*x1[i]+b;
					if(c>=y1[i]&&c<=y2[i]){
						t=1;
						break;
					}
				}
				else if(x1[j]==x2[j]){
					double a,b,c;
					a=(y2[i]-y1[i])/(x2[i]-x1[i]);
					b=y1[i]-a*x1[i];
					c=a*x1[j]+b;
					if((c>=y1[j]&&c<=y2[j])||(c>=y2[j]&&c<=y1[j])){
						t=1;
						break;
					}
				}
				else{
					double a1,b1,a2,b2,xr,yr;
					a2=(y2[j]-y1[j])/(x2[j]-x1[j]);
					b2=y1[j]-a1*x1[j];
					a1=(y2[i]-y1[i])/(x2[i]-x1[i]);
					b1=y1[i]-a1*x1[i];
					if(a1==a2){
						if(b1==b2){
							if((x1[j]>=x1[i]&&x1[j]<=x2[i])||(x2[j]>=x1[i]&&x2[j]<=x2[i])){
								t=1;
								break;
							}
						}
						continue;
					}
					xr=(b2-b1)/(a1-a2);
					yr=a1*xr+b1;
					if(yr>=y1[i]&&yr<=y2[i]&&yr>=y1[j]&&yr<=y2[j]){
						t=1;
						break;
					}
				}
			}
		}
		if(t==0) cout<<"ok!"<<endl;
		else cout<<"burned!"<<endl;
		delete []x1;
		delete []y1;
		delete []x2;
		delete []y2;
	}
	return 0;
}
					


					

				
