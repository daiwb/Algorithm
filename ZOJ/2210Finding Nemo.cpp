//ac

#include <iostream>
#include <cstring>
#include <string>
#include <deque>
#include <cstdio>
using namespace std;

#define MAXN 210
#define inf 1000000000

class state {
public:
        int x, y;
        int door;
        state() {}
        state(int mX, int mY, int mDoor) : x(mX), y(mY), door(mDoor) {}
};

int door[MAXN][MAXN];

int n, m;
int mat[MAXN][MAXN][4];
int destx, desty;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
deque<state> mm;

void run() {
        memset(mat, 0, sizeof(mat));
        for (int i = 0; i < MAXN; ++i) {
                for (int j = 0; j < MAXN; ++j) {
                        door[i][j] = inf;
                }
        }

        // input
        for (int i = 0; i < n; ++i) {
                int x, y, d, t;
                scanf("%d %d %d %d", &x, &y, &d, &t);
                if (d == 0) {
                        for (int j = 0; j < t; ++j) {
                                mat[x + j][y - 1][0] = 1;
                                mat[x + j][y][2] = 1;
                        }
                } else {
                        for (int j = 0; j < t; ++j) {
                                mat[x - 1][y + j][1] = 1;
                                mat[x][y + j][3] = 1;
                        }
                }
        }
        for (int i = 0; i < m; ++i) {
                int x, y, d;
                scanf("%d %d %d", &x, &y, &d);
                if (x <= 0 || y <= 0) continue;
                if (d == 0) {
                        mat[x][y - 1][0] = 2;
                        mat[x][y][2] = 2;
                } else {
                        mat[x - 1][y][1] = 2;
                        mat[x][y][3] = 2;
                }
        }
        double f1, f2;
        scanf("%lf %lf", &f1, &f2);
        destx = (int)f1, desty = (int)f2;
        if (destx >= MAXN || desty >= MAXN) {
                printf("0\n");
                return;
        }

        // proc
        mm.clear();
        mm.push_back(state(0, 0, 0));
        door[0][0] = 0;
        while (! mm.empty()) {
                state now = mm.front();
                mm.pop_front();
                int cx = now.x, cy = now.y;
                if (now.door > door[cx][cy]) continue;
                for (int i = 0; i < 4; ++i) {
                        int tx = cx + dir[i][0], ty = cy + dir[i][1];
                        if (tx < 0 || tx >= MAXN || ty < 0 || ty >= MAXN) continue;
                        if (mat[cx][cy][i] == 1) continue;
                        state tmp(tx, ty, now.door);
                        if (mat[cx][cy][i] == 2) tmp.door += 1;
                        if (tmp.door < door[tx][ty]) {
                                door[tx][ty] = tmp.door;
                                mm.push_back(tmp);
                        }
                }
        }

        // output
        if (door[destx][desty] == inf) {
                printf("-1\n");
        } else {
                printf("%d\n", door[destx][desty]);
        }
}

int main() {
        while (scanf("%d %d", &n, &m) != EOF) {
                if (n == -1 && m == -1) break;
                run();
        }
        return 0;
}
