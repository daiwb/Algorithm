//ac

#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	if (n == 1) cout << 0 << endl;
	else if (n == 2) cout << 1 << endl;
	else {
		long long ret = 0;
		long long  now = 1;
		while (n > now) {
			++ret;
			now = ((now + 1) / ret) * 2 * (ret + 1) - 1;
		}
		cout << ret << endl;
	}
	return 0;
}

