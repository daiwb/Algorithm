//ac

#include <iostream>
#include <string>
using namespace std;

string letter = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string symbol = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-";

bool IsWord(string str) {
	if (str.size() == 0) return false;
	for (int i = 0; i < str.size(); ++i) {
		int pos = symbol.find_first_of(str[i]);
		if (pos == -1) return false;
	}
	return true;
}

bool IsDomain(string str) {
	if (str.size() < 2 || str.size() > 3) return false;
	for (int i = 0; i < str.size(); ++i) {
		int pos = letter.find_first_of(str[i]);
		if (pos == -1) return false;
	}
	return true;
}

bool IsPrefix(string str) {
	int pos = str.find_last_of('.');
	if (pos == -1) {
		return IsWord(str);
	} else {
		return IsPrefix(str.substr(0, pos)) && IsWord(str.substr(pos + 1));
	}
}

bool IsSuffix(string str) {
	int pos = str.find_last_of('.');
	if (pos == -1) return false;
	return IsPrefix(str.substr(0, pos)) && IsDomain(str.substr(pos + 1));
}

bool IsAddress(string str) {
	int pos = str.find_first_of('@');
	if (pos == -1) return false;
	return IsPrefix(str.substr(0, pos)) && IsSuffix(str.substr(pos + 1));
}

char s[200];

void run() {
	cin.getline(s, 200, '\n');
	string str(s);
	if (IsAddress(str)) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int n;
	cin >> n;
	cin.getline(s, 200, '\n');
	while (n--) {
		run();
	}
	return 0;
}
