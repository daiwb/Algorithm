//ac

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#define MAXN 400
#define inf 1000000000
#define _clr(x) memset(x,0xff,sizeof(int)*n)

int kuhn_munkras(int m,int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],l1[MAXN],l2[MAXN],p,q,ret=0,i,j,k;
	for (i=0;i<m;i++)
		for (l1[i]=-inf,j=0;j<n;j++)
			l1[i]=mat[i][j]>l1[i]?mat[i][j]:l1[i];
	for (i=0;i<n;l2[i++]=0);
	for (_clr(match1),_clr(match2),i=0;i<m;i++){
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (l1[k]+l2[j]==mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
		if (match1[i]<0){
			for (i--,p=inf,k=0;k<=q;k++)
				for (j=0;j<n;j++)
					if (t[j]<0&&l1[s[k]]+l2[j]-mat[s[k]][j]<p)
						p=l1[s[k]]+l2[j]-mat[s[k]][j];
			for (j=0;j<n;l2[j]+=t[j]<0?0:p,j++);
			for (k=0;k<=q;l1[s[k++]]-=p);
		}
	}
	for (i=0;i<m;i++)
		ret+=mat[i][match1[i]];
	return ret;
}

int n;
int love[MAXN];
int mat[MAXN][MAXN];
int match1[MAXN], match2[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &love[i]);
		love[i] *= love[i];
	}
	memset(mat, 0, sizeof(mat));
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d", &k);
		while (k--) {
			int t;
			scanf("%d", &t);
			--t;
			mat[i][t] = love[i];
		}
	}
	kuhn_munkras(n, n, mat, match1, match2);
	for (int i = 0; i < n; ++i) {
		if (i) printf(" ");
		if (mat[i][match1[i]] == 0) printf("0");
		else printf("%d", match1[i] + 1);
	}
	printf("\n");
	return 0;
}

