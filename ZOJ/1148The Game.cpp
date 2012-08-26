#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

class point {
public:
    int x;
    int y;
    point() {
    }
    point(int xx, int yy) {
        x = xx, y = yy;
    }
    point &operator = (const point& cc) {
        this->x = cc.x;
        this->y = cc.y;
        return *this;
    }
};

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int w, h, board = 0;

void bfs(vector<vector<int> >& mat, point& a, point& b) {
    vector<point> queue(10000);
    int head, tail, nhead, ntail, step = 0, tx, ty;
    head = tail = 0;
    queue[0] = a;
    while (1) {
        ++step;
        nhead = tail + 1, ntail = tail;
        for (int i = head; i <= tail; ++i) {
            for (int dd = 0; dd < 4; ++dd) {
                tx = queue[i].x, ty = queue[i].y;
                while (1) {
                    tx += dir[dd][0], ty += dir[dd][1];
                    if (tx < 0 || tx > h + 1 || ty < 0 || ty > w + 1) break;
                    if (tx == b.x && ty == b.y) {
                        cout << step << " segments." << endl;
                        return;
                    }
                    if (mat[tx][ty] == -1 || (mat[tx][ty] != 0 && mat[tx][ty] < step)) break;
                    if (mat[tx][ty] == step) continue;
                    mat[tx][ty] = step;
                    queue[++ntail] = point(tx, ty);
                }
            }
        }
        if (ntail < nhead) break;
        for (int i = nhead; i <= ntail; ++i) {
            queue[i - nhead] = queue[i];
        }
        head = 0, tail = ntail - nhead;
    }
    cout << "impossible." << endl;
}

void Run() {
    vector<vector<int> > mat(h + 2, vector<int>(w + 2, 0));
    vector<vector<int> > bak(h + 2, vector<int>(w + 2, 0));
    char in[100];
    cin.getline(in, 100, '\n');
    for (int i = 0; i < h; ++i) {
        cin.getline(in, 100, '\n');
        for (int j = 0; j < strlen(in); ++j) {
            if (in[j] == 'X') mat[i + 1][j + 1] = -1;
        }
    }
    copy(mat.begin(), mat.end(), bak.begin());
    cout << "Board #" << ++board << ":" << endl;
    point a, b;
    int pair = 0;
    while (cin >> a.y >> a.x >> b.y >> b.x) {
        if (a.x == 0 && a.y == 0 && b.x == 0 && b.y == 0) break;
        cout << "Pair " << ++pair << ": ";
        copy(bak.begin(), bak.end(), mat.begin());
        bfs(mat, a, b);
    }
    cout << endl;
}

int main() {
    while (cin >> w >> h && w + h) {
        Run();
    }
    return 0;
}
