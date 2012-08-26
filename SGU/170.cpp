//ac

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

char aa[5005], bb[5005];

int main() {
	
	scanf("%s %s", aa, bb);
	int len = strlen(aa);
	if (len != strlen(bb)) {
		printf("-1\n");
		return 0;
	}
	int ca = 0, cb = 0;
	for (int i = 0; i < len; ++i) {
		if (aa[i] == '+') ++ca;
		if (bb[i] == '+') ++cb;
	}
	if (ca != cb) {
		printf("-1\n");
		return 0;
	}
	string a(aa), b(bb);
	int ret = 0;
	while (len--) {
		//cout << a << endl << b << endl;
		if (a[0] == b[0]) {
			a = a.substr(1), b = b.substr(1);
		} else {
			int pos = b.find_first_of(a[0]);
			ret += pos;
			a = a.substr(1);
			b = b.substr(0, pos) + b.substr(pos + 1);
		}
		//cout << ret << endl;
	}
	printf("%d\n", ret);
	return 0;
}

