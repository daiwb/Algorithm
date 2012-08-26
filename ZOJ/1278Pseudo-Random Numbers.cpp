#include<iostream>
using namespace std;

int main(void){
	long z,i,m,l,count,j,numcase=1;
	while(cin>>z>>i>>m>>l&&!(z==0&&i==0&&m==0&&l==0)){
		long* num=new long[m];
		for(j=0;j<m;j++)
			num[j]=0;
		num[l=(l*z+i)%m]=1;
		count=0;
		for(;;){
			count++;
			l=(z*l+i)%m;
			if(num[l]==1) break;
			num[l]=1;
		}
		cout<<"Case "<<numcase++<<": "<<count<<endl;
		delete []num;
	}
	return 0;
}

