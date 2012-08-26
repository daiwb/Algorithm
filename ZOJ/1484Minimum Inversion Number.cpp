/*
zju 1484 Minimum Inversion Number
00:00.98 520k
2004.09.11 by adai
*/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		vector <int> v;
		for (int i = 0; i < n; i ++) {
			int tt;
			scanf("%d", &tt);
			v.push_back(tt);
		}
		int res = 0;
		int mm = 0;
		for (int i = 0; i < n - 1; i ++) {
			for (int j = i + 1; j < n; j ++) {
				if (v[j] < v[i]) mm ++;
			}
		}
		res = mm;
		for (int i = 0; i < n - 1; i ++) {
			mm -= v[i];
			mm += n - 1 - v[i];
			if (mm < res) res = mm;
		}
		printf("%d\n", res);
	}
	return 0;
}