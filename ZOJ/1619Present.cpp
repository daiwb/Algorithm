/*ZJU 1619 Present
2004.04.21 By adai
00:00.04 436K*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	long n,m,i;
	while(cin>>n>>m){
		double pro;
		if(n==m){
			pro=1;
			for(i=2;i<=n;i++) pro/=i;
			cout<<setiosflags(ios::fixed)<<setprecision(8)<<pro<<endl;
			continue;
		}
		if(n==m-1){
			cout<<"0.00000000"<<endl;
			continue;
		}
		pro=0;
		long sigh(1),dif(n-m);
		double temp(1);
		for(i=2;i<=dif;i++){
			temp/=i;
			pro+=sigh*temp;
			sigh*=-1;
		}
		for(i=2;i<=m;i++) pro/=i;
		cout<<setiosflags(ios::fixed)<<setprecision(8)<<pro<<endl;
	}
	return 0;
}