//ac

#include <iostream>
using namespace std;

int n, k, ret, n2;
int cx[100], cy[100];
int ten[11] = {1, 100, 3480, 54400, 412596, 1535440, 2716096, 2119176, 636524, 56832, 724};

bool IsValid(int r, int c, int num) {
	for (int i = 0; i < num; ++i) {
		if (cx[i] == r || cy[i] == c || abs(cx[i] - r) == abs(cy[i] - c)) return false;
	}
	return true;
}

void dfs(int r, int c, int step, int num) {
	if (num + n2 - step < k) return;
	if (step == n2 + 1) return;
	if (num == k) {
		++ret;
		return;
	}
	if (c == n) {
		++r, c = 0;
	}
	if (IsValid(r, c, num)) {
		cx[num] = r, cy[num] = c;
		dfs(r, c + 1, step + 1, num + 1);
	}
	dfs(r, c + 1, step + 1, num);
}

void run() {
	cin >> n >> k;
	if (k > n) {
		cout << 0 << endl;
		return;
	}
	if (n == 10) {
		cout << ten[k] << endl;
		return;
	}
	n2 = n * n;
	ret  = 0;
	dfs(0, 0, 0, 0);
	cout << ret << endl;
}

int main() {
	run();
	return 0;
}

