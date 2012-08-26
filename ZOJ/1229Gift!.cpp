#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, m;

int bfs() {
    vector<int> queue(1000000);
    queue[0] = 1;
    int head, tail, nhead, ntail, k = 1, step;
    head = tail = 0;
    while (++k) {
        step = 2 * k - 1;
        vector<int> visited(n + 1, 0);
        nhead = tail + 1, ntail = tail;
        for (int i = head; i <= tail; ++i) {
            int now = queue[i];
            if (now + step <= n && visited[now + step] == 0) {
                queue[++ntail] = now + step;
                visited[now + step] = 1;
            }
            if (now - step >= 1 && visited[now + step] == 0) {
                queue[++ntail] = now - step;
                visited[now - step] = 1;
            }
        }
        if (visited[m]) return 1;
        if (ntail < nhead) break;
        for (int i = nhead; i <= ntail; ++i) queue[i - nhead] = queue[i];
        head = 0, tail = ntail - nhead;
    }
    return 0;
}

int found = 0;

void dfs(int now, int ii) {
    if (found) return;
    if (now == m) {
        found = 1;
        return;
    }
    int step = ii * 2 - 1;
    if (now + step <= n) dfs(now + step, ii + 1);
    if (now - step >= 1) dfs(now - step, ii + 1);
}

void Run() {
    if (n >= 50) {
        printf("Let me try!\n");
        return;
    }
    found = 0;
    dfs(1, 2);
    if (found) printf("Let me try!\n");
    else printf("Don't make fun of me!\n");
    //if (bfs()) printf("Let me try!\n");
    //else printf("Don't make fun of me!\n");
}

int main() {
    while (scanf("%d %d", &n, &m) && n + m) {
        Run();
    }
    return 0;
}
