/*
 * zju 2202 Alphacode
 * 00:00.00 464k
 * 2004.11.19 by adai
 */

#include <iostream>
#include <cstring>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int getnum(char x, char y) {
	int num = (x - '0') * 10 + y - '0';
	return num;
}

int main() {
	char input[10000];
	while (cin >> input) {
		if (strcmp(input, "0") == 0) break;
		int len = strlen(input);
		int* res = new int[len + 1];

		for (int i = 0; i <= len; i ++) res[i] = 0;

		res[len] = 1;

		if (input[len - 1] == '0') res[len - 1] = 0;
		else res[len - 1] = 1;

		for (int i = len - 2; i >= 0; i --) {
			if (input[i] != '0') res[i] = res[i + 1];
			int temp = getnum(input[i], input[i + 1]);
			if (temp >= 10 && temp <= 26) res[i] += res[i + 2];
		}

		cout << res[0] << endl;
		delete []res;
	}
	return 0;
}
