//Coprimes

#include <iostream>

using namespace std;

int main(void){
	int n;
	cin>>n;
	if(n==1||n==2){
		cout<<1<<endl;
		return 0;
	}
	if(n==3){
		cout<<2<<endl;
		return 0;
	}
	int* b=new int[n+1];
	int i,j,sum=0;
	for(i=1;i<=n;i++) b[i]=0;
	for(i=2;i<=n/2;i++){
		if(n%i==0){
			for(j=1;i*j<=n;j++) b[i*j]=1;
		}
	}
	for(i=1;i<n;i++){
		if(b[i]==0) sum++;
	}
	cout<<sum<<endl;
	delete []b;
	return 0;
}

