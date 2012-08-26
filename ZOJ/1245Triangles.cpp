//zju 1245 Triangles

#include <cstdio>
#include <iostream>
using namespace std;

#define MAX 300 
char table[MAX][MAX]; 
int  num[MAX][MAX]; 

int getmaxarea(char table[MAX][MAX],int m,int n) 
{ 
	int i,j,max,depth,left,right; 
	max=0; 
	for(i=1;i<=m;i++){ 
		for(j=i;j<=n;j++){ 
			if(table[i][j]=='-'){ 
				left=j-1;
				right=j+1; 
				if((i+j)%2==1){ //an upward triangle 
					for(depth=i+1;depth<=m;depth++){ 
						if(left<=0||right>n) break; 
						if(num[depth][right]-num[depth][left-1]<right-left+1)break; 
						left--;
						right++; 
					} 
					if(depth-i>max) max=depth-i; 
				} 
				else {//a downward triangle 
					for(depth=i-1;depth>=1;depth--){ 
						if(left<=0||right>n) break; 
						if(num[depth][right]-num[depth][left-1]<right-left+1)break; 
						left--;
						right++; 
					} 
					if(i-depth>max) max=i-depth; 
				} 
			} 
		} 
	} 
	return max*max; 
} 
int main() 
{ 
	int i,j,m,n,ans,counter=0; 
	char line[MAX]; 
	
	while(1){ 
		cin>>m;
		if(m==0) break; 
		counter++; 
		n=m+m-1; 
		for(i=1;i<=m;i++){ 
			for(j=1;j<=n;j++)table[i][j]=' '; 
		} 
		cin.getline(line,205,'\n');
		for(i=1;i<=m;i++){ 
			cin.getline(line,205,'\n');
			for(j=0;line[j];j++){ 
				table[i][j+1]=line[j]; 
			} 
		} 
		
		for(i=1;i<=m;i++){ 
			num[i][0]=0; 
			for(j=1;j<=n;j++){ 
				if(table[i][j]=='-') num[i][j]=num[i][j-1]+1; 
				else num[i][j]=num[i][j-1]; 
			} 
		} 
		ans=getmaxarea(table,m,n); 
		printf("Triangle #%d\n",counter); 
		printf("The largest triangle area is %d.\n\n",ans); 
	}
	return 0; 
}