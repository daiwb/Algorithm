/**
 * ZOJ 2421 Recaman's Sequence
 *
 * 2005/04/26 By adai
 */

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

#define MAXN 5000000

int n;
int out[500001];
bool visited[MAXN];

int Init() {
	memset(visited, 0, sizeof(visited));
	out[0] = 0, visited[0] = 1;
	for (int i = 1; i <= 500000; ++i) {
		int tmp = out[i - 1] - i;
		if (tmp > 0 && visited[tmp] == 0) {
			out[i] = tmp, visited[tmp] = 1;
		}
		else {
			tmp += i + i;
			out[i] = tmp, visited[tmp] = 1;
		}
	}
	return 0;
}

int main() {
	Init();
	while (scanf("%d", &n) && n != -1) {
		printf("%d\n", out[n]);
	}
	return 0;
}
