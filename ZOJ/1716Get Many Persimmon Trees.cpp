/*
 * ZJU 1716 Get Many Persimmon Trees
 * 00:00.00 912k
 * 2005-03-02 by adai
 */

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int n, wid, len, ret, t, h;
int mat[100][100], sum[100][100];

int main()
{
	while (scanf("%d", &n) && n)
	{
		scanf("%d %d", &wid, &len);
		memset(mat, 0, sizeof(mat));
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			mat[y][x] = 1;
		}
		scanf("%d %d", &t, &h);

		for (int i = 1; i <= len; ++i) {
			int tmp = 0;
			for (int j = 1; j <= wid; ++j) {
				tmp += mat[i][j];
				sum[i][j] = sum[i - 1][j] + tmp;
			}
		}

		ret = 0;
		for (int i = 1; i <= len; ++i) {
			if (h + i - 1 > len) break;
			for (int j = 1; j <= wid; ++j) {
				if (t + j - 1 > wid) break;
				int tmp = sum[h + i - 1][t + j - 1] - sum[h + i - 1][j - 1] - sum[i - 1][t + j - 1] + sum[i - 1][j - 1];
				if (tmp > ret) ret = tmp;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
