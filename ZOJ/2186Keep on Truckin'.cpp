/*
 * zju 2186 Keep on Truckin'
 * 00:00.00 436k
 * 2004.11.11 by adai
 */

#include <iostream>
using namespace std;

int main() {
	int h[3], hh, i;
	hh = 168;
	for (i = 0; i < 3; i ++) cin >> h[i];
	int crash = 0;
	for (i = 0; i < 3; i ++) {
		if (h[i] <= hh) {
			cout << "CRASH " << h[i] << endl;
			crash = 1;
			break;
		}
	}
	if (!crash) cout << "NO CRASH" << endl;
	return 0;
}
