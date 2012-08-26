/*
ZJU 1463 Brackets Sequence
00:00.06 480K
2004.07.07 By adai
*/

#include <cstring>
#include <iostream>
using namespace std;

#define MAXN 100

char input[MAXN+1];
char output[MAXN][3];
int d[MAXN][MAXN];

int min(int a,int b){
	if(a<b) return a;
	return b;
}

int bracket(int i,int j){
	int k,idx;
	int answer;
	int sign=0;
	if(i>j) return 0;
	else if(i==j){
		if(input[i]=='(') output[i][2]=')';
		else if(input[i]=='[') output[i][2]=']';
		else if(input[i]==')') output[i][0]='(';
		else if(input[i]==']') output[i][0]='[';
		return 1;
	}
	else{
		answer=1000;
		if((input[i]=='('&&input[j]==')')||(input[i]=='['&&input[j]==']')){
			answer=min(answer,d[i+1][j-1]);
			sign=1;
		}
		if(input[i]=='('||input[i]=='['){
			if(d[i+1][j]+1<answer){
				answer=d[i+1][j]+1;
				sign=2;
			}
		}
		if(input[j]==')'||input[j]==']'){
			if(d[i][j-1]+1<answer){
				answer=d[i][j-1]+1;
				sign=3;
			}
		}
        for(k=i;k<=j-1;k++){
			if(d[i][k]+d[k+1][j]<answer){
				answer=d[i][k]+d[k+1][j];
				sign=4;
				idx=k;
			}
        }
	}
	if(sign==1){
		bracket(i+1,j-1);
	}
	else if(sign==2){
		if(input[i]=='('){
			output[i][2]=')';
		}
		else if(input[i]=='['){
			output[i][2]=']';
		}
		bracket(i+1,j);
	}
	else if(sign==3){
		if(input[j]==')'){
			output[j][0]='(';
		}
		else if(input[j]==']'){
			output[j][0]='[';
		}
		bracket(i,j-1);
	}
	else if(sign==4){
		bracket(i,idx);
		bracket(idx+1,j);
	}
	return 0;
}

int main(){
	int num,i,j,p,k,kase=0,n;
	char ch;
	cin>>num;
	while(num--){
		//cin>>ch;
		cin>>input;
		n=strlen(input);
		if(kase++) cout<<endl;
		
		/* DP to get the minimum number of brackets to insert */
		for(i=1;i<n;i++) d[i][i-1]=0;
		for(i=0;i<n;i++) d[i][i]=1;
		for(p=1;p<=n-1;p++){
			for(i=0;i<=n-1-p;i++){
				j=i+p;
				d[i][j]=1000;
				if((input[i]=='('&&input[j]==')')||(input[i]=='['&&input[j]==']'))
					d[i][j]=min(d[i][j],d[i+1][j-1]);
				if(input[i]=='('||input[i]=='[')
					d[i][j]=min(d[i][j],d[i+1][j]+1);
				if(input[j]==')'||input[j]==']')
					d[i][j]=min(d[i][j],d[i][j-1]+1);
				for(k=i;k<=j-1;k++)
					d[i][j]=min(d[i][j],d[i][k]+d[k+1][j]);
			}
		}
		/* DP end here */
		
		/*
		printf("minimum number is %d\n",d[0][n-1]);
		for(i=0;i<n;i++){
		for(j=0;j<n;j++) printf("%d ",d[i][j]);
		printf("\n");
		}
		*/
		
		for(i=0;i<n;i++){
			output[i][0]=output[i][2]='.';
			output[i][1]=input[i];
		}
		bracket(0,n-1);
		
		/* output */
		for(i=0;i<n;i++){
			for(j=0;j<3;j++){
				if(output[i][j]!='.') cout<<output[i][j];
			}
		}
		cout<<endl;
		
	}
	return 0;
}