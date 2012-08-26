/**
 * ZOJ 2207 Team Rankings
 *
 * 2005/05/06 By adai
 */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int n;
char rank[6];
int mat[100][5][5];
int tmp[5][5];
int ii[5];
int out[5];
int value, mm;

int Run() {
	for (int i = 0; i < n; ++i) {
		scanf("%s", rank);
		for (int j = 0; j < 4; ++j) {
			for (int k = j + 1; k < 5; ++k) {
				int a = rank[j] - 'A', b = rank[k] - 'A';
				if (a > b) mat[i][b][a] = 1;
				else mat[i][a][b] = 0;
			}
		}
	}
	value = 10 * n;
	for (ii[0] = 0; ii[0] < 5; ++ii[0]) {
		for (ii[1] = 0; ii[1] < 5; ++ii[1]) {
			if (ii[1] == ii[0]) continue;
			for (ii[2] = 0; ii[2] < 5; ++ii[2]) {
				if (ii[2] == ii[0] || ii[2] == ii[1]) continue;
				for (ii[3] = 0; ii[3] < 5; ++ii[3]) {
					if (ii[3] == ii[0] || ii[3] == ii[1] || ii[3] == ii[2]) continue;
					ii[4] = 10 - ii[0] - ii[1] - ii[2] - ii[3];
					mm = 0;
					for (int i = 0; i < 4; ++i) {
						for (int j = i + 1; j < 5; ++j) {
							int a = ii[i], b = ii[j];
							if (a > b) tmp[b][a] = 1;
							else tmp[a][b] = 0;
						}
					}
					int quit = 0;
					for (int i = 0; i < 4; ++i) {
						if (quit) break;
						for (int j = i + 1; j < 5; ++j) {
							if (quit) break;
							for (int k = 0; k < n; ++k) {
								if (tmp[i][j] != mat[k][i][j]) {
									++mm;
									if (mm >= value) {
										quit = 1;
										break;
									}
								}
							}
						}
					}
					if (quit == 0) {
						value = mm;
						for (int i = 0; i < 5; ++i) out[i] = ii[i];
					}
				}
			}
		}
	}
	for (int i = 0; i < 5; ++i) {
		printf("%c", out[i] + 'A');
	}
	printf(" is the median ranking with value %d.\n", value);
	return 0;
}

int main() {
	while (scanf("%d", &n) && n != 0) {
		Run();
	}
	return 0;
}
