#pragma warning(disable:4786)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define for if(0); else for

int min(int a, int b) {
	return a < b ? a : b;
}

#define MAXN 800
#define inf 1000000000
#define _clr(x) memset(x,0xff,sizeof(int)*n)

int kuhn_munkras(int m,int n,char mat[][MAXN],int* match1,int* match2){
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

int n, p, nw, nb;
int mat[40][40];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char mm[MAXN][MAXN];
int match1[MAXN], match2[MAXN];
int idx[40][40];

void run() {
	map<int, pair<int, int> > wm;
	map<int, pair<int, int> > bm;
	nw = nb = 0;
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < n; ++i) {
			if ((i + j) % 2 == 0) {
				wm[nw] = make_pair(i, j);
				idx[i][j] = nw++;
			} else {
				bm[nb] = make_pair(i, j);
				idx[i][j] = -(nb++);
			}
		}
	}
	memset(mat, 0, sizeof(mat));
	for (int i = 0; i < p; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		mat[a][b] = 1;
	}
	int num = n * n - p;
	if (num % 2) {
		printf("No\n");
		return;
	}
	memset(mm, 0, sizeof(mm));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (mat[i][j]) continue;
			for (int d = 0; d < 4; ++d) {
				int ii = i + dir[d][0], jj = j + dir[d][1];
				if (ii < 0 || ii >= n || jj < 0 || jj >= n) continue;
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
	int ret = kuhn_munkras(nw, nb, mm, match1, match2);
	if (ret * 2 != num) {
		printf("No\n");
		return;
	}
	vector<pair<int, int> > hor;
	vector<pair<int, int> > ver;
	for (int i = 0; i < nw; ++i) {
		int t = match1[i];
		if (t == -1) continue;
		int wx = wm[i].first, wy = wm[i].second;
		int bx = bm[t].first, by = bm[t].second;
		if (mat[wx][wy]) continue;
		if (wx == bx) {
			ver.push_back(make_pair(wx, min(wy, by)));
		} else {
			hor.push_back(make_pair(min(wx, bx), wy));
		}
	}
	printf("Yes\n");
	printf("%d\n", hor.size());
	for (int i = 0; i < hor.size(); ++i) {
		printf("%d %d\n", hor[i].first + 1, hor[i].second + 1);
	}
	printf("%d\n", ver.size());
	for (int i = 0; i < ver.size(); ++i) {
		printf("%d %d\n", ver[i].first + 1, ver[i].second + 1);
	}
}

int main() {
	scanf("%d %d", &n, &p);
	run();
	return 0;
}

