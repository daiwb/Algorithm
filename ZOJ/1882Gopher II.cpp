#include <iostream>
#include <cmath>
#include <string>
using namespace std;

#define for if(0); else for

//二分图最大匹配,hungary算法,邻接阵形式,复杂度O(m*m*n)
//返回最大匹配数,传入二分图大小m,n和邻接阵mat,非零元素表示有边
//match1,match2返回一个最大匹配,未匹配顶点match值为-1
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

class point {
public:
    double x;
    double y;
};

double dis(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

point gopher[100], hole[100];
double n, m, s, v;
int mat[100][100];
int match1[100], match2[100];

void Run() {
    for (int i = 0; i < n; ++i) cin >> gopher[i].x >> gopher[i].y;
    for (int i = 0; i < m; ++i) cin >> hole[i].x >> hole[i].y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dis(gopher[i], hole[j]) / v > s) mat[i][j] = 0;
            else mat[i][j] = 1;
        }
    }
    cout << n - hungary(n, m, mat, match1, match2) << endl;
}

int main() {
    while (cin >> n >> m >> s >> v) {
        Run();
    }
    return 0;
}
