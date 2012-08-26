/*
ZJU 1103 Hike on a Graph
00:00.09 4348
2004.07.14 by adai
*/

#include <iostream>
using namespace std;

class state{
public:
	int x;
	int y;
	int z;
	int visited;
	state &operator=(const state &c){
		x=c.x;
		y=c.y;
		z=c.z;
		visited=c.visited;
		return *this;
	}
}a[50][50][50];

state queue[50*50*50];
int n;
char color[50][50];
int head,tail;
int nhead,ntail;
int depth;

void order(int &p1,int &p2,int &p3)
{
	int m;
	if (p1>p2)
    {
		m=p1,p1=p2,p2=m;
    }
	if (p1>p3)
    {
		m=p1,p1=p3,p3=m;
    }
	if (p2>p3)
    {
		m=p2,p2=p3,p3=m;
    }
}

int bfs(void){
	int i,j;
	while(tail-head>=0){
		for(i=head;i<=tail;i++){
			if(queue[i].x==queue[i].y&&queue[i].y==queue[i].z){
				return depth;
			}
		}
		depth++;
		nhead=tail+1;
		ntail=tail;
		int s1,s2,s3;
		for(i=head;i<=tail;i++){
			for(j=0;j<n;j++){
				if(j==queue[i].x) continue;
				if(color[j][queue[i].x]!=color[queue[i].y][queue[i].z]) continue;
				s1=j,s2=queue[i].y,s3=queue[i].z;
				order(s1,s2,s3);
				if(a[s1][s2][s3].visited==1) continue;
				a[s1][s2][s3].visited=1;
				queue[++ntail]=a[s1][s2][s3];
			}
			for(j=0;j<n;j++){
				if(j==queue[i].y) continue;
				if(color[j][queue[i].y]!=color[queue[i].x][queue[i].z]) continue;
				s1=queue[i].x,s2=j,s3=queue[i].z;
				order(s1,s2,s3);
				if(a[s1][s2][s3].visited==1) continue;
				a[s1][s2][s3].visited=1;
				queue[++ntail]=a[s1][s2][s3];
			}
			for(j=0;j<n;j++){
				if(j==queue[i].z) continue;
				if(color[j][queue[i].z]!=color[queue[i].x][queue[i].y]) continue;
				s1=queue[i].x,s2=queue[i].y,s3=j;
				order(s1,s2,s3);
				if(a[s1][s2][s3].visited==1) continue;
				a[s1][s2][s3].visited=1;
				queue[++ntail]=a[s1][s2][s3];
			}
		}
		for(i=nhead;i<=ntail;i++){
			queue[i-nhead]=queue[i];
		}
		head=0;
		tail=ntail-nhead;
	}
	return -1;
}

int main(){
	int min;
	int p1,p2,p3;
	int i,j,t;
	while(1){
		cin>>n;
		if(n==0) break;
		cin>>p1>>p2>>p3;
		p1--,p2--,p3--;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++) cin>>color[i][j];
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(t=0;t<n;t++){
					a[i][j][t].x=i;
					a[i][j][t].y=j;
					a[i][j][t].z=t;
					a[i][j][t].visited=0;
				}
			}
		}
		order(p1,p2,p3);
		a[p1][p2][p3].visited=1;
		queue[0]=a[p1][p2][p3];
		head=tail=0;
		depth=0;
		min=bfs();
		if(min==-1) cout<<"impossible"<<endl;
		else cout<<min<<endl;
	}
	return 0;
}

