/*
ZJU 1311 Network
2004.06.29 By adai
00:00.05 560K
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//无向图的关键点,dfs邻接阵形式,O(n^2)
//返回关键点个数,key[]返回点集
//传入图的大小n和邻接阵mat,不相邻点边权0
#define MAXN 100
int mat[MAXN][MAXN];

void search(int n,int mat[][MAXN],int* dfn,int* low,int now,int& ret,int* key,int& cnt,int root,int& rd){
	int i;
	dfn[now]=low[now]=++cnt;
	for (i=0;i<n;i++)
		if (mat[now][i]){
			if (!dfn[i]){
				search(n,mat,dfn,low,i,ret,key,cnt,root,rd);
				if (low[i]<low[now])
					low[now]=low[i];
				if (low[i]>=dfn[now]){
					if (now!=root)
						key[ret++]=now;
					else
						rd++;
				}
			}
			else if (dfn[i]<low[now])
				low[now]=dfn[i];
		}
}

int key_vertex(int n,int mat[][MAXN],int* key){
	int ret=0,i,cnt,rd,dfn[MAXN],low[MAXN];
	for (i=0;i<n;dfn[i++]=0);
	for (cnt=i=0;i<n;i++)
		if (!dfn[i]){
			rd=0;
			search(n,mat,dfn,low,i,ret,key,cnt,i,rd);
			if (rd>1)
				key[ret++]=i;
		}
		return ret;
}

int main(){
	int n,i,j,s,t;
	while(cin>>n&&n!=0){
		for(i=0;i<MAXN;i++){
			for(j=0;j<MAXN;j++){
				mat[i][j]=0;
			}
		}
		while(cin>>s){
			getchar();
			if(s==0) break;
			while(1){
				cin>>t;
				mat[s-1][t-1]=mat[t-1][s-1]=1;
				char ch=getchar();
				if(ch=='\n') break;
			}
		}
		int key[10000];
		int ret=key_vertex(n,mat,key);
		int* a=new int[n];
		for(i=0;i<n;i++) a[i]=0;
		int num(0);
		for(i=0;i<ret;i++){
			if(a[key[i]]==0){
				num++;
				a[key[i]]=1;
			}
		}
		cout<<num<<endl;
	}
	return 0;
}

