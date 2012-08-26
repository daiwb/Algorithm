//ac
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#define for if(0); else for

class cir {
public:
    int head, tail;
}mm[10000];

//quick sort
int cmp(const void *t1, const void *t2) {
	cir *a, *b; 
	a = (cir*)t1;
	b = (cir*)t2;
	if ((*a).tail > (*b).tail) return 1;
	if ((*a).tail < (*b).tail) return -1;
	if ((*a).head > (*b).head) return -1;
	return 1;
}

int flag[10000];
int n;

void Run() {
    for (int i = 0; i < n; ++i) {
            scanf("%d %d", &mm[i].head, &mm[i].tail);
            flag[i] = true;
        }
        qsort(mm, n, sizeof(mm[0]), cmp);
        for (int i = 0; i < n; ++i) {
            if (flag[i] == false) {
                continue;
            }
            for (int j = i + 1; j < n; ++j) {
                if (mm[j].head < mm[i].tail) {
                    flag[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (flag[i] == false) {
                count ++;
            }
        }
        printf("%d\n", count);
}

int main() {
    while (scanf("%d", &n) != EOF) {
        Run();
    }
    return 0;
}
