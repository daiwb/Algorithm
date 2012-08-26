#include <iostream>
using namespace std;

int main(void)
{
	int i,n,m,count;
	int a[10001];
	int sum[10001];
	int b[5000];
	sum[0]=a[0]=0;
	while(cin>>n>>m){
		count=0;
		for(i=0;i<5000;i++)
			b[i]=0;
		for(i=1;i<=n;i++)
			cin>>a[i];
		for(i=1;i<=n;i++){
			sum[i]=(sum[i-1]+a[i])%m;
			b[sum[i]]++;
		}
		b[0]++;
		for(i=0;i<m;i++)			
			if(b[i]!=0) count+=b[i]*(b[i]-1)/2;
		cout<<count<<endl;
	}
	return 0;
}