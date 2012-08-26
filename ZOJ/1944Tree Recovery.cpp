/**
 * ZOJ 1944 Tree Recovery
 *
 * 2005/04/11 By adai
 */

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char a[27], b[27];

int rec(int a1, int b1, int a2, int b2) {
	if (a1 > b1) return 0;
	for (int i = a2; i <= b2; ++i) {
		if (a[a1] == b[i]) {
			rec(a1 + 1, a1 + i - a2, a2, i - 1);
			rec(a1 + i - a2 + 1, b1, i + 1, b2);
			printf("%c", a[a1]);
			return 0;
		}
	}
	return 0;
}

int Run() {
	int len = strlen(a);
	rec(0, len - 1, 0, len - 1);
	printf("\n");
	return 0;
}

int main() {
	while (1) {
		cin >> a >> b;
		if (cin.fail()) break;
		Run();
	}
	return 0;
}
