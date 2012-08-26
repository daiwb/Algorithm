/*
 * ZJU 1798 Granny's Bike
 * 00:00.00 864k
 * 2005-03-02 by adai
 */

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int n, flag, kase = 1;
int mat[10][10];
int visited[10];

int dfs(int ii, int num)
{
	if (flag) return 0;

	if (num == n + 1) {
		if (mat[ii][0]) {
			flag = 1;
			return 0;
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (mat[ii][i] == 0) continue;
		if (visited[i]) continue;
		visited[i] = 1;
		dfs(i, num + 1);
		visited[i] = 0;
	}
	return 0;
}

int main()
{
	while (cin >> n && n)
	{
		char input[100];
		cin.getline(input, 100);
		memset(mat, 0, sizeof(mat));
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= n; ++i) {
			cin.getline(input, 100);
			istringstream is(input);
			int tmp;
			while (is >> tmp) {
				mat[i][tmp] = mat[tmp][i] = 1;
			}
		}
		flag = 0;
		visited[0] = 1;
		dfs(0, 1);

		cout << "Case " << kase++ << ": ";
		if (flag) cout << "Granny can make the circuit." << endl;
		else cout << "Granny can not make the circuit." << endl;
	}
	return 0;
}
