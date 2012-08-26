#include <iostream>
using namespace std;

int main(void)
{
	int n,p,e,i,j,d,t,count;
	cin>>n;
	for(t=0;t<n;t++){
		count=1;
		if(t) cout<<endl;
		while(cin>>p>>e>>i>>d&&!(p==-1&&e==-1&&i==-1&&d==-1)){
			p%=23;
			e%=28;
			i%=33;
			p=(d+23-p)%23;
			e=(d+28-e)%28;
			i=(d+33-i)%33;
			for(j=1;;j++){
				if((j+i)%33==0) break;
			}
			for(;;j+=33)
				if((j+p)%23==0&&(j+e)%28==0) break;
			cout<<"Case "<<count++<<": the next triple peak occurs in "<<j<<" days."<<endl;
		}
	}
	return 0;
}
