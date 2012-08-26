//zju 1301 The New Villa

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
	int r, l, last;
};

int main() {
	int cc = 0;
	while (1) {
		int n, m, t;
		cin>>n;
		if (!n) break;
		cin>>m>>t;
		int map[10][10], c[10][10];
		memset(map, 0, sizeof(map));
		memset(c, 0, sizeof(c));
		for (int i = 0; i < m; i++) {
			int a, b;
			cin>>a>>b;
			a--; b--;
			map[a][b] = map[b][a] = 1;
		}
		for (int i = 0; i < t; i++) {
			int a, b;
			cin>>a>>b;
			a--;  b--;
			c[a][b] = 1;
		}
		cout<<"Villa #"<<++cc<<endl;
		if (n == 1) {
			cout<<"The problem can be solved in 0 steps:"<<endl<<endl;
			continue;
		}
		Node init;
		init.r = 0; init.l = 1;
		vector<Node> q;
		q.push_back(init);
		int mark[10][1024];
		memset(mark, 0, sizeof(mark));
		mark[0][1] = 1;
		int flag = 0;
		for (int i = 0; i < q.size(); i++) {
			for (int j = 0; j < n; j++) {
				Node t = q[i];
				t.last = i;
				if (c[t.r][j]) {
					t.l ^= 1 << j;
					if (!mark[t.r][t.l] && (t.l & (1 << t.r))) {
						mark[t.r][t.l] = 1;
						q.push_back(t);
						if (t.r == n - 1 && t.l == (1 << n - 1)) {
							flag = 1;
							goto out;
						}
					}	
				}
			}
			for (int j = 0; j < n; j++) {
				Node t = q[i];
				t.last = i;
				if (map[t.r][j]) {
					t.r = j;
					if (!mark[t.r][t.l] && (t.l & (1 << j))) {
						mark[t.r][t.l] = 1;
						q.push_back(t);
					}
				}
			}
		}
out:
		if (!flag) cout<<"The problem cannot be solved."<<endl;
		else {
			vector<Node> t;
			for (int i = q.size() - 1; i > 0; i = q[i].last) {
				t.push_back(q[i]);
			}
			t.push_back(q[0]);
			cout<<"The problem can be solved in "<<t.size() - 1<<" steps:"<<endl;
			for (int i = t.size() - 1; i > 0; i--) {
				cout<<"- ";
				Node &t1 = t[i], &t2 = t[i - 1];
				if (t1.r != t2.r) cout<<"Move to room "<<t2.r + 1<<'.'<<endl;
				else {
					for (int j = 0; j < n; j++)
						if ((t1.l ^ t2.l) == (1 << j)) {
							cout<<"Switch ";
							if (t2.l & (1 << j)) cout<<"on";
							else cout<<"off";
							cout<<" light in room "<<j + 1<<'.'<<endl;
							break;
						}
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
