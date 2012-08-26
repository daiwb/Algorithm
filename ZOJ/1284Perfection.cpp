#include<iostream>
#include<iomanip>
using namespace std;

int main(void){
	long n,i,sum,j=0;
	while(cin>>n&&n!=0){
		if(j==0) cout<<"PERFECTION OUTPUT"<<endl;
		sum=0;
		for(i=1;i<=n/2;i++)
			if(n%i==0) sum+=i;
		cout.width(5);
		cout<<n<<"  ";
		if(sum==n) cout<<"PERFECT"<<endl;
		else if(sum>n) cout<<"ABUNDANT"<<endl;
		else cout<<"DEFICIENT"<<endl;
		j++;
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}
