//ac

#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	int aa, bb, cc;
	cin >> aa >> bb >> cc >> a >> b >> c;
	int ret = 100000000;
	if (aa / a < ret) ret = aa / a;
	if (bb / b < ret) ret = bb / b;
	if (cc / c < ret) ret = cc / c;
	cout << ret << endl;
	return 0;
}

