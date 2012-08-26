/*
 * zju 2201 No Brainer
 * 00:00.00 436k
 * 2004.11.11 by adai
 */

#include <iostream>
using namespace std;

int main() {
	int kase;
	cin >> kase;
	while (kase --) {
		int x, y;
		cin >> x >> y;
		if (x < y) cout << "NO BRAINS" << endl;
		else cout << "MMM BRAINS" << endl;
	}
	return 0;
}
