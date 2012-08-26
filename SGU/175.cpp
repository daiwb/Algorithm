//ac

#include <iostream>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	int add = 0;
	while (1) {
		if (n == 1) break;
		int n2 = n / 2;
		if (q <= n2) {
			add += n - n2;
			q = n2 - q + 1;
			n = n2;
		} else {
			q = n - q + 1;
			n = n - n2;
		}
		//cout << "q = " << q << ", n = " << n << ", add = " << add << endl;
	}
	cout << q + add << endl;
	return 0;
}

