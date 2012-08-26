/**
 * ZOJ 1699 Colorville
 *
 * Algo Desc: Simulation
 *
 * 2005/04/02 By ADAI
 */

#include <iostream>
using namespace std;

int n[3];
char board[80];
char cmd[200][3];
int pos[4];
int turn;

int Run() {
	int i, j;
	cin >> board;
	for (i = 0; i < n[2]; ++i) cin >> cmd[i];
	for (i = 0; i < n[0]; ++i) pos[i] = -1;
	turn = 0;
	for (i = 0; i < n[2]; ++i) {
		int num = strlen(cmd[i]);
		for (j = pos[turn] + 1; ; ++j) {
			if (board[j] == cmd[i][0]) --num;
			if (num == 0) break;
			if (j == n[1] - 1) break;
		}
		if (j == n[1] - 1) {
			cout << "Player " << turn + 1 << " won after " << i + 1 << " cards." << endl;
			return 0;
		}
		pos[turn++] = j;
		if (turn == n[0]) turn = 0;
	}
	cout << "No player won after " << n[2] << " cards." << endl;
	return 0;
}

int main() {
	while (cin >> n[0] >> n[1] >> n[2] && n[0]) {
		Run();
	}
	return 0;
}
