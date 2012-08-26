#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

struct node {
public:
    int value;
    int num;
    node(int v, int n) {
        value = v;
        num = n;
    }
    node &operator = (const node& cc) {
        this->value = cc.value;
        this->num = cc.num;
        return *this;
    }
};


int f[30], d[30], t[30];

void Run() {
    int h, n, flag = 1;
    while (scanf("%d", &n) && n) {
        if (flag) flag = 0;
        else printf("\n");
        scanf("%d", &h);
        h *= 12;
        for (int i = 0; i < n; ++i) scanf("%d", &f[i]);
        for (int i = 0; i < n; ++i) scanf("%d", &d[i]);
        for (int i = 0; i < n - 1; ++i) scanf("%d", &t[i]);
        int ret = -1;
        int out[30];
        for (int num = 1; num <= n; ++num) {
            int left = h;
            for (int i = 0; i < num - 1; ++i) left -= t[i];
            vector<node> fish;
            for (int i = 0; i < num; ++i) {
                fish.push_back(node(f[i], i));
            }
            int tmp[30] = {0};
            int total = 0;
            if (left <= 0) break;
            while (left--) {
                int big = -1, mark;
                for (int ii = 0; ii < fish.size(); ++ii) {
                    if (fish[ii].value > big) {
                        big = fish[ii].value;
                        mark = ii;
                    }
                }
                int aaa = fish[mark].num;
                tmp[aaa] += 1;
                fish[mark].value = (fish[mark].value < d[aaa] ? 0 : fish[mark].value - d[aaa]);
                total += big;
            }
            if (total > ret) {
                ret = total;
                memcpy(out, tmp, sizeof(tmp));
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i) printf(", ");
            printf("%d", out[i] * 5);
        }
        printf("\nNumber of fish expected: %d\n", ret);
    }
}

int main() {
    int kase;
    scanf("%d", &kase);
    for (int k = 0; k < kase; ++k) {
        if (k) printf("\n");
        Run();
    }
    return 0;
}