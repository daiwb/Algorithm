#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

int L, D, N;
vector<char>::iterator vitr;
vector<vector<char> > mm;
string str;
int valid[20][30];
string ts[5005];

void run() {
	mm.clear();
	int idx = 0;
	int cnt = 0;
	while (true) {
		vector<char> t;
		if (str[idx] == '(') {
			++idx;
			while (str[idx] != ')') {
				if (valid[cnt][str[idx] - 'a']) {
					t.push_back(str[idx]);
				}
				++idx;
			}
			++cnt;
			sort(t.begin(), t.end());
			t.erase(unique(t.begin(), t.end()), t.end());
			++idx;
		} else {
			if (valid[cnt][str[idx] - 'a']) {
				t.push_back(str[idx]);
			}
			++cnt;
			++idx;
		}
		mm.push_back(t);
		if (idx == str.length()) break;
	}

	int res = 0;
	REP(i,D) {
		bool flag = true;
		REP(j,L) {
			bool found = false;
			REP(k,mm[j].size()) {
				if (mm[j][k] == ts[i][j]) {
					found = true;
					break;
				}
			}
			if (!found) {
				flag = false;
				break;
			}
		}
		if (flag) ++res;
	}

	cout << res << endl;
}

int main() {
	cin >> L >> D >> N;
	memset(valid, 0, sizeof(valid));
	REP(i,D) {
		cin >> str;
		ts[i] = str;
		REP(j,L) {
			valid[j][str[j] - 'a'] = 1;
		}
	}
	REP(i,N) {
		cin >> str;
		cout << "Case #" << i + 1 << ": ";
		run();
	}
	return 0;
}
