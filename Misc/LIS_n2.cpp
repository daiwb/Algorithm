#include <iostream>
#include <vector>
using namespace std;

int n;

void Run() {
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	vector<int> mm(n, -1);
	vector<int> next(n, -1);
	for (int i = n - 1; i >= 0; --i) {
		int res = 0, idx = -1;
		for (int j = i + 1; j < n; ++j) {
			if (a[j] > a[i] && mm[j] > res) {
				res = mm[j], idx = j;
			}
		}
		mm[i] = res + 1;
		if (idx != -1) next[i] = idx;
	}
	int ret = 0, idx = -1;
	for (int i = 0; i < n; ++i) {
		if (mm[i] > ret) {
			ret = mm[i], idx = i;
		}
	}
	cout << ret << endl;
	cout << a[idx];
	while (1) {
		idx = next[idx];
		if (idx == -1) break;
		cout << ' ' << a[idx];
	}
	cout << endl;
}

int main() {
	while (cin >> n) {
		Run();
	}
	return 0;
}

