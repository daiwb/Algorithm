/*ZJU 1737 Unreliable Message
2004.04.07 By adai
00:00.00 436K*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
	long n,leno,lenm,i,j;
	cin>>n;
	char order[7];
	char msg[26];
	char temp[27];
	while(n--){
		cin>>order>>msg;
		leno=strlen(order);
		lenm=strlen(msg);
		for(j=leno-1;j>=0;j--){
			if(order[j]=='J'){
				for(i=0;i<lenm-1;i++) temp[i+1]=msg[i];
				temp[0]=msg[lenm-1];
				for(i=0;i<lenm;i++) msg[i]=temp[i];
			}
			else if(order[j]=='C'){
				for(i=1;i<lenm;i++) temp[i-1]=msg[i];
				temp[lenm-1]=msg[0];
				for(i=0;i<lenm;i++) msg[i]=temp[i];
			}
			else if(order[j]=='E'){
				long half=lenm/2,s=(lenm+1)/2;
				for(i=0;i<half;i++) temp[i+s]=msg[i];
				for(i=s;i<lenm;i++) temp[i-s]=msg[i];
				if(lenm%2==1) temp[lenm/2]=msg[lenm/2];
				for(i=0;i<lenm;i++) msg[i]=temp[i];
			}
			else if(order[j]=='A'){
				for(i=0;i<lenm;i++) temp[i]=msg[lenm-1-i];
				for(i=0;i<lenm;i++) msg[i]=temp[i];
			}
			else if(order[j]=='P'){
				for(i=0;i<lenm;i++){
					if(msg[i]>='0'&&msg[i]<='9'){
						if(msg[i]=='0') msg[i]='9';
						else msg[i]-=1;
					}
				}
			}
			else if(order[j]=='M'){
				for(i=0;i<lenm;i++){
					if(msg[i]>='0'&&msg[i]<='9'){
						if(msg[i]=='9') msg[i]='0';
						else msg[i]+=1;
					}
				}
			}
		}
		msg[lenm]='\0';
		cout<<msg<<endl;
	}
	return 0;
}

