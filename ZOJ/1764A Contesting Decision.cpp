/*ZJU 1764 Contesting Decision
2004.04.21 By adai
00:00.00 436K*/

#include <iostream>
#include <cstring>
using namespace std;

class cteam{
public:
	char name[40];
	long num,pp;
	cteam(){
		num=pp=0;
	}
	cteam &operator = (const cteam &c){
		strcpy(name,c.name);
		num=c.num;
		pp=c.pp;
		return *this;
	}
};


int main(){
	long n,i,j,sub,time;
	while(cin>>n){
		cteam* team=new cteam[n];
		for(i=0;i<n;i++){
			cin>>team[i].name;
			for(j=0;j<4;j++){
				cin>>sub>>time;
				if(time!=0){
					team[i].num++;
					team[i].pp+=time+(sub-1)*20;
				}
			}
		}
		cteam next;
		long p,q;
		for(p=1;p<n;p++){
			next=team[p];
			for(q=p-1;q>=0;q--){
				if(next.num>team[q].num||(next.num==team[q].num&&next.pp<team[q].pp)) break;
				team[q+1]=team[q];
			}
			team[q+1]=next;
		}
		cout<<team[n-1].name<<" "<<team[n-1].num<<" "<<team[n-1].pp<<endl;
		delete []team;
	}
	return 0;
}