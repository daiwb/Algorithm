//The Sum

#include <iostream>
using namespace std;

int main(void){
	long i,k,sum=0;
	cin>>k;
	long* num=new long[k+1];
	if(k==1) cout<<1<<endl;
	else if(k==2) cout<<2<<endl;
	else{
		num[1]=num[2]=1;
		sum=2;
		for(i=3;i<=k;i++){
			num[i]=num[i-1]+num[i-2];
			sum+=num[i];
		}
		cout<<sum<<endl;
	}
	delete []num;
	return 0;
}


