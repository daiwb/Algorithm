//ac

#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

#define inf 1000000000

int n, k, ret;

void f(int now, vector<vector<int> >& link, vector<int>& child, vector<int>& visited) {
	visited[now] = 1;
	for (int i = 0; i < link[now].size(); ++i) {
		int next = link[now][i];
		if (visited[next]) continue;
		f(next, link, child, visited);
		if (child[next] > 0) child[now] += child[next];
	}
	if (child[now] > ret) ret = child[now];
}

int main() {
	scanf("%d", &n);
	vector<vector<int> > link(n);
	vector<int> child(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &child[i]);
	}
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		link[a].push_back(b);
		link[b].push_back(a);
	}
	vector<int> visited(n, 0);
	ret = -inf;
	f(0, link, child, visited);
	printf("%d\n", ret);
	return 0;
}

