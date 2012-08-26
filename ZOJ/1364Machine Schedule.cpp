// ac

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 100
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

int n, m, k;
int mat[MAXN][MAXN];
int match1[MAXN], match2[MAXN];

void run() {
        scanf("%d %d", &m, &k);
        memset(mat, 0, sizeof(mat));
        for (int i = 0; i < k; ++i) {
                int c, a, b;
                scanf("%d %d %d", &c, &a, &b);
                if (a && b) mat[a][b] = 1;
        }
        printf("%d\n", hungary(n, m, mat, match1, match2));
}

int main() {
        while (scanf("%d", &n) && n) {
                run();
        }
        return 0;
}
