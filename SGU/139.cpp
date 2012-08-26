//ac

#include <iostream>
using namespace std;

int main() {
	int a[17];
	int r, c;
	for (int i = 1; i <= 16; ++i) {
		cin >> a[i];
		if (a[i] == 0) {
			r = (i - 1) / 4 + 1, c = (i - 1) % 4 + 1;
			a[i] = 16;
		}
	}
	int cnt = 0;
	for (int i = 1; i < 16; ++i) {
		for (int j = i + 1; j <= 16; ++j) {
			if (a[i] > a[j]) ++cnt;
		}
	}
	if ((cnt + r + c) & 1) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}

