#include<iostream>
using namespace std;

int main(void){
	long s,p,y,j;
	long a[3];
	long i,m,n;
	while(cin>>s>>p>>y>>j){
		n=0;
		for(i=p;i<=p+1&&n==0;i++){
			for(m=s;m<=s+1&&n==0;m++){
				if((12+j-2*i-m)%3==0&&i+m>=y&&i+m<=y+2){
					a[2]=(12+j-2*i-m)/3;
					a[1]=a[2]+i;
					a[0]=a[1]+m;
					n=1;
				}
			}
		}
		cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
	}
	return 0;
}
