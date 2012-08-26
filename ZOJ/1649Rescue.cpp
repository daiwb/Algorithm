/*
 * ZOJ 1160 Rescue
 *
 * 05/03/30 By ADAI
 *
 * Algo Desc: BFS
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

#define MAXN 200

#ifdef WIN32
#define for if(0); else for
#endif

class point {
public:
	int x;
	int y;
	int guard;
	point() {
	}
	point(int xx, int yy, int gguard) {
		x = xx, y = yy, guard = gguard;
	}
	point &operator = (const point &cc){
		x = cc.x, y = cc.y, guard = cc.guard;
		return *this;
	}
}list[400];

int n, m, ret;
int mat[MAXN][MAXN];
int visited[MAXN][MAXN];
char input[MAXN + 1];
int endx, endy;
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int bfs(int ii, int jj) {
	visited[ii][jj] = 1;
	int head, tail, nhead, ntail, step;
	head = tail = step = 0;
	list[0] = point(ii, jj, 0);
	while (1) {
		++step;
		if (step >= ret) return -1;
		nhead = tail + 1, ntail = tail;
		for (int i = head; i <= tail; ++i) {
			if (list[i].guard == 1) {
				list[i].guard = 0;
				list[++ntail] = list[i];
				continue;
			}
			int tx, ty;
			for (int j = 0; j < 4; ++j) {
				tx = list[i].x + dir[j][0];
				ty = list[i].y + dir[j][1];
				if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
				if (visited[tx][ty]) continue;
				if (mat[tx][ty] == 1) continue;
				visited[tx][ty] = 1;
				int tmp = 0;
				if (mat[tx][ty] == 2) tmp = 1;
				if (tmp == 1) {
					int adai = 3;
				}
				list[++ntail] = point(tx, ty, tmp);
			}
		}
		if (ntail < nhead) return -1;
		if (visited[endx][endy]) return step;
		for (int i = nhead; i <= ntail; ++i) {
			list[i - nhead] = list[i];
		}
		head = 0, tail = ntail - nhead;
	}
	return -1;
}

int Run() {
	vector<point> start;
	memset(mat, 0, sizeof(mat));
	for (int i = 0; i < n; ++i) {
		scanf("%s", input);
		for (int j = 0; j < m; ++j) {
			if (input[j] == 'r') {
				start.push_back(point(i, j, 0));
			}
			else if (input[j] == 'a') {
				endx = i, endy = j;
			}
			else if (input[j] == 'x') {
				mat[i][j] = 2;
			}
			else if (input[j] == '#') {
				mat[i][j] = 1;
			}
		}
	}
	
	ret = 50000;
	int size = start.size();
	for (int i = 0; i < size; ++i) {
		memset(visited, 0, sizeof(visited));
		int step = bfs(start[i].x, start[i].y);
		if (step > 0) {
			ret = step;
		}
	}
	if (ret == 50000) printf("Poor ANGEL has to stay in the prison all his life.\n");
	else printf("%d\n", ret);
	return 0;
}

int main() {
	while (scanf("%d %d", &n, &m) != EOF) {
		Run();
	}
	return 0;
}
