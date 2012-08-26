#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct info {
	int len;
	vector<int> pa;
	vector<int> next;
	info() {
		pa.clear();
		next.clear();
	}
};

int m;

int main() {
	int kase = 0;
	while (scanf("%d", &m) != EOF) {
		if (kase++) printf("\n");
		vector<int> mm(m);
		for (int i = 0; i < m; ++i) {
			scanf("%d", &mm[i]);
		}
		vector<info> dd(m);
		dd[m - 1].len = 1;
		dd[m - 1].pa.clear();
		dd[m - 1].next.clear();
		for (int i = m - 2; i >= 0; --i) {
			dd[i].pa.clear(), dd[i].next.clear();
			int ret = 2;
			for (int j = i + 1; j < m; ++j) {
				dd[i].pa.push_back(j);
				dd[i].next.push_back(mm[j] - mm[i]);
			}
			for (int j = i + 1; j < m; ++j) {
				if (dd[j].len + 1 > ret) {
					for (int t = 0; t < dd[j].next.size(); ++t) {
						if (mm[i] == dd[j].next[t]) {
							ret = dd[j].len + 1;
							dd[i].pa.clear();
							dd[i].next.clear();
							dd[i].pa.push_back(j);
							dd[i].next.push_back(mm[j] - mm[i]);
							break;
						}
					}
				} else if (dd[j].len + 1 == ret) {
					for (int t = 0; t < dd[j].next.size(); ++t) {
						if (mm[i] == dd[j].next[t]) {
							dd[i].pa.push_back(j);
							dd[i].next.push_back(mm[j] - mm[i]);
							break;
						}
					}
				}
			}
			
			dd[i].len = ret;
			/*
			cout << "i = " << i << endl;
			cout << dd[i].len << endl;
			for (int ddd = 0; ddd < dd[i].pa.size(); ++ddd) {
				cout << dd[i].pa[ddd] << ' ' << dd[i].next[ddd] << endl;
			}
			cout << "end" << endl;
			*/
		}
		int res = 0, idx = -1;
		for (int i = 0; i < m; ++i) {
			if (dd[i].len > res) {
				res = dd[i].len;
				idx = i;
			}
		}
		printf("%d\n", res);
		printf("%d", mm[idx]);
		int s = mm[idx], t;
		if (res == 1) {
			printf("\n\n");
			continue;
		}
		if (res == 2) {
			printf(" %d\n\n", mm[dd[idx].pa[0]]);
			continue;
		}
		idx = dd[idx].pa[0];
		printf(" %d", mm[idx]);
		t = mm[idx];
		int num = 2;
		//cout << "res = " << res << endl;
		//cout << "num = " << num << endl;
		while (1) {
			if (num == res) break;
			printf(" %d", s + t);
			int tmp = s;
			s = t, t += tmp;
			++num;
		}
		printf("\n");
	}
	return 0;
}

