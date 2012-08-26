/**
 * ZOJ 2418 Matrix
 *
 * 2005/05/07 By adai
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

int n, mat[7][7], ret, mm;
int value[7][7];

void search(int index) {
	if (index == n) {
		mm = value[index - 1][0];
		for (int i = 1; i < n; ++i) {
			if (value[index - 1][i] > mm) mm = value[index - 1][i];
		}
		if (mm < ret) ret = mm;
		return;
	}
	for (int i = 0; i < n; ++i) {
		int bk = mat[index][0];
		for (int j = 0; j < n - 1; ++j) mat[index][j] = mat[index][j + 1];
		mat[index][n - 1] = bk;
		for (int j = 0; j < n; ++j) {
			value[index][j] = value[index - 1][j] + mat[index][j];
		}
		search(index + 1);
	}
}

void Run() {
	ret = 500000;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &mat[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		value[0][i] = mat[0][i];
	}
	search(1);
	printf("%d\n", ret);
}

int main() {
	while (scanf("%d", &n) && n >= 1) {
		Run();
	}
	return 0;
}
