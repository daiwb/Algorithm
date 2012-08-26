#pragma warning(disable:4786)

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
using namespace std;

#define for if(0); else for
#define inf 1000000000

int small(int a, int b) {
	return a < b ? a : b;
}

class junction {
	public:
		char color;
		int rem;
		int tb;
		int tp;
};

class state {
	public:
		int t;
		int pos;
		state(int tt, int pp) : t(tt), pos(pp) {}
		bool operator<(const state& rhs) const {
			return t > rhs.t;
		}
};

int src, des;
int n, m;

vector<junction> jc;

// get the current color of a specific junction
char curc(int t, int idx) {
	if (t < jc[idx].rem) return jc[idx].color;
	t -= jc[idx].rem;
	t %= (jc[idx].tb + jc[idx].tp);
	if (jc[idx].color == 'B') {
		if (t < jc[idx].tp) return 'P';
		else return 'B';
	} else {
		if (t < jc[idx].tb) return 'B';
		else return 'P';
	}
}

int tcha(int t, int idx) {
	if (t < jc[idx].rem) return jc[idx].rem;
	t -= jc[idx].rem;
	int bk = t / (jc[idx].tb + jc[idx].tp) * (jc[idx].tb + jc[idx].tp) + jc[idx].rem;
	t %= (jc[idx].tb + jc[idx].tp);
	if (jc[idx].color == 'B') {
		if (t < jc[idx].tp) return bk + jc[idx].tp;
		else return bk + jc[idx].tp + jc[idx].tb;
	} else {
		if (t < jc[idx].tb) return bk + jc[idx].tb;
		else return bk + jc[idx].tb + jc[idx].tp;
	}
}

int main() {
	scanf("%d %d", &src, &des);
	--src, --des;
	scanf("%d %d", &n, &m);
	jc.resize(n);
	for (int i = 0; i < n; ++i) {
		char str[10];
		scanf("%s %d %d %d", str, &jc[i].rem, &jc[i].tb, &jc[i].tp);
		jc[i].color = str[0];
	}
	vector<vector<int> > len(n, vector<int>(n, -1));
	vector<int> pa(n, -1);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		--a, --b;
		len[a][b] = len[b][a] = c;
	}
	int ret = inf;
	priority_queue<state> que;
	vector<int> out;
	que.push(state(0, src));
	vector<int> flag(n, inf);
	flag[src] = 0;
	while (!que.empty()) {
		state cur = que.top(); que.pop();
		if (cur.pos == des) {
			ret = cur.t;
			int dd = cur.pos;
			while (1) {
				out.push_back(dd);
				dd = pa[dd];
				if (dd == -1) break;
			}
			while (!que.empty()) {
				que.pop();
			}
			break;
		}
		int from = cur.pos;
		for (int i = 0; i < n; ++i) {
			if (len[from][i] == -1) continue;
			int to = i;
			char cf, ct;
			cf = curc(cur.t, from); ct = curc(cur.t, to);
			if (cf == ct) {
				int sum = cur.t + len[from][to];
				if (sum >= flag[to]) continue;
				flag[to] = sum;
				pa[to] = from;
				que.push(state(sum, to));
			} else {
				int nf, nt;
				nf = tcha(cur.t, from); nt = tcha(cur.t, to);
				if (nf != nt) {
					int sum = len[from][to] + small(nf, nt);
					if (sum >= flag[to]) continue;
					flag[to] = sum;
					pa[to] = from;
					que.push(state(sum, to));
				} else {
					nf = tcha(nf, from); nt = tcha(nt, to);
					if (nf != nt) {
						int sum = len[from][to] + small(nf, nt);
						if (sum >= flag[to]) continue;
						flag[to] = sum;
						pa[to] = from;
						que.push(state(sum, to));
					}
				}
			}
		}
	}
	if (ret == inf) {
		printf("0\n");
		return 0;
	}
	printf("%d\n", ret);
	for (int i = out.size() - 1; i >= 0; --i) {
		printf("%d ", out[i] + 1);
	}
	printf("\n");
	return 0;
}
