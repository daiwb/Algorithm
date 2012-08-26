#include <iostream>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

class window {
public:
	int upper;
	int left;
	int lower;
	int right;
}ww[10];

int n;

void Run() {
	for (int i = 0; i < n; ++i) {
		cin >> ww[i].upper >> ww[i].left >> ww[i].lower >> ww[i].right;
	}
	int m;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		int flag = 1;
		for (int i = n - 1; i >= 0; --i) {
			if (x >= ww[i].upper && x <= ww[i].lower && y >= ww[i].left && y <= ww[i].right) {
				cout << i << endl;
				flag = 0;
				break;
			}
		}
		if (flag) cout << "-1" << endl;
	}
}

int main() {
	while (cin >> n && n) {
		Run();
	}
	return 0;
}