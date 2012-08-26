//ac

#include <iostream>
#include <string>
#include <vector>
using namespace std;

char upper(char c) {
  if (c >= 'A' && c <= 'Z') return c;
  return c - 'a' + 'A';
}

char lower(char c) {
  if (c >= 'a' && c <= 'z') return c;
  return c - 'A' + 'a';
}

int main() {
  string str;
  cin >> str;
  string ret;
  vector<int> sign;
  for (int i = 0; i < str.length(); ++i) {
    if (str[i] == '<') {
      if (str[i + 1] == '/') {
	if (str[i + 2] == 'U') i += 4;
	else i += 6;
	sign.pop_back();
      } else {
	if (str[i + 1] == 'U') {
	  sign.push_back(1);
	  i += 3;
	}
	else {
	  sign.push_back(0);
	  i += 5;
	}
      }
    } else {
      if (sign.empty()) {
	ret += str[i];
      } else if (sign.back() == 1) {
	ret += upper(str[i]);
      } else {
	ret += lower(str[i]);
      }
    }
  }
  cout << ret << endl;
  return 0;
}
