/**
 * ZOJ 1164 Software CRC
 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

char input[1030];
unsigned long ret, len;
int g = 34943;
int result[4];

int Run() {
	ret = 0;
	len = strlen(input);
	for (int i = 0; i < len; ++i) {
		ret = (ret * 256 + input[i]) % g;
	}
	ret *= 65536;
	ret %= g;
	if (ret == 0) {
		cout << "00 00" << endl;
		return 0;
	}
	ret = g - ret;
	for (int i = 3; i >= 0; --i) {
		result[i] = ret % 16;
		ret /= 16;
	}
	for (int i = 0; i < 4; ++i) {
		cout << setiosflags(ios::uppercase) << hex << result[i];
		if (i == 1) cout << ' ';
	}
	cout << endl;
	return 0;
}

int main() {
	while (1) {
		cin.getline(input, 1030, '\n');
		if (strcmp(input, "#") == 0) break;
		Run();
	}
	return 0;
}
