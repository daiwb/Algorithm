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

class shirt {
public:
    double value;
    int num;
    bool operator < (const shirt &c) {
        if (value > c.value) return true;
        if (value < c.value) return false;
        if (num < c.num) return true;
        return false;
	}
    shirt() {
    }
};

//quick sort
int cmp(const void *t1, const void *t2) {
	shirt *a, *b; 
	a = (shirt*)t1;
	b = (shirt*)t2;
    if ((*a).value > (*b).value) return -1;
    if ((*a).value < (*b).value) return 1;
    if ((*a).num < (*b).num) return -1;
    return 1;
}

int n, m, k;
double sa[1000][1000];
shirt mm[1000];

int Run() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%lf", &sa[i][j]);
        }
    }
    for (int i = 0; i < m; ++i) {
        double tmp = 0;
        for (int j = 0; j < n; ++j) {
            tmp += sa[j][i];
        }
        mm[i].value = tmp;
        mm[i].num = i + 1;
    }
    qsort(mm, m, sizeof(mm[0]), cmp);
    vector<int> out;
    for (int i = 0; i < k; ++i) {
        out.push_back(mm[i].num);
    }
    sort(out.begin(), out.end());
    for (int i = 0; i < k; ++i) {
        if (i) printf(" ");
        printf("%d", out[k - 1 - i]);
    }
    printf("\n");
    return 0;
}

int main() {
    while (scanf("%d %d %d", &n, &m, &k) != EOF) {
        Run();
    }
    return 0;
}
