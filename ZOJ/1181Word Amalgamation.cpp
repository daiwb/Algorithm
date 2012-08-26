/*
zju 1181 Word Amalgamation
00:00.00 392k
2004.09.05 by adai
*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int match(int a[26], int b[26]) {
	for (int i = 0; i < 26; i ++) {
		if (a[i] != b[i]) return 0;
	}
	return 1;
}

int main () {
	char dic[100][7];
	char tt[100][7];
	int count[100][26];
	int num = 0;
	char temp[7];
	int mm[26];

	memset(count, 0, sizeof(count));
	while (1) {
		scanf("%s", temp);
		if (strcmp(temp, "XXXXXX") == 0) break;
		strcpy(dic[num], temp);
		for (int i = 0; temp[i] != '\0'; i ++) count[num][temp[i] - 'a'] ++;
		num ++;
	}
	while (1) {
		scanf("%s", temp);
		if (strcmp(temp, "XXXXXX") == 0) break;
		
		memset(mm, 0, sizeof(mm));
		int sign = 0;
		for (int i = 0; temp[i] != '\0'; i ++) mm[temp[i] - 'a'] ++;

		int index = 0;
		for (int i = 0; i < num; i ++) {
			if (match(mm, count[i])) {
				strcpy(tt[index ++], dic[i]);
			}
		}
		
		int ii, jj;
		char next[7];
		for (ii = 1; ii < index; ii ++) {
			strcpy(next, tt[ii]);
			for (jj = ii - 1; jj >= 0 && strcmp(next, tt[jj]) < 0; jj --) {
				strcpy(tt[jj + 1], tt[jj]);
			}
			strcpy(tt[jj + 1], next);
		}

		for (int i = 0; i < index; i ++) printf("%s\n", tt[i]);
		if (!index) printf("NOT A VALID WORD\n");
		printf("******\n");
	}
	return 0;
}
