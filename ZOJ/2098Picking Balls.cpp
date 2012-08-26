//zju 2098 Picking Balls

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	long n,k,i,j;
	while(cin>>n>>k){
		if(n==-1&&k==-1) break;
		long* m=new long[n];
		long* p=new long[n];
		long sum(0);
		for(i=0;i<n;i++){
			cin>>m[i];
			sum+=m[i];
		}
		for(i=0;i<n;i++) cin>>p[i];
		bool sign(0);
		for(i=0;i<n;i++){
			if(p[i]>m[i]){
				sign=1;
				break;
			}
		}
		if(sign==1){
			cout<<"0.00000"<<endl;
			continue;
		}
		for(i=0;i<n;i++) p[i]=p[i]<(m[i]-p[i])?p[i]:(m[i]-p[i]);
		double rate(1);
		k=k<(sum-k)?k:(sum-k);
		for(i=1;i<=k;i++) rate*=double(i)/double(sum-k+i);
		for(i=0;i<n;i++){
			for(j=1;j<=p[i];j++) rate*=double(m[i]-p[i]+j)/double(j);
		}
		cout<<setiosflags(ios::fixed)<<setprecision(5)<<rate<<endl;
		delete []m;
		delete []p;
	}
	return 0;
}
