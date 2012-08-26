//ac

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class phone {
public:
	string num;
	bool operator < (const phone &t) const {
		if (num[0] != t.num[0]) {
			return num[0] < t.num[0];
		} else if (num[1] != t.num[1]) {
			return num[1] < t.num[1];
		} else if (num[2] != t.num[2]) {
			return num[2] < t.num[2];
		} else {
			return num[3] < t.num[3];
		}
	}
};

void run() {
	int k, n;
	cin >> k >> n;
	vector<phone> mm(n);
	for (int i = 0; i < n; ++i) cin >> mm[i].num;
	sort(mm.begin(), mm.end());
	int ret = 2, c = 0;
	char last = '*';
	for (int i = 0; i < n; ++i) {
		if (mm[i].num[0] != last) {
			++ret;
			last = mm[i].num[0];
			c = 1;
		} else {
			++c;
			if (c == k + 1) {
				c = 1;
				++ret;
			}
		}
	}
	cout << ret << endl;
}

int main() {
	run();
	return 0;
}

