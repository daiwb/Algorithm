/**
 * ZOJ 1950 France '98
 *
 * 2005/04/11 By adai
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char country[16][20];
int len[16];
double pro[16][16];
double win[16][4];
int a[4] = {2, 4, 8, 16};

int Run() {
	for (int i = 0; i < 16; ++i) {
		scanf("%s", country[i]);
		//cin >> country[i];
		len[i] = strlen(country[i]);
	}
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 16; ++j) {
			scanf("%lf", &pro[i][j]);
			pro[i][j] /= 100.00;
		}
	}
	memset(win, 0, sizeof(win));
	for (int i = 0; i < 16; ++i) win[i][0] = pro[i][i / 2 * 4 + 1 - i];
	for (int round = 1; round < 4; ++round) {
		for (int i = 0; i < 16; ++i) {
			for (int j = 0; j < 16; ++j) {
				if (i / a[round] == j / a[round] && i / a[round - 1] != j / a[round - 1]) {
					win[i][round] += win[j][round - 1] * pro[i][j];
				}
			}
			win[i][round] *= win[i][round - 1];
		}
	}
	for (int i = 0; i < 16; ++i) {
		printf("%s", country[i]);
		for (int j = 0; j < 11 - len[i]; ++j) printf(" ");
		printf("p=%.2lf", win[i][3] * 100);
		cout << "%" << endl;
	}
	return 0;
}

int main() {
	Run();
	return 0;
}