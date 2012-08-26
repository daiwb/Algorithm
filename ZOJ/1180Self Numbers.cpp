/*00:00.60 4336K*/

#include<iostream>
using namespace std;

long d(long i){
	long sum=i;
	while(i>=1){
		sum+=i%10;
		i/=10;
		if(sum>1000000) break;
	}
	return sum;
}

int main(void){
	long* a=new long[1000001];
	long i;
	for(i=1;i<=1000000;i++)
		a[i]=0;
	for(i=1;i<=1000000;i++)
		if(d(i)<=1000000) a[d(i)]=1;
	for(i=1;i<=1000000;i++)
		if(a[i]==0) cout<<i<<endl;
	delete []a;
	return 0;
}