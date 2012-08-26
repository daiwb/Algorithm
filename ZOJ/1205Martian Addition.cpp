#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char a[100],b[100],t[100];
	int lengtha,lengthb,length,i,j,tempa,tempb;
	while(cin>>a>>b){
		j=0;
		lengtha=strlen(a);
		lengthb=strlen(b);
		length=lengtha>lengthb?lengtha:lengthb;
		for(i=0;;i++){
			if(lengtha-i-1<0||lengthb-i-1<0)
				break;
			if(a[lengtha-i-1]>='0'&&a[lengtha-i-1]<='9') tempa=a[lengtha-i-1]-'0';
			else tempa=a[lengtha-i-1]-'a'+10;
			if(b[lengthb-i-1]>='0'&&b[lengthb-i-1]<='9') tempb=b[lengthb-i-1]-'0';
			else tempb=b[lengthb-i-1]-'a'+10;
			t[length-i-1]=tempa+tempb+j;
			if(t[length-i-1]>=20){
				t[length-i-1]-=20;
				j=1;
			}
			else j=0;
			if(t[length-i-1]>=0&&t[length-i-1]<=9) t[length-i-1]+='0';
			else t[length-i-1]+='a'-10;
		}
		if(lengtha>lengthb){
			for(;lengtha-i-1>=0;i++){
				t[length-i-1]=a[lengtha-i-1]+j;
				if(t[length-i-1]=='k'){
					t[length-i-1]='0';
					j=1;
				}
				else j=0;
			}
		}
		if(lengtha<lengthb){
			for(;lengthb-i-1>=0;i++){
				t[length-i-1]=b[lengthb-i-1]+j;
				if(t[length-i-1]=='k'){
					t[length-i-1]='0';
					j=1;
				}
				else j=0;
			}
		}
		if(j==1) cout<<"1";
		for(i=0;i<length;i++)
			cout<<t[i];
		cout<<endl;
	}
	return 0;
}




