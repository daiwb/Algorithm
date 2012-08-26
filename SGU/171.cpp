//ac

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define for if(0); else for

class zone {
	public:
		int num;
		int q;
		int idx;
		bool operator<(const zone& rhs) const {
			return q < rhs.q;
		}
}zo[100];

class student {
	public:
		int q;
		int w;
		int idx;
		bool operator<(const student& rhs) const {
			return w > rhs.w;
		}
}stu[16000];

int pos[16000];

int k, n;

int main() {
	scanf("%d", &k);
	n = 0;
	for (int i = 0; i < k; ++i) {
		scanf("%d", &zo[i].num);
		zo[i].idx = i;
		n += zo[i].num;
	}
	for (int i = 0; i < k; ++i) {
		scanf("%d", &zo[i].q);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &stu[i].q);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &stu[i].w);
		stu[i].idx = i;
	}
	sort(zo, zo + k);
	sort(stu, stu + n);
	for (int i = 0; i < n; ++i) {
		int flag = 1;
		for (int j = k - 1; j >= 0; --j) {
			if (zo[j].num > 0 && zo[j].q < stu[i].q) {
				pos[stu[i].idx] = zo[j].idx;
				zo[j].num -= 1;
				flag = 0;
				break;
			}
		}
		if (flag) {
			for (int j = k - 1; j >= 0; --j) {
				if (zo[j].num > 0) {
					pos[stu[i].idx] = zo[j].idx;
					zo[j].num -= 1;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", pos[i] + 1);
	}
	printf("\n");
	return 0;
}
