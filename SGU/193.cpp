//ac

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[2010];
int len;

void sub(int n) {
	for (int i = len - 1; i >= 0; --i) {
		s[i] -= n;
		if (s[i] < '0') {
			s[i] += 10;
			n = 1;
		} else {
			break;
		}
	}
}

void div() {
	int add = 0;
	for (int i = 0; i < len; ++i) {
		int m = s[i] - '0' + add * 10;
		if (m % 2) add = 1;
		else add = 0;
		s[i] = m / 2 + '0';
	}
}

int main() {
	scanf("%s", s);
	len = strlen(s);
	int num = s[len - 1] - '0';
	if (num % 2) {
		sub(1);
		div();
	} else {
		if (len > 1) num += 10 * (s[len - 2] - '0');
		num /= 2;
		div();
		//cout << s << endl;
		//cout << num << endl;
		if (num % 2) {
			sub(2);
		} else {
			sub(1);
		}
	}
	int d = 0;
	while (s[d] == '0') ++d;
	for (d; d < len; ++d) printf("%c", s[d]);
	printf("\n");
	return 0;
}

