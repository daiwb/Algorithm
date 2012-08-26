/*
zju 2100 Seeding
00:00.31 436k
2004.08.04 by adai
*/

#include <iostream>
using namespace std;

int n, m;
int mat[6][6];
int sign, number;
int dir[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};

int dfs(int s, int t, int num){
	num ++;
	if(num == number){
		sign = 1;
		return 0;
	}
	if(sign) return 0;
	for(int i = 0; i < 4; i ++){
		int ss = s + dir[i][0];
		int tt = t + dir[i][1];
		if(ss < 0 || ss >= n) continue;
		if(tt < 0 || tt >= m) continue;
		if(mat[ss][tt] != 0) continue;
		mat[ss][tt] = 1;
		dfs(ss, tt, num);
		mat[ss][tt] = 0;
	}
	return 0;
}

int main(){
	while(1){
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		char input[7];
		number = 0;
		for(int i = 0; i < n; i ++){
			cin >> input;
			for(int j = 0; j < m; j ++){
				if(input[j] == 'S') mat[i][j] = -1;
				else{
					mat[i][j] = 0;
					number ++;
				}
			}
		}
		sign = 0;
		mat[0][0] = 1;
		dfs(0, 0, 0);
		if(sign) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
