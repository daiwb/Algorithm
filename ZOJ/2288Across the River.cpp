/*
 * zju 2288 Across the River
 * 00:05.23 2960k
 * by adai
 */

#include <iostream>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

#define MAXN 200 + 1

int man, woman, boat;

class rr {
public:
	int man;
	int woman;
	bool side;		//0:left 1:right
	bool visited;
	rr &operator = (const rr &cc) {
		man = cc.man;
		woman = cc.woman;
		side = cc.side;
		visited = cc.visited;
		return *this;
	}
}mm[MAXN][MAXN][2];

rr list[100000];
int head, tail;

int bfs() {
	int step = 0;
	int side = 1;
	while (1) {
		step ++;
		side = 1 - side;
		int nhead = tail + 1, ntail = tail;
		for (int i = head; i <= tail; i ++) {
			for (int j = 0; j <= list[i].man; j ++) {
				for (int k = 0; k <= list[i].woman; k ++) {
					if (j + k == 0) continue;
					if (j + k > boat) break;
					if (!(k == 0 || k >= j)) continue;
					if (!(list[i].woman - k == 0 || list[i].woman - k >= list[i].man - j)) continue;
					int twoman = woman - list[i].woman + k;
					int tman = man - list[i].man + j;
					if (!(twoman == 0 || twoman >= tman)) continue;
					if (mm[tman][twoman][1 - side].visited == 1) continue;
					mm[tman][twoman][1 - side].visited = 1;
					ntail ++;
					list[ntail] = mm[tman][twoman][1 - side];
				}
			}
		}
		if (mm[man][woman][1].visited) return step;
		if (ntail < nhead) break;
		for (int i = nhead; i <= ntail; i ++) {
			list[i - nhead] = list[i];
		}
		head = 0, tail = ntail - nhead;
	}
	return -1;
}

int main () {
	for (int i = 0; i < MAXN; i ++) {
		for (int j = 0; j < MAXN; j ++) {
			mm[i][j][0].man = mm[i][j][1].man = i;
			mm[i][j][0].woman = mm[i][j][1].woman = j;
			mm[i][j][0].side = 0, mm[i][j][1].side = 1;
		}
	}
	while (cin >> man >> woman >> boat) {
		for (int i = 0; i <= man; i ++) {
			for (int j = 0; j <= woman; j ++) {
				mm[i][j][0].visited = mm[i][j][1].visited = 0;
			}
		}
		head = tail = 0;
		mm[man][woman][0].visited = 1;
		list[head] = mm[man][woman][0];
		int res = bfs();
		if (res == -1) cout << "Impossible" << endl;
		else cout << res << endl;
	}
	return 0;
}
