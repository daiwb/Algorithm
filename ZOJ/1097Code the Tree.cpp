/*
zju 1097 Code the Tree
00:00.00 440k
2004.08.19 by adai
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

#define MAXN 1000
int father[MAXN];
int leaf[MAXN];	//represent how many leaves this node has
int mn;	//maximum number
int total;	//equal mn
int root;	//the root of the tree

void mm(char input[MAXN], int start, int end, int num) {
	int nn = 0;
	int i;
	for (i = start; i <= end; i ++) {
		if (input[i] == ' ') break;
		nn = nn * 10 + input[i] - '0';
	}
	leaf[nn] = 0;
	total ++;
	leaf[num] ++;
	father[nn] = num;
	int tt = 0;
	int begin = i + 1;
	for (i ++; i <= end; i ++) {
		if (input[i] == '(') tt ++;
		if (input[i] == ')') {
			tt --;
			if (tt == 0) {
				mm(input, begin + 1, i - 1, nn);
				begin = i + 2;
			}
		}
	}
}

int main () {
	char input[MAXN];
	int i;
	while (1) {
		cin.getline(input, MAXN, '\n');
		if (cin.fail()) break;

		memset(father, 0, sizeof(father));
		memset(leaf, -1, sizeof(leaf));

		int len = strlen(input);
		int num = 0;
		mn = total = 0;
		for (i = 1; i < len - 1; i ++) {
			if (input[i] == ' ') break;
			num = num * 10 + input[i] - '0';
		}
		root = num;
		total ++;
		leaf[num] = 0;
		int tt = 0;
		int start = i + 1;
		for (i ++; i < len - 1; i ++) {
			if (input[i] == '(') tt ++;
			if (input[i] == ')') {
				tt --;
				if (tt == 0) {
					mm(input, start + 1, i - 1, num);
					start = i + 2;
				}
			}
		}
		if (total == 1) {
			printf("\n");
			continue;
		}
		if (total == 2) {
			printf("2\n");
			continue;
		}
		
		mn = total;
		if (leaf[root] == 1) {
			leaf[root] = 0;
			for (int ii = 1; ii <= mn; ii ++) {
				if (father[ii] == root && leaf[ii] != -1) {
					leaf[ii] ++;
					father[root] = ii;
					father[ii] = 0;
					root = ii;
					break;
				}
			}
		}

		int first = 1;

		while (1) {
			for (i = 1; i <= mn; i ++) {
				if (leaf[i] == 0) {
					leaf[i] = -1;
					if (first) first = 0;
					else printf(" ");
					printf("%d", father[i]);
					leaf[father[i]] --;
					total --;
					if (leaf[root] == 1) {
						leaf[root] = 0;
						for (int ii = 1; ii <= mn; ii ++) {
							if (father[ii] == root && leaf[ii] != -1) {
								leaf[ii] ++;
								father[root] = ii;
								father[ii] = 0;
								root = ii;
								break;
							}
						}
					}
					break;
				}
			}
			if (total == 2) break;
		}
		printf(" %d\n", mn);
	}
	return 0;
}
