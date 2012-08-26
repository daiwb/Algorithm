/**
 * ZOJ 1150 S-Trees
 *
 * 05/03/29 by adai
 */

#include <iostream>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int n, kase;
int seq[7];
int terminal[128];
int b[7];

int Run() {
	for (int i = 0; i < n; ++i) {
		char sequence[3];
		cin >> sequence;
		seq[i] = sequence[1] - '1';
	}
	int total = 1 << n;
	char temp[129];
	cin >> temp;
	for (int i = 0; i < total; ++i) {
		terminal[i] = temp[i] - '0';
	}
	cout << "S-Tree #" << ++kase << ":" << endl;
	int num;
	cin >> num;
	while (num--) {
		int pos = 0;
		cin >> temp;
		for (int i = 0; i < n; ++i) {
			b[i] = temp[i] - '0';
		}
		for (int i = 0; i < n; ++i) {
			if (b[seq[i]]) pos = pos * 2 + 1;
			else pos *= 2;
		}
		cout << terminal[pos];
	}
	cout << endl << endl;
	return 0;
}

int main() {
	while (cin >> n && n) {
		Run();
	}
	return 0;
}
