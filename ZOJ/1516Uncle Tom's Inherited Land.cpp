#pragma warning(disable:4786)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <map>
#include <numeric>
using namespace std;

#define for if(0); else for

int min(int a, int b) {
    return a < b ? a : b;
}

#define MAXN 50
#define inf 1000000000

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

int n, m, p, nw, nb;
int mat[100][100];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int mm[MAXN][MAXN];
int match1[MAXN], match2[MAXN];
int idx[100][100];

void run() {
    map<int, pair<int, int> > wm;
    map<int, pair<int, int> > bm;
    memset(mat, 0, sizeof(mat));
    while (p--) {
        int a, b;
        scanf("%d %d", &b, &a);
        --a, --b;
        mat[a][b] = 1;
    }
    nw = nb = 0;
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            idx[i][j] = inf;
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (mat[i][j]) continue;
            if ((i + j) % 2 == 0) {
                wm[nw] = make_pair(i, j);
                idx[i][j] = nw++;
            } else {
                bm[nb] = make_pair(i, j);
                idx[i][j] = -(nb++);
            }
        }
    }
    int num = n * m - p;
    memset(mm, 0, sizeof(mm));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j]) continue;
            for (int d = 0; d < 4; ++d) {
                int ii = i + dir[d][0], jj = j + dir[d][1];
                if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                if (mat[ii][jj]) continue;
                int s1 = idx[i][j], s2 = idx[ii][jj];
                if ((i + j) % 2 == 0) {
                    mm[s1][-s2] = 1;
                } else {
                    mm[s2][-s1] = 1;
                }
            }
        }
    }
    int ret = hungary(nw, nb, mm, match1, match2);
    printf("%d\n", ret);
}

int main() {
    while (scanf("%d %d", &m, &n) && n + m) {
        scanf("%d", &p);
        run();
    }
    return 0;
}
