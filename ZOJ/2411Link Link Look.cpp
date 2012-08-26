/**
 * ZOJ 2411 Link Link Look
 *
 * 2005/04/22 By adai
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

#define MAXN 100

int n, m, ret;
int mat[MAXN + 2][MAXN + 2];
int HH[MAXN + 2][MAXN + 2], VV[MAXN + 2][MAXN + 2];

int connect(int x1, int y1, int x2, int y2)
{
	if (mat[x1][y1] != mat[x2][y2]) return 0;
	if (mat[x1][y1] == 0) return 0;

	if (x1 == x2 && y1 == y2) return 1;

	if (x1 == x2)
	{
		if (abs(HH[x1][y1] - HH[x2][y2]) == 1) return 1;
	}
	if (y1 == y2)
	{
		if (abs(VV[x1][y1] - VV[x2][y2]) == 1) return 1;
	}

	int bb, ss;

	int left, right;
	left = right = y1;
	while (left - 1 >= 0 && mat[x1][left - 1] == 0) --left;
	while (right + 1 <= m + 1 && mat[x1][right + 1] == 0) ++right;

	int left2, right2;
	left2 = right2 = y2;
	while (left2 - 1 >= 0 && mat[x2][left2 - 1] == 0) --left2;
	while (right2 + 1 <= m + 1 && mat[x2][right2 + 1] == 0) ++right2;

	if (left < left2) left = left2;
	if (right > right2) right = right2;

	bb = x1, ss = x2;
	if (bb < ss) bb ^= ss ^= bb ^= ss;
	for (int i = left; i <= right; ++i)
	{
		if (VV[bb - 1][i] == VV[ss][i]) return 1;
	}

	int up, down;
	up = down = x1;
	while (up - 1 >= 0 && mat[up - 1][y1] == 0) --up;
	while (down + 1 <= n + 1 && mat[down + 1][y1] == 0) ++down;

	int up2, down2;
	up2 = down2 = x2;
	while (up2 - 1 >= 0 && mat[up2 - 1][y2] == 0) --up2;
	while (down2 + 1 <= n + 1 && mat[down2 + 1][y2] == 0) ++down2;

	if (up < up2) up = up2;
	if (down > down2) down = down2;

	bb = y1, ss = y2;
	if (bb < ss) bb ^= ss ^= bb ^= ss;
	for (int i = up; i <= down; ++i)
	{
		if (HH[i][bb - 1] == HH[i][ss]) return 1;
	}

	return 0;
}

int Run()
{
	ret = 0;
	memset(mat, 0, sizeof(mat));
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j)
			scanf("%d", &mat[i][j]);
	memset(HH, 0, sizeof(HH));
	memset(VV, 0, sizeof(VV));
	for (int i = 1; i <= n + 1; ++i)
	{
		for (int j = 1; j <= m + 1; ++j)
		{
			if (mat[i][j] > 0) HH[i][j] = HH[i][j - 1] + 1;
			else HH[i][j] = HH[i][j - 1];
		}
	}
	for (int j = 1; j <= m + 1; ++j)
	{
		for (int i = 1; i <= n + 1; ++i)
		{
			if (mat[i][j] > 0) VV[i][j] = VV[i - 1][j] + 1;
			else VV[i][j] = VV[i - 1][j];
		}
	}
	int kase;
	scanf("%d", &kase);
	while (kase--)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if (connect(x1, y1, x2, y2))
		{
			if (x1 == x2 && y1 == y2) {
				++ret;
				mat[x1][y1] = 0;
				for (int i = x1; i <= n + 1; ++i) --VV[i][y1];
				for (int i = y1; i <= m + 1; ++i) --HH[x1][i];
			}
			else
			{
				ret += 2;
				mat[x1][y1] = mat[x2][y2] = 0;
				for (int i = x1; i <= n + 1; ++i) --VV[i][y1];
				for (int i = x2; i <= n + 1; ++i) --VV[i][y2];
				for (int i = y1; i <= m + 1; ++i) --HH[x1][i];
				for (int i = y2; i <= m + 1; ++i) --HH[x2][i];
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}

int main() {
	while (scanf("%d %d", &n, &m))
	{
		if (n == 0 && m == 0) break;
		Run();
	}
	return 0;
}

