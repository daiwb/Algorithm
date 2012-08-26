//Calendar

#include <iostream>

using namespace std;

int main(void){
	int n,m,i,sum=0;
	int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	cin>>n>>m;
	if(n>month[m]){
		cout<<"Impossible"<<endl;
		return 0;
	}
	for(i=1;i<m;i++) sum+=month[i];
	sum+=n;
	sum%=7;
	if(sum==0) sum=7;
	cout<<sum<<endl;
	return 0;
}


