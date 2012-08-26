/*
 * ZJU 2165 Red and Black
 * 00:00.05 856k
 * 2005.03.19 by adai
 */

#include <iostream>
using namespace std;

int width, height;
int mat[20][20];
int start[2];
char input[21];
int ret;
int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};

int search(int ii, int jj)
{
	int tx, ty;
	for (int i = 0; i < 4; ++i)
	{
		tx = ii + dir[i][0];
		ty = jj + dir[i][1];
		if (tx < 0 || tx >= height || ty < 0 || ty >= width) continue;
		if (mat[tx][ty]) continue;
		mat[tx][ty] = 1;
		++ret;
		search(tx, ty);
	}
	return 0;
}

int main()
{
	while (cin >> width >> height && width + height)
	{
		for (int i = 0; i < height; ++i)
		{
			cin >> input;
			for (int j = 0; j < width; ++j)
			{
				if (input[j] == '#') mat[i][j] = 1;
				else if (input[j] == '.') mat[i][j] = 0;
				else
				{
					mat[i][j] = 0;
					start[0] = i, start[1] = j;
				}
			}
		}

		mat[start[0]][start[1]] = 1;
		ret = 1;
		search(start[0], start[1]);
		cout << ret << endl;
	}
	return 0;
}