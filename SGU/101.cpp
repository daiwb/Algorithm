//tle

#include <iostream>
using namespace std;

#define MAXN 105

class domino {
public:
	int left, right;
}mm[MAXN];

int n;
int degree[7];
int visited[MAXN];
int output[MAXN], rot[MAXN];
int flag;
int aa[7], bb[7];

void dfs(int now, int num) {
	if (flag) return;
	if (num == n) {
		for (int i = 0; i < num; ++i) {
			printf("%d ", output[i] + 1);
			if (rot[i]) printf("-\n");
			else printf("+\n");
		}
		flag = 1;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (visited[i]) continue;
		if (mm[i].left == now) {
			visited[i] = 1;
			output[num] = i, rot[num] = 0;
			dfs(mm[i].right, num + 1);
			visited[i] = 0;
		}
		if (mm[i].right == now) {
			visited[i] = 1;
			output[num] = i, rot[num] = 1;
			dfs(mm[i].left, num + 1);
			visited[i] = 0;
		}
	}
}

void fill(int now) {
	if (bb[now]) return;
	bb[now] = 1;
	for (int i = n - 1; i >= 0; --i) {
		if (mm[i].left == now) {
			fill(mm[i].right);
		}
		if (mm[i].right == now) {
			fill(mm[i].left);
		}
	}
}

void run() {
	memset(degree, 0, sizeof(degree));
	memset(visited, 0, sizeof(visited));
	memset(aa, 0, sizeof(aa));
	memset(bb, 0, sizeof(bb));
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &mm[i].left, &mm[i].right);
		degree[mm[i].left]++, degree[mm[i].right]++;
		aa[mm[i].left] = aa[mm[i].right] = 1;
	}
	int odd = 0, start;
	for (int i = 0; i < 7; ++i) {
		if (degree[i] % 2 == 1) {
			++odd;
			start = i;
		}
	}
	if (! (odd == 0 || odd == 2)) {
		printf("No solution\n");
		return;
	}

	for (int i = 0; i < 7; ++i) {
		if (aa[i]) {
			fill(i);
			break;
		}
	}

	for (int i = 0; i < 7; ++i) {
		if (aa[i] == 1 && bb[i] == 0) {
			printf("No solution\n");
			return;
		}
	}
	
	if (odd == 0) {
		start = mm[0].left;
	}
	flag = 0;
	dfs(start, 0);
	if (flag == 0) {
		printf("No solution\n");
	}
}

int main() {
	while (scanf("%d", &n) != EOF) {
		run();
	}
	return 0;
}

