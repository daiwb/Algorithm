/*
ZJU 1060 Sorting It All Out
00:00.00 380K
2004.07.05 By adai
*/

#include <stdio.h>

int mat[26][26];
int n,m,i,j,p,q,no,idx,sign;

int f(int ii,int jj){
	int t,s;
	for(t=0;t<n;t++){
		if(sign==1) break;
		if(!(mat[ii][t]==1||t==ii)) continue;
		for(s=0;s<n;s++){
			if(!(mat[jj][s]==-1||s==jj)) continue;
			if(s==t) continue;
			if(mat[t][s]==1){
				sign=1;
				idx=i+1;
				return 0;
			}
			else if(mat[t][s]==0){
				no+=2;
				mat[t][s]=-1;
				mat[s][t]=1;
				f(t,s);
			}
		}
	}
	return 0;
}

int main(){
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n==0&&m==0) break;
		sign=0;
		no=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++) mat[i][j]=0;
		}
		char input[4];
		for(i=0;i<m;i++){
			scanf("%s",&input);
			if(sign==1||sign==3) continue;
			p=input[0]-'A';
			q=input[2]-'A';
			if(p==q){
				sign=1;
				idx=i+1;
				continue;
			}
			if(mat[p][q]==1){
				sign=1;
				idx=i+1;
				continue;
			}
			else if(mat[p][q]==0){
				no+=2;
				mat[p][q]=-1;
				mat[q][p]=1;
				f(p,q);
			}
			if(no==n*n-n){
				idx=i+1;
				sign=3;
				continue;
			}
		}
		if(sign==1){
			printf("Inconsistency found after %d relations.\n",idx);
			continue;
		}
		if(no!=n*n-n){
			printf("Sorted sequence cannot be determined.\n");
			continue;
		}
		int rank[26]={0};
		int t;
		for(i=0;i<n;i++){
			t=0;
			for(j=0;j<n;j++){
				if(mat[i][j]==1) t++;
			}
			rank[t]=i;
		}
		printf("Sorted sequence determined after %d relations: ",idx);
		for(i=0;i<n;i++){
			printf("%c",rank[i]+'A');
		}
		printf(".\n");
	}
	return 0;
}
