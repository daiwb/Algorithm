#include <iostream>
#include <string>
using namespace std;

bool run(int now) {
	string m, n;
	cin >> m >> n;
	if (cin.fail()) {
		return false;
	}
	int mm, nn;					// last digit of m and n
	mm = m[m.length() - 1];
	nn = n[n.length() - 1];
	if (now) {
		cout << endl;
	}
	if (mm & 1 || nn & 1) {
		cout << "1" << endl;
	} else {
		cout << "2" << endl;
	}
	return true;
}

int main() {
	for (int now = 0; run(now); ++now);
	return 0;
}
