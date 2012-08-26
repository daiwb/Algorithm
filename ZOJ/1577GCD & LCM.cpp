#include <iostream>
using namespace std;

int main(void)
{
	long data,x,y,i,sum;
	while(cin>>x>>y){
		if(x==y){
			cout<<"1"<<endl;
			continue;
		}
		if(y%x!=0){
			cout<<"0"<<endl;
			continue;
		}
		sum=1;
		data=y/x;
		for(i=2;i<=data;i++){
			if(data%i==0){
				sum*=2;
				while(data%i==0)
					data/=i;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
