#include<iostream>
#include<cmath>
using namespace std;

int main(void){
	double r[16],g[16],b[16],temp;
	double x,y,z;
	int num,i,j;
	for(i=0;i<16;i++)
		cin>>r[i]>>g[i]>>b[i];
	while(cin>>x>>y>>z&&!((long)x==-1&&(long)y==-1&&(long)z==-1)){
		num=0;
		temp=sqrt(pow(x-r[0],2)+pow(y-g[0],2)+pow(z-b[0],2));
		for(j=1;j<16;j++){
			if(sqrt(pow(x-r[j],2)+pow(y-g[j],2)+pow(z-b[j],2))<temp){
				temp=sqrt(pow(x-r[j],2)+pow(y-g[j],2)+pow(z-b[j],2));
				num=j;
			}
		}
		cout<<"("<<(long)x<<","<<(long)y<<","<<(long)z<<") maps to ("
			<<r[num]<<","<<g[num]<<","<<b[num]<<")"<<endl;
	}
	return 0;
}



