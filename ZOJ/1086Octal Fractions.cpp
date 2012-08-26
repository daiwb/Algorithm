#include <iostream>
#include <string>

using namespace std;

int main(void){
	int i,j,len;
	char num[10000];
	while(cin>>num){
		len=strlen(num);
		int a[30000]={0};
		int count=0,add=0,temp;
		for(i=len-1;i>=2;i--){
			add=num[i]-'0';
			for(j=1;j<=count;j++){
				temp=add*10+a[j];
				a[j]=temp/8;
				add=temp%8;
			}
			while(add!=0){
				temp=add*10;
				a[++count]=temp/8;
				add=temp%8;
			}
		}
		cout<<num<<" [8] = "<<
			"0.";
		for(i=1;i<=count;i++) cout<<a[i];
		cout<<" [10]"<<endl;
	}
	return 0;
}

				

