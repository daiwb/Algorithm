#include <iostream>
#include <string>
using namespace std;

int n, mm, e, flag;
int mat[105][105];
int visited[105];

void search(int x) {
    if (!flag) return;
    if (visited[x]) {
        flag = 0;
        return;
    }
    visited[x] = 1;
    for (int i = 1; i <= mm; ++i) {
        if (mat[x][i] && x != i) {
            search(i);
            if (!flag) return;
        }
    }
    visited[x] = 0;
}

void Run() {
    memset(mat, 0, sizeof(mat));
    memset(visited, 0, sizeof(visited));
    mm = 0;
    while (n--) {
        int ai, bi;
        cin >> ai >> bi;
        if (ai > mm) mm = ai;
        if (bi > mm) mm = bi;
        mat[ai][bi] = 1;
    }
    cin >> e;
    flag = 1;
    search(e);
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    while (cin >> n && n > 0) {
        Run();
    }
    return 0;
}
