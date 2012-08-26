//Little shop of flowers

#include <iostream>
#include <string>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int main() {
	int a[100][100];
	int b[100][100];
	int f, v;
	cin >> f >> v;
	for (int i = 0; i < f; i ++) {
		for (int j = 0; j < v; j ++) {
			cin >> a[i][j];
			b[i][j] = -500000;
		}
	}
	for (int i = 0; i < v; i ++) b[f - 1][i] = a[f - 1][i];
	for (int i = f - 2; i >= 0; i --) {
		for (int j = 0; j < v; j ++) {
			int temp = -500000;
			for (int t = j + 1; t < v; t ++) {
				if (b[i + 1][t] > temp) temp = b[i + 1][t];
			}
			b[i][j] = a[i][j] + temp;
		}
	}
	int res = -500000, index;
	for (int i = 0; i < v; i ++) {
		if (b[0][i] > res) {
			res = b[0][i];
			index = i;
		}
	}
	cout << res << endl;
	cout << index + 1;
	res -= a[0][index];
	for (int i = 1; i < f; i ++) {
		for (int j = index + 1; j < v; j ++) {
			if (b[i][j] == res) {
				cout << " " << j + 1;
				res -= a[i][j];
				index = j;
				break;
			}
		}
	}
	cout << endl;
	return 0;
}
