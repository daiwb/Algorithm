// ac

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

void run() {
    int u, m;
    scanf("%d %d", &u, &m);
    vector<vector<string> > mm(u, vector<string>());
    int dd = m + 1;
    while (m--) {
        char name[100];
        int bid;
        scanf("%s %d", name, &bid);
        mm[bid - 1].push_back(string(name));
    }
    int idx;
    string ret;
    for (int i = 0; i < u; ++i) {
        if (mm[i].empty()) continue;
        if (mm[i].size() < dd) {
            dd = mm[i].size();
            idx = i + 1, ret = mm[i][0];
        }
    }
    printf("The winner is %s.\n", ret.c_str());
    printf("The price is %d.\n", idx);
}

int main() {
    int kase;
    scanf("%d", &kase);
    for (int kk = 0; kk < kase; ++kk) {
        if (kk) printf("\n");
        printf("Case %d:\n", kk + 1);
        run();
    }
    return 0;
}
