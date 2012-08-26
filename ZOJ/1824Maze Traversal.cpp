/**
 * ZOJ 1824 Maze Traversal
 */

#include <iostream>
#include <string>
using namespace std;

int row, col;
int mat[60][60];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int flag;
char direction[5] = "NESW";

int Run() {
	string in;
	memset(mat, 0, sizeof(mat));
	getline(cin, in);
	for (int i = 0; i < row; ++i) {
		getline(cin, in);
		for (int j = 0; j < col; ++j) {
			if (in[j] == '*') mat[i][j] = 1;
		}
	}
	flag = 0;
	int x, y;
	cin >> x >> y;
	--x, --y;
	string cmd;
	int quit = 0;
	for (cin >> cmd; ; cin >> cmd) {
		for (int i = 0; i < cmd.size() && !quit; ++i) {
			if (cmd[i] == 'R') flag = (flag + 1) % 4;
			else if (cmd[i] == 'L') flag = (flag + 3) % 4;
			else if (cmd[i] == 'Q') {
				++x, ++y;
				cout << x << ' ' << y << ' ' << direction[flag] << endl;
				quit = 1;
			}
			else if (cmd[i] == 'F') {
				int tx = x + dir[flag][0];
				int ty = y + dir[flag][1];
				if (tx >= 0 && tx < row && ty >= 0 && ty < col && mat[tx][ty] == 0) {
					x = tx, y = ty;
				}
			}
		}
		if (quit) break;
	}
	return 0;
}

int main() {
	while (cin >> row >> col) {
		Run();
	}
	return 0;
}
