// ac

#pragma warning(disable:4786)

#include <iostream>
#include <cstdio>
#include <deque>
#include <map>
using namespace std;

#define for if(0); else for
#define MAXN 25

int n, m, l;
int mat[MAXN][MAXN], mas[MAXN][MAXN];
int dir[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

class snake {
public:
	char x, y;
	char d[7];
	int step;
	snake() {
	}
	bool operator<(const snake& rhs) const {
		if (x != rhs.x) return x < rhs.x;
		for (int i = 0; i < l - 1; ++i) {
			if (d[i] != rhs.d[i]) return d[i] < rhs.d[i];
		}
		return y < rhs.y;
	}
};

void run(int kase) {
	map<snake, int> mm;
	memset(mat, 0, sizeof(mat));
	int x, y, xx, yy;
	scanf("%d %d", &x, &y);
	snake start;
	start.x = x, start.y = y;
	for (int i = 0; i < l - 1; ++i) {
		scanf("%d %d", &xx, &yy);
		for (int j = 0; j < 4; ++j) {
			if (x + dir[j][0] == xx && y + dir[j][1] == yy) {
				start.d[i] = j;
				break;
			}
		}
		x = xx, y = yy;
	}
	int p;
	for (scanf("%d", &p); p; --p) {
		scanf("%d %d", &x, &y);
		mat[x][y] = 1;
	}
	start.step = 0;
	deque<snake> que;
	que.push_back(start);
	mm[start] = 1;
	while (!que.empty()) {
		snake now = que[0];
		que.pop_front();
		memcpy(mas, mat, sizeof(mat));
		x = now.x, y = now.y;
		if (x == 1 && y == 1) {
			printf("Case %d: %d\n", kase, now.step);
			return;
		}
		mas[x][y] = 1;
		for (int i = 0; i < l - 1; ++i) {
			x += dir[now.d[i]][0], y += dir[now.d[i]][1];
			mas[x][y] = 1;
		}
		for (int i = 0; i < 4; ++i) {
			int tx = now.x + dir[i][0], ty = now.y + dir[i][1];
			if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
			if (mas[tx][ty]) continue;
			snake tmp(start);
			tmp.x = tx, tmp.y = ty;
			for (int i = 1; i < l - 1; ++i) {
				tmp.d[i] = now.d[i - 1];
			}
			tmp.d[0] =  3 - i;
			map<snake, int>::iterator it;
			it = mm.find(tmp);
			if (it == mm.end()) {
				mm[tmp] = 1;
				tmp.step = now.step + 1;
				que.push_back(tmp);
			}
		}
	}
	printf("Case %d: %d\n", kase, -1);
}

int main() {
	int kase = 1;
	while (scanf("%d %d %d", &n, &m, &l) && n + m + l) {
		run(kase++);
	}
	return 0;
}
