//ac
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

#define for if(0); else for

class window {
public:
    int upper;
    int left;
    int lower;
    int right;
    int num;
    int flag;
    int title;
    int number;
    int lastx;
    int lasty;
}mm[5];

//quick sort
int cmp(const void *t1, const void *t2) {
	window *a, *b; 
	a = (window*)t1;
	b = (window*)t2;
    if ((*a).num > (*b).num) return -1;
    return 1;
}

int n, h, wmax, hmax, m;
int cc;
int out[50];
int x, y;

int Run() {
    cc = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &mm[i].left, &mm[i].upper, &mm[i].right, &mm[i].lower);
        mm[i].flag = 0;
        mm[i].title = 0;
        mm[i].num = i;
        mm[i].number = i;
    }
    cc = n;
    scanf("%d", &m);
    for (int ii = 0; ii < m; ++ii) {
        scanf("%d %d", &x, &y);
        qsort(mm, n, sizeof(mm[0]), cmp);
        int sss = 0;
        for (int i = 0; i < n; ++i) {
            if (mm[i].flag) {
                out[ii] = mm[i].number;
                if (y >= hmax - h && y <= hmax) {
                    if (mm[i].lastx == x && mm[i].lasty == y) {
                        mm[i].flag = 0;
                    }
                }
                sss = 1;
                mm[i].num = cc++;
                mm[i].lastx = x;
                mm[i].lasty = y;
                break;
            }
        }
        if (sss == 1) continue;
        int ss = 1;
        for (int i = 0; i < n; ++i) {
            if (x >= mm[i].left && x <= mm[i].right && y >= mm[i].lower && y <= mm[i].upper) {
                out[ii] = mm[i].number;
                if (y >= mm[i].upper - h && y <= mm[i].upper) {
                    if (mm[i].lastx == x && mm[i].lasty == y) {
                        mm[i].flag = 1;
                    }
                }
                ss = 0;
                mm[i].num = cc++;
                mm[i].lastx = x;
                mm[i].lasty = y;
                break;
            }
        }
        if (ss) out[ii] = -1;
    }
    for (int i = 0; i < m; ++i) {
        if (i) printf(" ");
        printf("%d", out[i]);
    }
    printf("\n");
    return 0;
}

int main() {
    while (scanf("%d %d %d %d", &n, &h, &wmax, &hmax) != EOF) {
        Run();
    }
    return 0;
}
