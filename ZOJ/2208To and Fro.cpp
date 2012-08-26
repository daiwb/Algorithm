/*
 * zju 2208 To and Fro
 * 00:00.00 432k
 * 2004.11.18 by adai
 */

#include <iostream>
#include <cstring>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

char out[100][20];
char msg[205];

int main() {
	int row, col;
	while (cin >> col && col) {
		cin >> msg;
		int len = strlen(msg);
		row = len / col;
		int left = 1;
		int index = 0;
		for (int i = 0; i < row; i ++) {
			if (left) {
				for (int j = 0; j < col; j ++) out[i][j] = msg[index ++];
			}
			else {
				for (int j = col - 1; j >= 0; j --) out[i][j] = msg[index ++];
			}
			left = 1 - left;
		}
		for (int j = 0; j < col; j ++) {
			for (int i = 0; i < row; i ++) {
				cout << out[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}
