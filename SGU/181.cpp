//ac

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	long long A, alpha, beta, gamma, M, k;
	scanf("%lld %lld %lld %lld %lld %lld %lld", &A, &alpha, &beta, &gamma, &M, &k);
	bool visited[1005];
	long long mm[1005];
	memset(visited, false, sizeof(visited));
	if (k == 0) {
		printf("%lld\n", A);
		return 0;
	}
	long long ret = A % M;
	visited[ret] = true;
	long long num = 0;
	mm[num++] = ret;
	for (int i = 1; i <= k; ++i) {
		ret = (alpha * ((ret * ret) % M) + beta * ret + gamma) % M;
		if (visited[ret]) {
			for (int j = 0; j < num; ++j) {
				if (mm[j] == ret) {
					int len = i - j;
					printf("%lld\n", mm[(k - j) % len + j]);
					return 0;
				}
			}
		}
		visited[ret] = true;
		mm[num++] = ret;
	}
	printf("%lld\n", ret);
	return 0;
}

