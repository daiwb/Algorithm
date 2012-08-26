/*
ZJU 1189 Numbers That Counts
2004.05.03 By adai
00:00.04 440K
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
	long total,kase,k,i,j,m;	//k:length of loop
	cin>>total;
	for(kase=0;kase<total;kase++){
		if(kase) cout<<endl;
		char input[200];
		char temp[16][200];
		while(1){
			cin>>input;
			if(strcmp(input,"-1")==0) break;
			strcpy(temp[0],input);
			long tlen[16]={0};
			tlen[0]=strlen(temp[0]);
			long step;
			long sign=0;	//0:failed after 15 steps;1:self-inventorying;2:loop
			for(step=0;step<15;step++){
				long dec[10]={0};
				for(i=0;i<tlen[step];i++) dec[temp[step][i]-'0']++;
				j=0;
				for(i=0;i<=9;i++){
					if(dec[i]!=0){
						while(dec[i]>0){
							temp[step+1][j++]=dec[i]%10+'0';
							dec[i]/=10;
						}
						temp[step+1][j++]=i+'0';
					}
				}
				tlen[step+1]=j;
				temp[step+1][j++]='\0';
				if(strcmp(temp[step+1],temp[step])==0){
					sign=1;
					break;
				}
				for(m=step-1;m>=0;m--){
					if(strcmp(temp[step+1],temp[m])==0){
						sign=2;
						k=step+1-m;
						break;
					}
				}
			}
			if(sign==0) cout<<input<<" can not be classified after 15 iterations"<<endl;
			else if(sign==1){
				if(step==0) cout<<input<<" is self-inventorying"<<endl;
				else cout<<input<<" is self-inventorying after "<<step<<" steps"<<endl;
			}
			else{
				cout<<input<<" enters an inventory loop of length "<<k<<endl;
			}
		}
	}
	return 0;
}