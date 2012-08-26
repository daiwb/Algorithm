//ac

#include <iostream>
using namespace std;

int main() {
	int s, p;
	cin >> s >> p;
	int ret = 0;
	if (p - s <= 0) ret = 0;
	else if (p - s < 300) ret = 1;
	else if (p - s < 900) ret = 2;
	else if (p - s < 1800) ret = 3;
	else ret = 4;
	cout << ret << endl;
	return 0;
}

