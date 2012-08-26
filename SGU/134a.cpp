#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

#define inf 1000000000

int main() {
	int n;
	scanf("%d", &n);
	//vector<int> cnt(n, 1);;
	vector<vector<int> > link(n);
	vector<int> out;
	deque<int> leaf;
	//vector<int> value(n, 0);
	int cnt[16000], value[16000];
	for (int i = 0; i < n; ++i) {
		cnt[i] = 1, value[i] = 0;
	}
	//for (int i = 0; i < n; ++i) cout << cnt[i] << ' ' << value[i] << endl;
	int k = inf;
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
	for (int i = 0; i < n; ++i) {
		if (link[i].size() == 1) {
			leaf.push_back(i);
			k = n - 1;
			out.push_back(i);
		}
	}
	while (1) {
		int size = leaf.size();
		if (size == 0) break;
		/*
		   cout << "start" << endl;
		   for (int i = 0; i < size; ++i) {
		   cout << leaf[i] << ' ' << cnt[leaf[i]] << ' ' << endl;
		   }
		   cout << "end" << endl;
		 */
		for (int i = 0; i < size; ++i) {
			int now = leaf[i];
			int tmp = value[now];
			if (n != cnt[now] && n - cnt[now] > tmp) tmp = n - cnt[now];
			if (tmp < k) {
				k = tmp;
				out.clear();
				out.push_back(now);
			} else if (tmp == k) {
				out.push_back(now);
			}
			int pa = link[now][0];
			cnt[pa] += cnt[now];
			if (cnt[now] > value[pa]) value[pa] = cnt[now];
			link[pa].erase(remove(link[pa].begin(), link[pa].end(), now), link[pa].end());
			if (link[pa].size() == 1) {
				leaf.push_back(pa);
			}
			link[now].clear();
		}
		for (int i = 0; i < size; ++i) leaf.pop_front();
	}
	sort(out.begin(), out.end());
	printf("%d %d\n", k, out.size());
	for (int i = 0; i < out.size(); ++i) {
		if (i) printf(" ");
		printf("%d", out[i] + 1);
	}
	printf("\n");
	return 0;
}

