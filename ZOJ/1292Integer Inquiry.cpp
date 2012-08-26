#include <iostream>
#include <cstring>
using namespace std;

int main(void){
	long n,i,j,len1,len2,add,num;
	cin>>n;
	for(i=0;i<n;i++){
		if(i) cout<<endl;
		char* a=new char[120];
		char* b=new char[120];
		char* temp=new char[120];
		char* ans=new char[120];
		cin>>a;
		len1=strlen(a);
		for(j=0;j<len1;j++)
			ans[j]=a[len1-1-j];
		while(cin>>b&&!(b[0]=='0'&&b[1]=='\0')){
			len2=strlen(b);
			add=0;
			for(j=0;j<len2;j++)
				temp[j]=b[len2-1-j];
			for(j=0;j<len1&&j<len2;j++){
				num=ans[j]-'0'+temp[j]-'0'+add;
				if(num>9){
					ans[j]=num-10+'0';
					add=1;
				}
				else{
					ans[j]=num+'0';
					add=0;
				}
			}
			if(len1>len2){
				for(;j<len1;j++){
					num=ans[j]-'0'+add;
					if(num>9){
						ans[j]=num-10+'0';
						add=1;
					}
					else{
						ans[j]=num+'0';
						add=0;
					}
				}
				if(add==1){
					ans[j]=1+'0';
					len1++;
				}
			}
			else if(len1<len2){
				for(;j<len2;j++){
					num=temp[j]-'0'+add;
					if(num>9){
						ans[j]=num-10+'0';
						add=1;
					}
					else{
						ans[j]=num+'0';
						add=0;
					}
				}
				if(add==1){
					ans[j]=1+'0';
					len1=len2+1;
				}
				else len1=len2;
			}
			else{
				if(add==1){
					ans[j]=1+'0';
					len1++;
				}
			}
		}
		for(j=len1-1;j>=0;j--)
			cout<<ans[j];
		cout<<endl;
		delete []a;
		delete []b;
		delete []ans;
		delete []temp;
	}
	return 0;
}



