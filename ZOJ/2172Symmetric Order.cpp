/*
 * zju 2172 Symmetric Order
 * 00:00.00 436k
 * 2004.11.11 by adai
 */

#include <iostream>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int main() {
	char in[15][26];
	int n, kase = 1, i;
	while (1) {
		cin >> n;
		if (!n) break;
		for (i = 0; i < n; i ++) cin >> in[i];
		cout << "SET " << kase ++ << endl;
		for (i = 0; i < n; i += 2) cout << in[i] << endl;
		if (n % 2) i = n - 2;
		else i = n - 1;
		for (; i >= 0; i -= 2) cout << in[i] << endl;
	}
	return 0;
}
