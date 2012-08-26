//ac

#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

#define inf 1000000000

int n, k;

void f(int now, vector<vector<int> >& link, vector<int>& child, vector<int>& visited) {
	visited[now] = 1;
	int ret = 0;
	for (int i = 0; i < link[now].size(); ++i) {
		int next = link[now][i];
		if (visited[next]) continue;
		f(next, link, child, visited);
		ret += child[next];
	}
	child[now] = ret + 1;
}


void g(int now, vector<vector<int> >& link, vector<int>& child, vector<int>& visited, vector<int>& out) {
	visited[now] = 1;
	int t = 0, sum = 0;
	for (int i = 0; i < link[now].size(); ++i) {
		int next = link[now][i];
		if (visited[next]) continue;
		g(next, link, child, visited, out);
		sum += child[next];
		if (child[next] > t) t = child[next];
	}
	++sum;
	if (n - sum > t) t = n - sum;
	//cout << "now = " << now << ", t = " << t << ", sum = " << sum << endl;
	if (t < k) {
		k = t;
		out.clear();
		out.push_back(now);
	} else if (t == k) {
		out.push_back(now);
	}
}

int main() {
	scanf("%d", &n);
	vector<vector<int> > link(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		link[a].push_back(b);
		link[b].push_back(a);
	}
	if (n == 1) {
		printf("0 1\n1\n");
		return 0;
	} else if (n == 2) {
		printf("1 2\n1 2\n");
		return 0;
	}
	vector<int> visited(n, 0);
	vector<int> child(n);
	f(0, link, child, visited);
	vector<int> out;
	k = inf;
	visited.assign(n, 0);
	g(0, link, child, visited, out);
	sort(out.begin(), out.end());
	printf("%d %d\n", k, out.size());
	for (int i = 0; i < out.size(); ++i) {
		if (i) printf(" ");
		printf("%d", out[i] + 1);
	}
	printf("\n");
	return 0;
}

