#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	double humble[5842],temp;
	long i,j,m,n,index=0,next,num;
	for(i=0;i<=31;i++){
		temp=pow(2,i);
		if(temp>2000000000) break;
		for(j=0;j<=20;j++){
			temp=pow(2,i)*pow(3,j);
			if(temp>2000000000) break;
			for(m=0;m<=14;m++){
				temp=pow(2,i)*pow(3,j)*pow(5,m);
				if(temp>2000000000) break;
				for(n=0;n<=12;n++){
					temp=pow(2,i)*pow(3,j)*pow(5,m)*pow(7,n);
					if(temp<=2000000000) humble[index++]=temp;
					else break;
				}
			}
		}
	}
	for(i=1;i<5842;i++){
		next=humble[i];
		for(j=i-1;j>=0&&next<humble[j];j--)
			humble[j+1]=humble[j];
		humble[j+1]=next;
	}
	while(cin>>num&&num!=0){
		cout<<"The "<<num;
		if(num%10==1&&num%100!=11) cout<<"st";
		else if(num%10==2&&num%100!=12) cout<<"nd";
		else if(num%10==3&&num%100!=13) cout<<"rd";
		else cout<<"th";
		cout<<" humble number is "<<(long)humble[num-1]<<"."<<endl;
	}
	return 0;
}




