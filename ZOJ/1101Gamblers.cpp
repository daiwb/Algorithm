/*
zju 1101 Gamblers
00:02.01 448k
2004.08.09 by adai
*/

#include <iostream>
#include <cstdlib> 
#include <string> 
#include <cstdio>
using namespace std;

int cmp(const void *t1,const void *t2) 
{ 
	int *a,*b; 
	a=(int *)t1;
	b=(int *)t2; 
	if((*a)-(*b)>0) return 1;
	if((*a)-(*b)<0) return -1;
	return 0; 
}

int wager[1000];

int main() {
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i ++) {
		    scanf("%d", &wager[i]);
		}
		qsort(wager, n, sizeof(int), cmp);
		for (int i = n - 1; i >= 0; i --) {
			for (int j = 0; j < n; j ++) {
				if (j == i) continue;
				for (int t = j + 1; t < n; t ++) {
					if (t == i) continue;
					for (int s = t + 1; s < n; s ++) {
						if (s == i) continue;
						if (wager[j] + wager[t] + wager[s] == wager[i]) {
						    printf("%d\n", wager[i]);
							goto exit;
						}
					}
				}
			}
		}
		printf("no solution\n");
exit:;
	}
	return 0;
}
