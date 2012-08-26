/*
zju 2134 Network Saboteur
00:00.64 380k
2004.08.09 by adai
*/

#include <iostream>
#include <cstdio>
using namespace std;

#ifdef WIN32
#define for if (0); else for
#endif

int mat[20][20];
int sign[20];
int maxn;
int n, halfn;

int dfs(int num, int res) {
	if (num == n) {
		if (res > maxn) maxn = res;
		return 0;
	}

	int temp;
	sign[num] = 1;
	temp = res;
	for (int i = 0; i < num; i ++) {
		if (sign[i] != sign[num]) temp += mat[num][i];
	}
	dfs(num + 1, temp);
	sign[num] = 0;
	temp = res;
	for (int i = 0; i < num; i ++) {
		if (sign[i] != sign[num]) temp += mat[num][i];
	}
	dfs(num + 1, temp);
	return 0;
}

int main(){
	int kase;
	scanf("%d", &kase);
	for (int testcase = 0; testcase < kase; testcase ++) {
		if (testcase) printf("\n");
		
		scanf("%d", &n);
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) scanf("%d", &mat[i][j]);
		}
		
		sign[0] = 1;
		maxn = 0;
		dfs(1, 0);
		printf("%d\n", maxn);
	}
	return 0;
}
