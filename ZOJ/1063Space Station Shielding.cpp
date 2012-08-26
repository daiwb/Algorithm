/*
zju 1063 Space Station Shielding
00:00.32 7600k
2004.07.17 by adai
*/

#include <iostream>
using namespace std;

int n,m,k,l;
int acm[62][62][62];
int step[6][3]={1,0,0,-1,0,0,0,1,0,0,-1,0,0,0,1,0,0,-1};

void dfs(int x,int y,int z){
	acm[x][y][z]=-1;
	for(int i=0;i<6;i++){
		if(x+step[i][0]<0||x+step[i][0]>n+1) continue;
		if(y+step[i][1]<0||y+step[i][1]>m+1) continue;
		if(z+step[i][2]<0||z+step[i][2]>k+1) continue;
		if(acm[x+step[i][0]][y+step[i][1]][z+step[i][2]]==0){
			dfs(x+step[i][0],y+step[i][1],z+step[i][2]);
		}
	}
}

int main(){
	int num;
	int i,j,t,s;
	int x,y,z;
	while(1){
		cin>>n>>m>>k>>l;
		if(n+m+k+l==0) break;
		for(i=0;i<=n+1;i++){
			for(j=0;j<=m+1;j++){
				for(t=0;t<=k+1;t++) acm[i][j][t]=0;
			}
		}
		for(i=0;i<l;i++){
			cin>>j;
			j++;
			if(j%(m*n)==0) z=j/(m*n);
			else z=j/(m*n)+1;
			j-=(z-1)*m*n;
			if(j%n==0) y=j/n;
			else y=j/n+1;
			j-=(y-1)*n;
			x=j;
			acm[x][y][z]=1;
		}
		dfs(0,0,0);
		num=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				for(t=1;t<=k;t++){
					if(acm[i][j][t]==1){
						for(s=0;s<6;s++){
							if(acm[i+step[s][0]][j+step[s][1]][t+step[s][2]]==-1) num++;
						}
					}
				}
			}
		}
		cout<<"The number of faces needing shielding is "<<num<<"."<<endl;
	}
	return 0;
}
