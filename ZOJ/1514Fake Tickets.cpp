#include <iostream>

using namespace std;

int main(void){
	int n,m,i,a,count;
	while(cin>>n>>m&&!(n==0&&m==0)){
		count=0;
		int* num=new int[n+1];
		for(i=1;i<=n;i++) num[i]=0;
		for(i=1;i<=m;i++){
			cin>>a;
			num[a]++;
		}
		for(i=1;i<=n;i++){
			if(num[i]>1) count++;
		}
		cout<<count<<endl;
		delete []num;
	}
	return 0;
}


