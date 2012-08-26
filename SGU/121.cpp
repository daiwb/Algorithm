//ac

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define for if(0); else for

class node {
	public:
		int black;
		int white;
		int degree;
		node() : black(0), white(0), degree(0) {}
};

int n;

int main() {
	scanf("%d", &n);
	vector<node> mm(n);
	vector<vector<int> > mat(n, vector<int>(n, -1));
	vector<vector<int> > link(n);
	for (int i = 0; i < n; ++i) {
		int a;
		while (scanf("%d", &a) && a) {
			--a;
			mm[i].degree += 1;
			mat[i][a] = 0;
			link[i].push_back(a);
		}
	}
	while (1) {
		int idx = -1;
		for (int i = 0; i < n; ++i) {
			if (mm[i].degree % 2) {
				idx = i;
				break;
			}
		}
		if (idx != -1) {
			int start = 2;
			while (1) {
				int flag = 1;
				for (int i = 0; i < n; ++i) {
					if (mat[idx][i] == 0) {
						mat[idx][i] = mat[i][idx] = start;
						mm[idx].degree -= 1; mm[i].degree -= 1;
						if (start == 1) {
							mm[idx].black += 1, mm[i].black += 1;
						} else {
							mm[idx].white += 1, mm[i].white += 1;
						}
						idx = i;
						start = 3 - start;
						flag = 0;
						break;
					}
				}
				if (flag) break;
			}
			continue;
		}
		for (int i = 0; i < n; ++i) {
			if (mm[i].degree > 0 && mm[i].black + mm[i].white > 0) {
				idx = i;
				break;
			}
		}
		int start = 2;
		if (idx != -1) {
			if (mm[idx].black == 0) start = 1;
			if (mm[idx].white == 0) start = 2;
		}
		if (idx == -1) {
			for (int i = 0; i < n; ++i) {
				if (mm[i].degree > 0) {
					idx = i;
					break;
				}
			}
		}
		if (idx == -1) break;
		while (1) {
			int flag = 1;
			for (int i = 0; i < n; ++i) {
				if (mat[idx][i] == 0) {
					mat[idx][i] = mat[i][idx] = start;
					mm[idx].degree -= 1; mm[i].degree -= 1;
					if (start == 1) {
						mm[idx].black += 1, mm[i].black += 1;
					} else {
						mm[idx].white += 1, mm[i].white += 1;
					}
					idx = i;
					start = 3 - start;
					flag = 0;
					break;
				}
			}
			if (flag) break;
		}
	}
	for (int i = 0; i < n; ++i) {
		if ((mm[i].black >= 2 && mm[i].white == 0) || (mm[i].black == 0 && mm[i].white >= 2)) {
			printf("No solution\n");
			return 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		int size = link[i].size();
		for (int j = 0; j < size; ++j) {
			printf("%d ", mat[i][link[i][j]]);
		}
		printf("0\n");
	}
	return 0;
}
