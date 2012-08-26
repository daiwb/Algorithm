#include <iostream>
#include <string>
#include <strstream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int> > table[15][10];

char tree[4096];
int n, m, k, l;

int search(int p)
{
	int l = 0, r = 0, sig = 0;
	if (tree[p * 2 + 1] != '*') {
		l = search(p * 2 + 1);
		r = search(p * 2 + 2);
	}
	else for (int i = n - m; i < n; ++i) {
		l |= 1 << i;
		r |= 1 << i;
	}
	for (int i = 0; i < n; i++) {
		vector<pair<int, int> > &t = table[i][tree[p] - 'a'];
		for (int j = 0; j < t.size(); j++)
			if ((1 << t[j].first & l) && (1 << t[j].second & r)) sig |= 1 << i;
	}
	return sig;
}

int main()
{
	int nta = 0;
	while (1) {
		cin >> n >> m >> k;
		if (!n && !m && !k) break;
		cin >> ws;
		if (nta) cout<<endl;
		cout << "NTA" << ++nta << ":" << endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < k; ++j) {
				table[i][j].clear();
				string s;
				getline(cin, s);
				istrstream is(s.c_str());
				while (1) {
					int a, b;
					is >> a >> b;
					if (is.fail()) break;
					table[i][j].push_back(make_pair(a, b));
				}
			}
		}
		while (1) {
			memset(tree, '*', sizeof(tree));
			int n;
			cin >> l >> ws;
			if (l < 0) break;
			n = (1 << (l + 1)) - 1;
			for (int i = 0; i < n; i++)
				cin >> tree[i];
			if (search(0) & 1) cout << "Valid" << endl;
			else cout << "Invalid" << endl;
		}
	}
	return 0;
}
