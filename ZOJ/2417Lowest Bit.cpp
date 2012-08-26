/**
 * ZOJ 2417 Lowest Bit
 */

#include <iostream>
using namespace std;

int n;

int main() {
	while (cin >> n && n) {
		for (int i = 0; ; ++i) {
			if (n & (1 << i)) {
				cout << (1 << i) << endl;
				break;
			}
		}
	}
	return 0;
}