#include <iostream>
#include <vector>
using namespace std;

int n;

void Run() {
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
    // mm[i] is the smallest ending element for a sequence of length i + 1
	vector<int> mm(n);
	int len = -1;
	for (int i = 0; i < n; ++i) {
		int left = 0, right = len, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (mm[mid] < a[i]) left = mid + 1;
			else right = mid - 1;
		}
		mm[left] = a[i];
		if (left > len) len = left;
	}
	cout << len + 1 << endl;
	for (int i = 0; i <= len; ++i) {
		if (i) cout << ' ';
		cout << mm[i];
	}
	cout << endl;
}

int main() {
	while (cin >> n) {
		Run();
	}
}

