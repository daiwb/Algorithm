//ac

#include <iostream>
#include <cstdio>
#include <string>

#define MAXN 500
#define inf 1000000000
#define _clr(x) memset(x,0xff,sizeof(int)*n)

int hungary(int m,int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],p,q,ret=0,i,j,k;
	if (m>n) return 0;
	for (_clr(match1),_clr(match2),i=0;i<m&&ret==i;ret+=(match1[i++]>=0))
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
	return ret==m;
};

int n;
int mat[MAXN][MAXN];
int mm[MAXN][MAXN];
int match1[MAXN], match2[MAXN];

int main() {
	scanf("%d", &n);
	int left = inf, right = -inf;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &mat[i][j]);
			if (mat[i][j] < left) left = mat[i][j];
			if (mat[i][j] > right) right = mat[i][j];
		}
	}
	while (left <= right) {
		int mid = (left + right) / 2;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (mat[i][j] <= mid) mm[i][j] = 1;
				else mm[i][j] = 0;
			}
		}
		int ret = hungary(n, n, mm, match1, match2);
		if (ret == 1) right = mid - 1;
		else left = mid + 1;
	}
	printf("%d\n", left);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (mat[i][j] <= left) mm[i][j] = 1;
			else mm[i][j] = 0;
		}
	}
	hungary(n, n, mm, match1, match2);
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", i + 1, match1[i] + 1);
	}
	return 0;
}

