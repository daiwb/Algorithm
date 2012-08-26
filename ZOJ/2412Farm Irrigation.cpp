/**
 * ZOJ 2412 Farm Irrigation
 */

#include <iostream>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

class square {
public:
	int dir[4];
	int visited;
}mm[50][50];

int dir[11][4] = {
	{1, 0, 0, 1},
	{1, 1, 0, 0},
	{0, 0, 1, 1},
	{0, 1, 1, 0},
	{1, 0, 1, 0},
	{0, 1, 0, 1},
	{1, 1, 0, 1},
	{1, 0, 1, 1},
	{0, 1, 1, 1},
	{1, 1, 1, 0},
	{1, 1, 1, 1}
};
	
int move[4][2] = {
	{-1, 0},
	{ 0, 1},
	{ 1, 0},
	{ 0, -1}
};

int cc[4] = {2, 3, 0, 1};

int m, n, ret;

int search(int ii, int jj) {
	int tx, ty;
	for (int i = 0; i < 4; ++i) {
		if (mm[ii][jj].dir[i]) {
			tx = ii + move[i][0], ty = jj + move[i][1];
			if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
			if (mm[tx][ty].visited) continue;
			if (mm[tx][ty].dir[cc[i]]) {
				mm[tx][ty].visited = 1;
				search(tx, ty);
			}
		}
	}
	return 0;
}

int Run()
{
	char input[51];
	for (int i = 0; i < m; ++i) {
		cin >> input;
		for (int j = 0; j < n; ++j) {
			mm[i][j].visited = 0;
			for (int k = 0; k < 4; ++k) {
				mm[i][j].dir[k] = dir[input[j] - 'A'][k];
			}
		}
	}
	
	ret = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (mm[i][j].visited) continue;
			mm[i][j].visited = 1;
			++ret;
			search(i, j);
		}
	}
	cout << ret << endl;
	return 0;
}

int main() {
	while (cin >> m >> n) {
		if (m == -1 && n == -1) break;
		Run();
	}
	return 0;
}
