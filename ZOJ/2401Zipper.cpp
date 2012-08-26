/**
 * ZOJ 2401 Zipper
 *
 * 2005/04/30 By adai
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int alpha[3][52];
char a[201], b[201], c[401];
int len[3];
int ret;

int search(int ii, int jj, int kk) {
	if (ret) return 0;
	if (kk == len[2]) {
		ret = 1;
		return 0;
	}
	if (ii < len[0] && a[ii] == c[kk]) search(ii + 1, jj, kk + 1);
	if (jj < len[1] && b[jj] == c[kk]) search(ii, jj + 1, kk + 1);
	return 0;
}

int Run() {
	scanf("%s %s %s", a, b, c);
	memset(alpha, 0, sizeof(alpha));
	for (int i = 0; i < len[0]; ++i) {
		if (a[i] >= 'a' && a[i] <= 'z') alpha[0][a[i] - 'a']++;
		else alpha[0][a[i] - 'A' + 26]++;
	}
	for (int i = 0; i < len[1]; ++i) {
		if (b[i] >= 'a' && b[i] <= 'z') alpha[1][b[i] - 'a']++;
		else alpha[1][b[i] - 'A' + 26]++;
	}
	for (int i = 0; i < len[2]; ++i) {
		if (c[i] >= 'a' && c[i] <= 'z') alpha[2][c[i] - 'a']++;
		else alpha[2][c[i] - 'A' + 26]++;
	}
	for (int i = 0; i < 52; ++i) {
		if (alpha[0][i] + alpha[1][i] != alpha[2][i]) {
			printf("no\n");
			return 0;
		}
	}
	
	len[0] = strlen(a), len[1] = strlen(b), len[2] = strlen(c);
	ret = 0;
	search(0, 0, 0);
	if (ret) printf("yes\n");
	else printf("no\n");
	return 0;
}

int main() {
	int kase;
	scanf("%d", &kase);
	for (int kk = 1; kk <= kase; ++kk)
	{
		printf("Data set %d: ", kk);
		Run();
	} 
	return 0;
}
