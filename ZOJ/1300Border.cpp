#include <iostream>

using namespace std;

int main(void){
	int n,i,j,t,x,y;
	char direct[1000000];
	cin>>n;
	for(t=1;t<=n;t++){
		cin>>x>>y;
		cin>>direct;
		cout<<"Bitmap #"<<t<<endl;
		int grid[32][32]={0};
		for(j=0;direct[j]!='.';j++){
			if(direct[j]=='E'){
				if(x>=0&&x<=31&&y-1>=0&&y-1<=31) grid[x][y-1]=1;
				x++;
			}
			else if(direct[j]=='S'){
				if(x-1>=0&&x-1<=31&&y-1>=0&&y-1<=31) grid[x-1][y-1]=1;
				y--;
			}
			else if(direct[j]=='W'){
				if(x-1>=0&&x-1<=31&&y>=0&&y<=31) grid[x-1][y]=1;
				x--;
			}
			else{
				if(x>=0&&x<=31&&y>=0&&y<=31) grid[x][y]=1;
				y++;
			}
		}
		for(i=31;i>=0;i--){
			for(j=0;j<=31;j++){
				if(grid[j][i]==1) cout<<"X";
				else cout<<".";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}


