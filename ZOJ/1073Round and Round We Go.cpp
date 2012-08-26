#include <iostream>
#include <cstring>
using namespace std;

int main(void){
	char num[60];
	int i,j,t,m,index,length,add,judge2,judge3,dai;
	while(cin>>num){
		length=strlen(num);
		char cycle[60][60];
		char temp[60];
		for(i=0;i<length;i++){
			for(j=0;j<length-i-1;j++)
				cycle[i][j]=num[i+j+1];
			index=0;
			for(;j<length;j++)
				cycle[i][j]=num[index++];
		}
		judge2=0;
		for(t=1;t<=length;t++){
			if(judge2==1) break;
			add=0;
			for(i=length-1;i>=0;i--){
				dai=(num[i]-'0')*t+add;
				if(dai>9){
					add=dai/10;
					temp[i]=dai-10*add+'0';
				}
				else{
					temp[i]=dai+'0';
					add=0;
				}
			}
			if(add>=1){
				judge2=1;
				break;
			}
			judge2=1;
			for(j=0;j<length;j++){
				judge3=0;
				for(m=0;m<length;m++){
					if(temp[m]!=cycle[j][m]){
						judge3=1;
						break;
					}
				}
				if(judge3==1) continue;
				else{
					judge2=0;
					continue;
				}
			}
		}
		if(judge2==0) cout<<num<<" is cyclic"<<endl;
		else cout<<num<<" is not cyclic"<<endl;
	}
	return 0;
}
			




