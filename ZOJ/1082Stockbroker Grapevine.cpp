/*
zju 1082 Stockbroker Grapevine
00:00.00 472k
2004.08.19 by adai
*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

//单源最短路径,dijkstra算法,邻接阵形式,复杂度O(n^2)
//求出源s到所有点的最短路经,传入图的顶点数n,(有向)邻接矩阵mat
//返回到各点最短距离min[]和路径pre[],pre[i]记录s到i路径上i的父结点,pre[s]=-1
//可更改路权类型,但必须非负!
#define MAXN 100
#define inf 100000

void dijkstra(int n,int mat[][MAXN],int s,int* min,int* pre){
	int v[MAXN],i,j,k;
	for (i=0;i<n;i++)
		min[i]=inf,v[i]=0,pre[i]=-1;
	for (min[s]=0,j=0;j<n;j++){
		for (k=-1,i=0;i<n;i++)
			if (!v[i]&&(k==-1||min[i]<min[k]))
				k=i;
		for (v[k]=1,i=0;i<n;i++)
			if (!v[i]&&min[k]+mat[k][i]<min[i])
				min[i]=min[k]+mat[pre[i]=k][i];
	}
}

int mat[100][100];

int main () {
	int n;
	while (cin >> n && n != 0) {
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) mat[i][j] = inf;
			mat[i][i] = 0;
		}
		for (int i = 0; i < n; i ++) {
			int m;
			cin >> m;
			for (int j = 0; j < m; j ++) {
				int a, b;
				cin >> a >> b;
				mat[i][a - 1] = b;
			}
		}
		int min[MAXN], pre[MAXN];
		int disjoint = 1;
		int res = inf;
		int index;
		for (int i = 0; i < n; i ++) {
			int mm = 0;
			int sign = 1;
			dijkstra(n, mat, i, min, pre);
			for (int j = 0; j < n; j ++) {
				if (j == i) continue;
				if (sign == 0) break;
				if (min[j] == inf) sign = 0;
				if (min[j] > mm) mm = min[j];
			}
			if (sign) {
				disjoint = 0;
				if (mm < res) {
					res = mm;
					index = i + 1;
				}
			}
		}
		if (!disjoint) cout << index << " " << res << endl;
		else cout << "disjoint" << endl;
	}
	return 0;
}
