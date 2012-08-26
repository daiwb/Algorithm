//ac

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

class station {
	public:
		int cost;
		int idx;
		int dif;
		bool operator < (const station& r) const {
			return dif < r.dif;
		}
};

int n;

int main() {
	scanf("%d", &n);
	vector<station> mm(n + 1);
	vector<int> sum(n + 1);
	sum[0] = 0;
	for (int i = 1; i <= n; ++i) {
		int now, total;
		scanf("%d %d %d", &now, &total, &mm[i].cost);
		mm[i].idx = i;
		sum[i] = sum[i - 1] + now;
		mm[i].dif = sum[i] - total;
	}
	priority_queue<station> que, bk;
	int ret = 1000000000;
	int cost = 0;
	for (int i = n; i >= 1; --i) {
		cost += mm[i].cost;
		while (!que.empty()) {
			station tmp = que.top();
			if (tmp.dif > sum[i - 1]) {
				cost -= tmp.cost;
				que.pop();
			}
			else break;
		}
		que.push(mm[i]);
		if (cost < ret) {
			ret = cost;
			bk = que;
		}
	}
	vector<int> out;
	while (!bk.empty()) {
		out.push_back(bk.top().idx);
		bk.pop();
	}
	sort(out.begin(), out.end());
	for (int i = 0; i < out.size(); ++i) {
		printf("%d\n", out[i]);
	}
	return 0;
}
