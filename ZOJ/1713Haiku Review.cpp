/*
 * zju 1713 Haiku Review
 * 00:00.00 436k
 * 2004.10.14 by adai
 */

#include <iostream>
#include <cstring>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int IsVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') return 1;
	return 0;
}

int main() {
	char haiku[205];
	while (1) {
		cin.getline(haiku, 205, '\n');
		if (strcmp(haiku, "e/o/i") == 0) break;
		int i, num = 0, index = 0, last = 0, sign = 1;
		for (i = 0; ; i ++) {
			if (haiku[i] == '/') {
				if (!((index == 0 && num == 5) || (index == 1 && num == 7))) {
					sign = 0;
					cout << index + 1 << endl;
					break;
				}
				else {
					index ++;
					num = 0;
					last = 0;
					continue;
				}
			}

			if (haiku[i] == '\0') {
				if (num != 5) {
					sign = 0;
					cout << index + 1 << endl;
				}
				break;
			}

			if (IsVowel(haiku[i])) {
				if (!last) {
					num ++;
					last = 1;
				}
			}
			else last = 0;
		}
		if (sign) cout << "Y" << endl;
	}
	return 0;
}
