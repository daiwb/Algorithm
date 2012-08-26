/*
zju 1108 FatMouse's Speed
00:00.01 416k
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

#define MAXN 10001

class mouse{
public:
	int weight;
	int speed;
	int index;
}mice[1000];

int cmp(const void *t1, const void *t2) {
	mouse *a, *b; 
	a = (mouse *)t1;
	b = (mouse *)t2;
	if ((*a).weight < (*b).weight) return -1;
	if ((*a).weight == (*b).weight) {
		if ((*a).speed > (*b).speed) return -1;
		return 1;
	}
	return 1;
} 

int mm[1000];

int main () {
	int n = 0, w, s;
	while (scanf("%d %d", &w, &s) != EOF) {
		//if (w == 0 && s == 0) break;
		mice[n].weight = w;
		mice[n].speed = s;
		mice[n].index = n + 1;
		n ++;
	}
	qsort(mice, n, sizeof(mouse), cmp);

	for (int i = 0; i < n; i ++) mm[i] = 1;
	for (int i = n - 1; i >= 1; i --) {
		for (int j = i - 1; j >= 0; j --) {
			if (mice[j].weight < mice[i].weight && mice[j].speed > mice[i].speed) {
				if (mm[i] + 1 > mm[j]) mm[j] = mm[i] + 1;
			}
		}
	}

	int res = 0;
	int ii = 0;
	for (int i = 0; i < n; i ++) {
		if (mm[i] > res) {
			res = mm[i];
			ii = i;
		}
	}
	printf("%d\n", res);
	printf("%d\n", mice[ii].index);
	for (int i = ii; i < n; i ++) {
		if (mice[i].weight > mice[ii].weight && mice[i].speed < mice[ii].speed) {
			if (mm[i] == res - 1) {
				printf("%d\n", mice[i].index);
				res --;
				ii = i;
			}
		}
	}
	return 0;
}
