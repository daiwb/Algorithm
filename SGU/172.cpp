//ac

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int flag;

void op(int now, int g, vector<int>& visited, vector<vector<int> >& stu, vector<vector<int> >& cor) {
	if (flag) return;
	visited[now] = g;
	for (int i = 0; i < cor[now].size(); ++i) {
		int s = cor[now][i];
		for (int j = 0; j < 2; ++j) {
			int t = stu[s][j];
			if (t == now) continue;
			if (visited[t]) {
				if (visited[t] == g) {
					flag = 1;
					return;
				}
			} else {
				op(t, 3 - g, visited, stu, cor);
			}
		}
	}
}

int main() {
	int n, m;
	cin >> m >> n;
	vector<vector<int> > stu(n);
	vector<vector<int> > cor(m);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		stu[i].push_back(a), stu[i].push_back(b);
		cor[a].push_back(i), cor[b].push_back(i);
	}
	vector<int> visited(m, 0);
	flag = 0;
	op(0, 1, visited, stu, cor);
	for (int i = 1; i < m; ++i) {
		if (visited[i]) continue;
		op(i, 1, visited, stu, cor);
	}
	if (flag) cout << "no" << endl;
	else {
		cout << "yes" << endl;
		vector<int> out;
		for (int i = 0; i < m; ++i) {
			if (visited[i] == 1) out.push_back(i);
		}
		cout << out.size() << endl;
		for (int j = 0; j < out.size(); ++j) {
			if (j) cout << ' ';
			cout << out[j] + 1;
		}
		cout << endl;
	}
	return 0;
}

