#include <iostream>

using namespace std;

int main(void){
	int n,i;
	while(cin>>n&&n!=0){
		int sum=0,total=0;
		int* num=new int[n+1];
		for(i=1;i<=n;i++){
			cin>>num[i];
			sum+=num[i];
		}
		if(sum%2==1){
			cout<<"No equal partitioning."<<endl;
			continue;
		}
		sum/=2;
		for(i=1;;i++){
			total+=num[i];
			if(total==sum){
				cout<<"Sam stops at position "<<i
					<<" and Ella stops at position "<<i+1<<"."<<endl;
				break;
			}
			if(total>sum){
				cout<<"No equal partitioning."<<endl;
				break;
			}
		}
		delete []num;
	}
	return 0;
}


