#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	long d,n,i;
	double ans;
	cin>>d;
	while(d--){
		cin>>n;
		ans=0;
		for(i=1;i<=n;i++)
			ans+=log10(i+0.0);
		cout<<(long)ans+1<<endl;
	}return 0;
}

