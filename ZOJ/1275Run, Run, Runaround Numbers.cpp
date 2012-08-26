#include <iostream>

using namespace std;

int main(void){
	long num,j,temp,count,judge,judge2,total,all=1;
	int a[7],b[7],c[7],d[10];
	while(cin>>num&&num!=0){
		cout<<"Case "<<all++<<": ";
		for(;;num++){
			for(j=1;j<=9;j++) d[j]=0;
			temp=num;
			count=judge=judge2=total=0;
			while(temp>0){
				a[count]=temp%10;
				if(d[a[count]]==1){
					judge2=1;
					break;
				}
				d[a[count]]++;
				b[count]=0;
				count++;
				temp/=10;
			}
			if(judge2==1) continue;
			for(j=0;j<count;j++) c[j]=a[count-1-j];
			j=0;
			while(1){
				if(b[j]==1){
					if(total==count&&j==0) judge=1;
					break;
				}
				b[j]=1;
				total++;
				j=(j+c[j])%count;
			}
			if(judge==1){
				for(j=0;j<count;j++) cout<<c[j];
				cout<<endl;
				break;
			}
		}
	}
	return 0;
}


			


