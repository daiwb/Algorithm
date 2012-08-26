#include <iostream>
using namespace std;

int main(void)
{
	int d,i,j,k,t,count,temp;
	cin>>d;
	for(i=0;i<d;i++){
		count=0;
		cin>>t;
		count=0;
		for(j=1;j<=t;j++){
			temp=0;
			for(k=1;k<=j;k++)
				if(j%k==0) temp=(temp+1)%2;
			if(temp==1) count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
			

