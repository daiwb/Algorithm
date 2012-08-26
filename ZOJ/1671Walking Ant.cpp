/*
 * ZJU 1671 Walking Ant
 * 00:00.01 844k
 * 2005.03.01 by adai
 */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//单源最短路径,bellman_ford算法,邻接阵形式,复杂度O(n^3)
//求出源s到所有点的最短路经,传入图的大小n和邻接阵mat
//返回到各点最短距离min[]和路径pre[],pre[i]记录s到i路径上i的父结点,pre[s]=-1
//可更改路权类型,路权可为负,若图包含负环则求解失败,返回0
//优化:先删去负边使用dijkstra求出上界,加速迭代过程
#define MAXN 7
#define inf 10000000
typedef int elem_t;

int bellman_ford(int n,elem_t mat[][MAXN],int s,elem_t* min,int* pre){
	int v[MAXN],i,j,k,tag;
	for (i=0;i<n;i++)
		min[i]=inf,v[i]=0,pre[i]=-1;
	for (min[s]=0,j=0;j<n;j++){
		for (k=-1,i=0;i<n;i++)
			if (!v[i]&&(k==-1||min[i]<min[k]))
				k=i;
		for (v[k]=1,i=0;i<n;i++)
			if (!v[i]&&mat[k][i]>=0&&min[k]+mat[k][i]<min[i])
				min[i]=min[k]+mat[pre[i]=k][i];
	}
	for (tag=1,j=0;tag&&j<=n;j++)
		for (tag=i=0;i<n;i++)
			for (k=0;k<n;k++)
				if (min[k]+mat[k][i]<min[i])
					min[i]=min[k]+mat[pre[i]=k][i],tag=1;
	return j<=n;
}

class point
{
public:
	int x;
	int y;
}mm[7];
int number;

int dis[7][7];

int len, wid, ret;
int startX, startY, endX, endY;
int mat[10][10], visited[10][10];
int x[50], y[50], hp[50];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

int getDis(int ii, int jj)
{
	int step = 0;
	int head = 0, tail = 0, nhead, ntail;
	int tx, ty;
	x[0] = mm[ii].x, y[0] = mm[ii].y, hp[0] = 6;
	memset(visited, 0, sizeof(visited));
	visited[x[0]][y[0]] = 1;
	while (1)
	{
		if (visited[mm[jj].x][mm[jj].y]) {
			return step;
		}
        nhead = tail + 1, ntail = tail;
		for (int i = head; i <= tail; ++i) {
			if (hp[i] == 1) break;
			for (int j = 0; j < 4; ++j) {
				tx = x[i] + dir[j][0], ty = y[i] + dir[j][1];
				if (mat[tx][ty] == 0) continue;
				if (visited[tx][ty]) continue;
				visited[tx][ty] = 1;
				++ntail;
				x[ntail] = tx, y[ntail] = ty, hp[ntail] = hp[i] - 1;
			}
		}
		if (ntail < nhead) break;
		for (int i = nhead; i <= ntail; ++i) {
			x[i - nhead] = x[i], y[i - nhead] = y[i], hp[i - nhead] = hp[i];
		}
		head = 0, tail = ntail - nhead;
		++step;
	}
	return 1000;
}

int main()
{
	while (cin >> wid >> len && wid + len)
	{
		//input
		number = 1;
		memset(mat, 0, sizeof(mat));
		for (int i = 1; i <= len; ++i) {
			for (int j = 1; j <= wid; ++j) {
				cin >> mat[i][j];
				if (mat[i][j] == 2) {
					startX= i, startY = j;
				}
				else if (mat[i][j] == 4) {
					mm[number].x = i, mm[number].y = j;
					++number;
				}
				else if (mat[i][j] == 3) {
					endX = i, endY = j;
				}
			}
		}
		mm[0].x = startX, mm[0].y = startY;
		mm[number].x = endX, mm[number].y = endY;
		++number;

		memset(dis, 0, sizeof(dis));
		for (int i = 0; i < number; ++i) {
			for (int j = i + 1; j < number; ++j) {
				dis[i][j] = getDis(i, j);
			}
		}
		for (int i = 0; i < number; ++i) {
			for (int j = i - 1; j >= 0; --j) {
				dis[i][j] = dis[j][i];
			}
		}

		int min[7], pre[7];
		bellman_ford(number, dis, 0, min, pre);
		ret = min[number - 1];

		//output
		if (ret == 1000) cout << -1 << endl;
		else cout << ret << endl;
	}
	return 0;
}
