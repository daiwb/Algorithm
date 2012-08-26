/**
 * ZOJ 2203 Anti-prime Sequences
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

//用质数表判定质数,先调用initprime
int plist[10000],pcount=0;
int a[9956];

int prime(int n){
	int i;
	if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
		return 0;
	for (i=0;plist[i]*plist[i]<=n;i++)
		if (!(n%plist[i]))
			return 0;
		return n>1;
}

void initprime(){
	memset(a, 0, sizeof(a));
	a[2] = 1;
	int i;
	for (plist[pcount++]=2,i=3;i<9956;i++)
		if (prime(i)) {
			a[i] = 1;
			plist[pcount++]=i;
		}
}

int visited[1001], sum[1001];
int n, m, d, flag, all;
int out[1001];

int search(int total) {
	if (flag) return 0;
	if (total == all) {
		flag = 1;
		printf("%d", out[1]);
		for (int i = 2; i <= all; ++i) printf(",%d", out[i]);
		printf("\n");
		return 0;
	}
	for (int i = n; i <= m; ++i) {
		if (visited[i] == 0) {
			int sign = 1;
			out[total + 1] = i;
			sum[total + 1] = sum[total] + i;
			int jj = total + 1 - d;
			if (jj < 0) jj = 0;
			for (int ii = jj; ii <= total - 1; ++ii) {
				if (a[sum[total + 1] - sum[ii]] == 1) {
					sign = 0;
					break;
				}
			}
			if (sign) {
				visited[i] = 1;
				search(total + 1);
				visited[i] = 0;
			}
		}
	}
	return 0;
}

int Run() {
	sum[0] = 0;
	all = m - n + 1;
	flag = 0;
	memset(visited, 0, sizeof(visited));
	search(0);
	if (flag == 0) printf("No anti-prime sequence exists.\n");
	return 0;
}

int main() {
	initprime();
	while (scanf("%d %d %d", &n, &m, &d)) {
		if (n == 0 && m == 0 && d == 0) break;
		Run();
	}
	return 0;
}
