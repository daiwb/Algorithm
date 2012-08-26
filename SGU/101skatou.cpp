//ac

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
using namespace std;

#define MAXN 10

void find_path_u(int n,int mat[][MAXN],int now,int& step,int* path){
	int i;
	for (i=n-1;i>=0;i--)
		while (mat[now][i]){
			mat[now][i]--,mat[i][now]--;
			find_path_u(n,mat,i,step,path);
		}
	path[step++]=now;
}

void find_path_d(int n,int mat[][MAXN],int now,int& step,int* path){
	int i;
	for (i=n-1;i>=0;i--)
		while (mat[now][i]){
			mat[now][i]--;
			find_path_d(n,mat,i,step,path);
		}
	path[step++]=now;
}

int euclid_path(int n,int mat[][MAXN],int start,int* path){
	int ret=0;
	find_path_u(n,mat,start,ret,path);
	//	find_path_d(n,mat,start,ret,path);
	return ret;
}

int n;
int mat[10][10];
map<pair<int, int>, deque<int> > M;
int path[1000];
int degree[10];
int visit[10];

void dfs(int now) {
	visit[now] = 1;
	for (int i = 0; i < 7; ++i) if (!visit[i] && mat[now][i])
		dfs(i);
}

int main() {
	while (scanf("%d", &n) != EOF) {
		M.clear();
		memset(mat, 0, sizeof(mat));
		memset(degree, 0, sizeof(degree));
		for (int i = 0; i < 7; ++i)
			visit[i] = 1;
		for (int i = 1; i <= n; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			mat[a][b]++; mat[b][a]++;
			degree[a]++; degree[b]++;
			visit[a] = visit[b] = 0;
			pair<int, int> u(a, b);
			M[u].push_back(i);
		}
		int start = 0;
		for (int i = 0; i < 7; ++i) if (!visit[i]) {
			start = i;
			dfs(i); break;
		}
		int flag = 0;
		for (int i = 0; i < 7; ++i) if (!visit[i]) {
			flag = 1; break;
		}
		if (flag) {
			printf("No solution\n");
			continue;
		}
		int oddCnt = 0;
		for (int i = 0; i < 7; ++i) if (degree[i] & 1)
			oddCnt++, start = i;
		if (!(oddCnt == 0 || oddCnt == 2)) {
			printf("No solution\n");
			continue;
		}
		int ret = euclid_path(7, mat, start, path);
		for (int i = 1; i < ret; ++i) {
			pair<int, int> u(path[i - 1], path[i]), v(path[i], path[i - 1]);
			if (M[u].size() > 0) {
				int num = M[u].front(); M[u].pop_front();
				printf("%d +\n", num);
			} else if (M[v].size() > 0) {
				int num = M[v].front(); M[v].pop_front();
				printf("%d -\n", num);
			}
		}
	}
	return 0;
}
