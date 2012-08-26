//ac

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int mm[1000], visited[1000];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	memset(visited, 0, sizeof(visited));
	int a = k / n;
	for (int i = 0; i < n; ++i) {
		mm[i] = a;
	}
	mm[0]--, mm[n - 1]++;
	a = k % n;
	int t = 0;
	while (1) {
		if ((a * t) % n == n - 1) break;
		++t;
	}
	a = 0;
	while (1) {
		if (a == n - 1) break;
		if (visited[a]) break;
		mm[a]++;
		visited[a] = 1;
		a += t;
		while (a >= n) a -= n;
	}
	for (int i = 0; i < n; ++i) {
		if (i) printf(" ");
		printf("%d", mm[i]);
	}
	printf("\n");
	return 0;
}

