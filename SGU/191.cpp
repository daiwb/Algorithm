//ac

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main() {
	char a[30001];
	int idx;
	char c;
	string str;
	cin >> c >> str;
	idx = 0;
	int len = str.length();
	for (int i = 0; i < len; ++i) {
		if (idx == 0) {
			idx = 1;
			a[1] = str[i];
		} else {
			if (str[i] == a[idx]) --idx;
			else a[++idx] = str[i];
		}
	}
	if (idx > 1 || a[1] == c) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}

