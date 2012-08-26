#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	int n,b,j,sum,num,k,l;
	char a[10000];
	cin>>n;
	for(j=0;j<n;j++){
		while(cin>>b){
			if(b==0) break;
			cin>>a;
			l=strlen(a);
			sum=num=0;
			for(k=0;k<l;k++){
				sum+=a[k]-'0';
				num=num*b+a[k]-'0';
			}
			if(num%sum==0) cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
		if(j<n-1) cout<<endl;
	}
	return 0;
}