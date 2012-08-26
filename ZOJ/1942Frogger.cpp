/*
zju 1942 Frogger
00:00.03 760k
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <string>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

#define MAXN 200
#define inf 1000000

class point {
public:
	int x;
	int y;
}pp[200];

int visited[200];
double mat[200][200];

double dis(point a, point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double res;
int n;

void dijkstra(int n,double mat[][MAXN],int s,double* min,int* pre)
{
	int v[MAXN],i,j,k;
	for (i=0;i<n;i++)
		min[i]=inf,v[i]=0,pre[i]=-1;
	for (min[s]=0,j=0;j<n;j++){
		for (k=-1,i=0;i<n;i++)
			if (!v[i]&&(k==-1||min[i]<min[k]))
				k=i;
		for (v[k]=1,i=0;i<n;i++)
			if (!v[i]&&(min[k]>mat[k][i]?min[k]:mat[k][i])<min[i])
				min[i]=min[k]>mat[pre[i]=k][i]?min[k]:mat[k][i];
	}
}

/*
int dfs(int ii, double nes) {
	double temp;
	temp = mat[ii][1];
	if (temp < res) {
		if (temp < nes) temp = nes;
		if (temp < res) res = temp;
	}
	for (int i = 2; i < n; i ++) {
		if (visited[i] == 1) continue;
		temp = mat[ii][i];
		if (temp > res) continue;
		visited[i] = 1;
		dfs(i, temp > nes ? temp : nes);
		visited[i] = 0;
	}
	return 0;
}*/


int main() {
	cout.setf(ios::fixed);
	cout.precision(3);
	int kase = 1;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i ++) scanf("%d %d", &pp[i].x, &pp[i].y);
		for (int i = 0; i < n; i ++) {
			for (int j = i; j < n; j ++) {
				mat[i][j] = mat[j][i] = dis(pp[i], pp[j]);
			}
		}
		memset(visited, 0, sizeof(visited));
		/*
		res = mat[0][1];
				for (int i = 2; i < n; i ++) {
					double nes = mat[0][i];
					if (nes < res) {
						visited[i] = 1;
						dfs(i, nes);
						visited[i] = 0;
					}
				}*/
		double min[200];
		int pre[200];
		dijkstra(n, mat, 0, min, pre);
		res = min[1];
		printf("Scenario #%d\n", kase ++);
		printf("Frog Distance = %.3lf\n\n", res);
	}
	return 0;
}