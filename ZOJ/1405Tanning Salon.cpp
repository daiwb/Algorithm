#include <iostream>

using namespace std;

int main(void){
	int n,i,t;
	while(cin>>n&&n!=0){
		char a[10000];
		cin>>a;
		int b[26]={0};
		int count=0,num=0;
		for(i=0;a[i]!='\0';i++){
			t=a[i]-65;
			if(b[t]==0){
				if(count<n){
					count++;
					b[t]=1;
				}
				else{
					b[t]=2;
				}
			}
			else if(b[t]==1) count--;
			else num++;
		}
		if(num==0) cout<<"All customers tanned successfully."<<endl;
		else cout<<num<<" customer(s) walked away."<<endl;
	}
	return 0;
}
			



