/*
 * ZJU 1623 Deal with C++ Comments
 * 00:00.00 2388k
 * 2005.01.10 by adai
 */

#include <iostream>
#include <cstring>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int main() {
	int kase, num;
	char cmd[10000][200];
	int size[100];
	cin >> kase;
	while (kase --) {
		cin >> num;
		int count = 0;
		cin.getline(cmd[0], 200);
		for (int i = 0; i < num; i ++) cin.getline(cmd[i], 200);
		int sign = 0;
		int starti, startj;
		for (int i = 0; i < num; i ++) {
			size[i] = strlen(cmd[i]);
			if (sign == 2) sign = 0;
			for (int j = 0; j < size[i]; j ++) {
				if (cmd[i][j] >= 'a' && cmd[i][j] <= 'z' && sign == 2) {
					cmd[i][j] += 'A' - 'a';
					continue;
				}
				if (cmd[i][j] == '/' && j + 1 < size[i] && cmd[i][j + 1] == '*' && sign == 0) {
					sign = 1;
					j ++;
					starti = i;
					startj = j + 1;
					continue;
				}
				if (cmd[i][j] == '*' && j + 1 < size[i] && cmd[i][j + 1] == '/' && sign == 1) {
					sign = 0;
					j ++;
					count ++;
					if (starti == i) {
						for (int jj = startj; jj <= j; jj ++) {
							if (cmd[i][jj] >= 'a' && cmd[i][jj] <= 'z')
								cmd[i][jj] += 'A' - 'a';
						}
					}
					else {
						for (int jj = startj; jj < size[starti]; jj ++) {
							if (cmd[starti][jj] >= 'a' && cmd[starti][jj] <= 'z')
								cmd[starti][jj] += 'A' - 'a';
						}
						for (int ii = starti + 1; ii < i; ii ++) {
							for (int jj = 0; jj < size[ii]; jj ++)
								if (cmd[ii][jj] >= 'a' && cmd[ii][jj] <= 'z')
									cmd[ii][jj] += 'A' - 'a';
						}
						for (int jj = 0; jj <= j; jj ++) {
							if (cmd[i][jj] >= 'a' && cmd[i][jj] <= 'z')
								cmd[i][jj] += 'A' - 'a';
						}
					}
					continue;
				}
				if (cmd[i][j] == '/' && j + 1 < size[i] && cmd[i][j + 1] == '/' && sign == 0) {
					sign = 2;
					j ++;
					count ++;
				}
			}
		}
		cout << count << endl;
		for (int i = 0; i < num; i ++) cout << cmd[i] << endl;
		cout << endl;
	}
	return 0;
}
