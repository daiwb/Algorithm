#include<iostream>
using namespace std;

int main(void){
	long d,i,n,count;
	cin>>d;
	for(i=0;i<d;i++){
		cin>>n;
		count=0;
		for(;n>=2;){
			if(n%2==1) cout<<count<<" ";
			count++;
			n/=2;
		}
		cout<<count<<endl;
	}
	return 0;
}
