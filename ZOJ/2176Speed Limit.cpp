/*
 * zju 2176 Speed Limit
 * 00:00.00 436k
 * 2004.11.11 by adai
 */

#include <iostream>
using namespace std;

int main() {
	int n;
	while (1) {
		cin >> n;
		if (n == -1) break;
		int t, s, tt = 0, miles = 0;
		while (n --) {
			cin >> s >> t;
			miles += (t - tt) * s;
			tt = t;
		}
		cout << miles << " miles" << endl;
	}
	return 0;
}
