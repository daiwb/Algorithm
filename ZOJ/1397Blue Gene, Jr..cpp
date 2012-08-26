/**
 * ZOJ 1397 Blue Gene, Jr.
 *
 * 2005/04/02 by adai
 */

#include <iostream>
#include <cstring>
using namespace std;

int n;
char in[25];

int mutate(int start, int end) {
	if (start > end) return 0;
	int tmp;
	if (in[start] >= 'A' && in[start] <= 'Z') {
		if (start == end) {
			in[start] = '0';
			return 1;
		}
		else {
			tmp = mutate(start + 1, end);
			in[start] = tmp % 10 + '0';
			return tmp + 1;
		}
	}
	else if (in[start] == '0') return 0;
	else {
		tmp = in[start] - '0';
		in[start]--;
		if (start + tmp <= end) {
			return 1 + mutate(start + tmp, end);
		}
		else {
			return 1 + mutate(start + 1, end);
		}
	}
	return 0;
}

int Run() {
	cin >> n;
	cin >> in;
	mutate(0, n - 1);
	cout << in << endl;
	return 0;
}

int main() {
	while(cin >> in) {
		if (strcmp(in, "ENDOFINPUT") == 0) break;
		Run();
		cin >> in;
	}
	return 0;
}
