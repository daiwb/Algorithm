#include <iostream>
#include <string>

using namespace std;

int main(void){
	int k,temp,i,j,n;
	char clipher[70];
	char plain[70];
	while(cin>>k&&k!=0){
		cin>>clipher;
		n=strlen(clipher);
		for(i=0;i<n;i++){
			if(clipher[i]=='_') temp=0;
			else if(clipher[i]=='.') temp=27;
			else temp=clipher[i]-96;
			temp+=28;
			temp+=i;
			while(temp>27||temp<0){
				if(temp>27) temp-=28;
				else temp+=28;
			}
			j=(k*i)%n;
			if(temp==0) plain[j]='_';
			else if(temp==27) plain[j]='.';
			else plain[j]=temp+96;
		}
		for(i=0;i<n;i++) cout<<plain[i];
		cout<<endl;
	}
	return 0;
}


		
