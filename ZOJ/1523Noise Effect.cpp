/*
 * ZJU 1523 Noise Effect
 * 00:00.17 2092k
 */

#include <iostream>
#include <cstdio>
using namespace std;

int size, maxn, num, ima[400][400], sca[400][400];

int abso(int i)
{
	if (i < 0) return -i;
	return i;
}

int main()
{
	while (scanf("%d", &size) && size)
	{
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				scanf("%d", &ima[i][j]);
			}
		}
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				scanf("%d", &sca[i][j]);
			}
		}

		maxn = 0;

		//1
		num = 0;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (abso(ima[i][j] - sca[i][j]) <= 100) {
					++num;
				}
			}
		}
		if (num > maxn) {
			maxn = num;
		}

		num = 0;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (abso(ima[i][j] - sca[size - 1 - i][j]) <= 100) {
					++num;
				}
			}
		}
		if (num > maxn) {
			maxn = num;
		}

		//2
		num = 0;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (abso(ima[i][j] - sca[j][size - 1 - i]) <= 100) {
					++num;
				}
			}
		}
		if (num > maxn) {
			maxn = num;
		}

		num = 0;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (abso(ima[i][j] - sca[size - 1 - j][size - 1 - i]) <= 100) {
					++num;
				}
			}
		}
		if (num > maxn) {
			maxn = num;
		}

		//3
		num = 0;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (abso(ima[i][j] - sca[size - 1 - i][size - 1 - j]) <= 100) {
					++num;
				}
			}
		}
		if (num > maxn) {
			maxn = num;
		}

		num = 0;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (abso(ima[i][j] - sca[i][size - 1 - j]) <= 100) {
					++num;
				}
			}
		}
		if (num > maxn) {
			maxn = num;
		}

		//4
		num = 0;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (abso(ima[i][j] - sca[size - 1 - j][i]) <= 100) {
					++num;
				}
			}
		}
		if (num > maxn) {
			maxn = num;
		}

		num = 0;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (abso(ima[i][j] - sca[j][i]) <= 100) {
					++num;
				}
			}
		}
		if (num > maxn) {
			maxn = num;
		}

		printf("%.2lf\n", maxn * 100.0 / size / size);
	}
	return 0;
}
