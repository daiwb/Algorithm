#include <iostream>

using namespace std;

int main(void){
	int n,i,j,t;
	int x[20],y[20];
	while(cin>>n&&n!=0){
		char* a=new char[n+1];
		cin>>a;
		int num[51][51]={0};
		for(i=0;i<20;i++){
			x[i]=30-i;
			y[i]=25;
			num[x[i]][y[i]]=1;
		}
		for(j=0;j<n;j++){
			if(a[j]=='E'){
				num[x[19]][y[19]]=0;
				if(x[0]+1>50){
					cout<<"The worm ran off the board on move "<<j+1<<"."<<endl;
					break;
				}
				if(num[x[0]+1][y[0]]==1){
					cout<<"The worm ran into itself on move "<<j+1<<"."<<endl;
					break;
				}
				for(t=19;t>=1;t--){
					x[t]=x[t-1];
					y[t]=y[t-1];
				}
				x[0]=x[0]+1;
				y[0]=y[0];
				num[x[0]][y[0]]=1;
			}
			if(a[j]=='S'){
				num[x[19]][y[19]]=0;
				if(y[0]+1>50){
					cout<<"The worm ran off the board on move "<<j+1<<"."<<endl;
					break;
				}
				if(num[x[0]][y[0]+1]==1){
					cout<<"The worm ran into itself on move "<<j+1<<"."<<endl;
					break;
				}
				for(t=19;t>=1;t--){
					x[t]=x[t-1];
					y[t]=y[t-1];
				}
				x[0]=x[0];
				y[0]=y[0]+1;
				num[x[0]][y[0]]=1;
			}
			if(a[j]=='W'){
				num[x[19]][y[19]]=0;
				if(x[0]-1<1){
					cout<<"The worm ran off the board on move "<<j+1<<"."<<endl;
					break;
				}
				if(num[x[0]-1][y[0]]==1){
					cout<<"The worm ran into itself on move "<<j+1<<"."<<endl;
					break;
				}
				for(t=19;t>=1;t--){
					x[t]=x[t-1];
					y[t]=y[t-1];
				}
				x[0]=x[0]-1;
				y[0]=y[0];
				num[x[0]][y[0]]=1;
			}
			if(a[j]=='N'){
				num[x[19]][y[19]]=0;
				if(y[0]-1<1){
					cout<<"The worm ran off the board on move "<<j+1<<"."<<endl;
					break;
				}
				if(num[x[0]][y[0]-1]==1){
					cout<<"The worm ran into itself on move "<<j+1<<"."<<endl;
					break;
				}
				for(t=19;t>=1;t--){
					x[t]=x[t-1];
					y[t]=y[t-1];
				}
				x[0]=x[0];
				y[0]=y[0]-1;
				num[x[0]][y[0]]=1;
			}
			if(j==n-1) cout<<"The worm successfully made all "<<j+1<<" moves."<<endl;
		}
		delete []a;
	}
	return 0;
}



