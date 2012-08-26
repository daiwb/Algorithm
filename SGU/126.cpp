//ac

#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int ret = 0;
	int s = a + b;
	while (1) {
		if (a % s == 0) {
			cout << ret << endl;
			return 0;
		}
		else {
			if (s % 2 == 1) {
				cout << -1 << endl;
				return 0;
			} else {
				++ret;
				s /= 2;
			}
		}
	}
	return 0;
}

