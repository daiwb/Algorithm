/*
 * ZJU 2291 Maze
 * 00:00.00 844k
 * 2005.01.25 by adai
 */

#include <iostream>
#include <string>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
char mat[22][22];
int visited[22][22];
int num[5];
int found, again;

int search(int ii, int jj) {
	int next_i, next_j;
	for (int i = 0; i < 4; i ++) {
		next_i = ii + dir[i][0];
		next_j = jj + dir[i][1];

		if (visited[next_i][next_j] == 1) continue;
		if (mat[next_i][next_j] == 'X') continue;
		else if (mat[next_i][next_j] >= 'A' && mat[next_i][next_j] <= 'E') {
			if (num[mat[next_i][next_j] - 'A'] == 0) {
				mat[next_i][next_j] = '.';
				again = 1;
				visited[next_i][next_j] = 1;
				search(next_i, next_j);
			}
		}
		else if (mat[next_i][next_j] >= 'a' && mat[next_i][next_j] <= 'e') {
			num[mat[next_i][next_j] - 'a'] --;
			mat[next_i][next_j] = '.';
			again = 1;
			visited[next_i][next_j] = 1;
			search(next_i, next_j);
		}
		else if (mat[next_i][next_j] == 'G') {
			found = 1;
			return 0;
		}
		else {
			visited[next_i][next_j] = 1;
			search(next_i, next_j);
		}
	}
	return 0;
}

int main() {
	int n, m;
	while (1) {
		cin >> n >> m;
		if (!n && !m) break;

		memset(mat, 'X', sizeof(mat));
		memset(visited, 0, sizeof(visited));
		memset(num, 0, sizeof(num));

		int start_i, start_j;
		found = 0;

		char input[21];
		for (int i = 1; i <= n; i ++) {
			cin >> input;
			for (int j = 1; j <= m; j ++) {
				mat[i][j] = input[j - 1];
				if (mat[i][j] >= 'a' && mat[i][j] <= 'e') num[mat[i][j] - 'a'] ++;
				else if (mat[i][j] == 'S') start_i = i, start_j = j;
			}
		}

		visited[start_i][start_j] = 1;
		while (1) {
			again = 0;
			memset(visited, 0, sizeof(visited));
			search(start_i, start_j);
			if (!again) break;
		}

		if (found) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
