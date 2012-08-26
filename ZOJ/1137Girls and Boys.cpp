#include <iostream>
#include <cstdio>
#include <string>
#include <string>
using namespace std;

//二分图最大匹配,hungary算法,邻接阵形式,复杂度O(m*m*n)
//返回最大匹配数,传入二分图大小m,n和邻接阵mat,非零元素表示有边
//match1,match2返回一个最大匹配,未匹配顶点match值为-1
#define MAXN 2000
#define _clr(x) memset(x,0xff,sizeof(int)*MAXN)

int hungary(int m,int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],p,q,ret=0,i,j,k;
	for (_clr(match1),_clr(match2),i=0;i<m;ret+=(match1[i++]>=0))
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
	return ret;
}

int n;
int mat[MAXN][MAXN];
int map[MAXN][MAXN];
int num[MAXN];
int boy, girl;
int type[MAXN];
int ref[MAXN], ref2[MAXN];

void search(int ii, int value)
{
	type[ii] = value;
	for (int i = 0; i < n; i ++) {
		if (type[i] == -1 && mat[ii][i])
			search(i, 3 - value);
	}
}

void Run() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) mat[i][j] = 0;
    }
    for (int i = 0; i < n; ++i) {
        char temp[100];
        scanf("%s", temp);
        scanf("%s", temp);
        num[i] = 0;
        for (int j = 1; temp[j] != ')'; ++j) num[i] = num[i] * 10 + temp[j] - '0';
        for (int j = 0; j < num[i]; ++j) {
            int a;
            scanf("%d", &a);
            mat[i][a] = 1;
        }
    }
    boy = girl = 0;
    memset(type, -1, sizeof(type));
    for (int i = 0; i < n; ++i) {
        if (num[i] == 0) type[i] = 0;
        else if (type[i] == -1) search(i, 1);
    }
    for (int i = 0; i < n; i ++) {
		if (type[i] == 1) ref[boy++] = i;
		else if (type[i] == 2) ref2[girl++] = i;
	}
	for (int i = 0; i < boy; i ++)
	for (int j = 0; j < girl; j ++)
		map[i][j] = mat[ref[i]][ref2[j]];

	int res[MAXN], res2[MAXN], re;
	re = hungary(boy, girl, map, res, res2);
	re = n - re;
	printf("%d\n", re);
}

int main() {
    while (scanf("%d", &n) != EOF) {
        Run();
    }
    return 0;
}
