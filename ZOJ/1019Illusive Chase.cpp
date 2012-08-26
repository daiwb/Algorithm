#include <iostream>
#include <vector>
using namespace std;

#define for if(0); else for

class move {
public:
    int a;
    int b;
    int dir;
    move(int aa, int bb, int dd) {
        a = aa, b = bb, dir = dd;
    }
};

class point {
public:
    int x;
    int y;
    point() {
    }
    point(int xx, int yy) {
        x = xx, y = yy;
    }
    point &operator = (const point &cc) {
        x = cc.x;
        y = cc.y;
        return *this;
    }
};

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char cc[5] = "DLUR";

int m, n;

void Run() {
    cin >> m >> n;
    int mat[100][100];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }
    vector<move> mm;
    int a, b, d;
    char ch;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        cin >> ch;
        if (a > b) a ^= b ^= a ^= b;
        for (int i = 0; i < 4; ++i) {
            if (cc[i] == ch) {
                d = i;
                break;
            }
        }
        mm.push_back(move(a, b, d));
    }
    point queue[20000];
    int head = 0, tail = -1, nhead, ntail;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 0) {
                queue[++tail] = point(i, j);
            }
        }
    }
    for (int ii = mm.size() - 1; ii >= 0; --ii) {
        vector<vector<int> > visited(m, vector<int>(n, 0));
        nhead = tail + 1, ntail = tail;
        for (int i = head; i <= tail; ++i) {
            int nx = queue[i].x, ny = queue[i].y;
            a = mm[ii].a, b = mm[ii].b, d = mm[ii].dir;
            for (int j = 1; j <= b; ++j) {
                int tx = nx + j * dir[d][0];
                int ty = ny + j * dir[d][1];
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || mat[tx][ty] == 1) break;
                if (j < a) continue;
                if (visited[tx][ty]) continue;
                visited[tx][ty] = 1;
                queue[++ntail] = point(tx, ty);
            }
        }
        if (ntail < nhead) {
            cout << 0 << endl;
            return;
        }
        for (int i = nhead; i <= ntail; ++i) {
            queue[i - nhead] = queue[i];
        }
        head = 0, tail = ntail - nhead;
    }
    cout << tail - head + 1 << endl;
}

int main() {
    int kase;
    for (cin >> kase; kase; --kase) {
        Run();
    }
    return 0;
}
