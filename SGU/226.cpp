//ac

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 200

class line {
	public:
		int next;
		int c;
		line(int nn, int cc) : next(nn), c(cc) {}
};

class State {
	public:
		int now;
		int color;
		int cost;

		State(int nn, int cc, int c) : now(nn), color(cc), cost(c) {}
		bool operator < (const State &r) const {
			return cost > r.cost;
		}
};

int n, m;
int sp[MAXN][3];

void run() {
	scanf("%d %d", &n, &m);
	vector<vector<line> > link(n, vector<line>());
	while (m--) {
		int from, to, c;
		scanf("%d %d %d", &from, &to, &c);
		--from, --to, --c;
		link[from].push_back(line(to, c));
	}
	memset(sp, 0, sizeof(sp));
	priority_queue<State> pq;
	for (int i = 0; i < link[0].size(); ++i) {
		pq.push(State(link[0][i].next, link[0][i].c, 1));
	}
	while (!pq.empty()) {
		State cur = pq.top();
		pq.pop();

		if (sp[cur.now][cur.color] == 1) continue;
		sp[cur.now][cur.color] = 1;
		if (cur.now == n - 1) {
			printf("%d\n", cur.cost);
			return;
		}

		int now = cur.now, color = cur.color, cost = cur.cost;
		for (int i = 0; i < link[now].size(); ++i) {
			if (link[now][i].c != color) {
				pq.push(State(link[now][i].next, link[now][i].c, cost + 1));
			}
		}
	}
	printf("-1\n");
}

int main() {
	run();
	return 0;
}
