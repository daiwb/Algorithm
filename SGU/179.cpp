//ac

#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int len = str.length();
	int num = 0;
	int ret = -1;
	for (int i = len - 1; i >= 0; --i) {
		if (str[i] == '(') {
			++num;
			if (num < 0) {
				ret = i;
				break;
			}
		} else {
			--num;
		}
	}
	if (ret == -1) cout << "No solution" << endl;
	else {
		for (int i = 0; i < ret; ++i) {
			cout << str[i];
		}
		cout << ')';
		int sl = 0, sr = 0;
		for (int i = 0; i < ret; ++i) {
			if (str[i] == '(') ++sl;
			else ++sr;
		}
		++sr;
		for (int i = 0; i < len / 2 - sl; ++i) cout << '(';
		for (int i = 0; i < len / 2 - sr; ++i) cout << ')';
		cout << endl;
	}
	return 0;
}

