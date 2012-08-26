/*ZJU 1091 Knight Moves
2004.04.23 By adai
00:00.04 436K*/

//搜索 bfs

#include <iostream>
#include <cstdio>
using namespace std;

class tkp{
public:
	long row;
	long col;
	long sign;		//标志是否已被访问过
	tkp* next;
};

long stepi[8]={-2,-1,1,2,2,1,-1,-2};
long stepj[8]={-1,-2,-2,-1,1,2,2,1};

int main(){
	char input[2][3];
	long srow,scol,drow,dcol,i,j,min,t,sign,quit;
	tkp *head,*cur,*temp;
	tkp mat[9][9];
	for(i=1;i<=8;i++){
		for(j=1;j<=8;j++){
			mat[i][j].row=i;
			mat[i][j].col=j;
		}
	}
	while(cin>>input[0]){
		cin>>input[1];
		for(i=1;i<=8;i++){
			for(j=1;j<=8;j++){
				mat[i][j].sign=0;
				mat[i][j].next=NULL;
			}
		}
		srow=input[0][1]-'1'+1;
		scol=input[0][0]-'a'+1;
		drow=input[1][1]-'1'+1;
		dcol=input[1][0]-'a'+1;
		head=&mat[srow][scol];
		min=0;
		if(!(srow==drow&&scol==dcol)){
			mat[srow][scol].sign=1;
			while(1){
				min++;		//需要的步数加一
				sign=quit=0;
				cur=temp=head;
				while(temp!=NULL){
					for(t=0;t<8;t++){
						if((*temp).row+stepi[t]<1) continue;
						if((*temp).row+stepi[t]>8) continue;
						if((*temp).col+stepj[t]<1) continue;
						if((*temp).col+stepj[t]>8) continue;

						//已被访问过
						if(mat[(*temp).row+stepi[t]][(*temp).col+stepj[t]].sign==1) continue;
						
						mat[(*temp).row+stepi[t]][(*temp).col+stepj[t]].sign=1;
						
						//找到
						if((*temp).row+stepi[t]==drow&&(*temp).col+stepj[t]==dcol){
							quit=1;
							break;
						}
						if(sign==0){
							head=&mat[(*temp).row+stepi[t]][(*temp).col+stepj[t]];
							cur=head;
							sign=1;
						}
						else{
							(*cur).next=&mat[(*temp).row+stepi[t]][(*temp).col+stepj[t]];
							cur=(*cur).next;
						}
					}
					if(quit==1) break;
					temp=(*temp).next;
				}
				(*cur).next=NULL;
				if(quit==1) break;
			}
		}
		cout<<"To get from "<<input[0]<<" to "<<input[1]<<" takes "<<min<<" knight moves."<<endl;
	}
	return 0;
}