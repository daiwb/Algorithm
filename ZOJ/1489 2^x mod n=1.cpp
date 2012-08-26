#include <iostream>
using namespace std;

int main(void)
{
	long n,i,j,k,t;
	while(cin>>n){
		if(n%2==0) cout<<"2^? mod "<<n<<" = 1"<<endl;
		else{
			i=4;
			t=2;
			j=2%n;
			k=i%n;
			while(k!=1){
				if(k==j) break;
				t++;
				k=(k*2)%n;
			}
			if(k!=1) cout<<"2^? mod "<<n<<" = 1"<<endl;
			else cout<<"2^"<<t<<" mod "<<n<<" = 1"<<endl;
		}
	}
	return 0;
}
