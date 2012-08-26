//ZOJ Monthly, September 2003 Contest
//1001 Analyse the Bridge Note
//ZJU 1641 Analyse the Bridge Note
//2003.09.21 BY adai
//00:00.00 436K

#include <iostream>

using namespace std;

int main(void){
	char temp[4];
	while(cin>>temp){
		int n=temp[0]-'0'+6;
		//cout<<"n="<<n<<endl;
		char king,first;
		king=temp[1];
		int win=0,i,j;
		int t=1,max;//t＝0表示庄家先出
		char card[4][3];
		int num[4];
		for(i=0;i<13;i++){
			for(j=0;j<4;j++){
				cin>>card[j];
				first=card[0][0];
				if(card[j][0]==king) num[j]=6;
				else if(card[j][0]==first) num[j]=5;
				else if(card[j][0]=='C') num[j]=1;
				else if(card[j][0]=='D') num[j]=2;
				else if(card[j][0]=='H') num[j]=3;
				else num[j]=4;
				num[j]*=100;
				if(card[j][1]=='A') num[j]+=14;
				else if(card[j][1]=='K') num[j]+=13;
				else if(card[j][1]=='Q') num[j]+=12;
				else if(card[j][1]=='J') num[j]+=11;
				else if(card[j][1]=='T') num[j]+=10;
				else num[j]+=card[j][1]-'0';
				//cout<<num[j]<<" ";
			}
			//cout<<endl;
			max=0;
			for(j=1;j<4;j++) if(num[j]>num[max]) max=j;
			if(t==0){
				if(max%2==0) win++;
				else t=1;
			}
			else{
				if(max%2==1){
					win++;
					t=0;
				}
			}
			//cout<<"win="<<win<<endl;
			//cout<<"t="<<t<<endl;
		}
		cout<<temp;
		if(win==n) cout<<"MK"<<endl;
		else if(win<n) cout<<"-"<<n-win<<endl;
		else cout<<"+"<<win-n<<endl;
	}
	return 0;
}


			
