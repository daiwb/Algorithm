#include <iostream>
#include <cstring>
using namespace std;

#ifndef WIN32
typedef long long i64;
#else
typedef __int64 i64;
#endif

#ifdef WIN32
#define for if(0); else for
#endif

int n;
i64 ret;
int out[50];

void Run() {
	ret = 0;
	for (int i = 0; i < n; ++i) {
		char str[50];
		cin >> str;
		int len = strlen(str);
		i64 temp = 0;
		for (int j = 0; j < len; ++j) {
			if (! (str[j] >= '0' && str[j] <= '9')) continue;
			temp = temp * 10 + str[j] - '0';
		}
		ret += temp;
	}
	int tt = 0;
	while (ret > 0) {
		out[tt++] = ret % 10;
		ret /= 10;
	}
	while (tt < 3) out[tt++] = 0;
	cout << '$';
	for (int i = tt - 1; i >= 2; --i) {
		cout << out[i];
		if (i != 2 && ((i - 2) % 3 == 0)) cout << ',';
	}
	cout << '.' << out[1] << out[0] ;
	cout << endl;
}

int main() {
	while (cin >> n && n) {
		Run();
	}
	return 0;
}