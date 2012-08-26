/**
 * ZJU 1344 A Mazing Problem
 *
 * 2005/07/14 By adai
 */

#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

class point {
public:
    int x;
    int y;
    point() {
    }
    point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    point &operator=(const point &c) {
        x = c.x;
        y = c.y;
        return *this;
    }
};

int dir[5][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {0, 0}};

int m, n;
point start, end, dog;
int len, ret;
string step;

bool check(point me, point dog, vector<vector<char> >& map, int face) {
    int cx = dog.x;
    int cy = dog.y;
    while (1) {
        if (cx == me.x && cy == me.y) return false;
        cx += dir[face][0], cy += dir[face][1];
        if (cx < 0 || cx >= m || cy < 0 || cy >= n) return true;
        if (map[cx][cy] == '*') return true;
    }
    return true;
}

void bfs(deque<point>& list, vector<vector<char> >& map) {
    vector<vector<vector<bool> > > status(m, vector<vector<bool> >(n, vector<bool>(len, false)));
    point cur;
    int face = 3;
    int itr = -1;
    ret = 0;
    while (1) {
        ++ret;
        itr = (itr + 1) % len;
        if (itr == 0) {
            cur = dog, face = 3;
        }
        if (step[itr] == 'G') {
            int tx = cur.x + dir[face][0];
            int ty = cur.y + dir[face][1];
            if (tx >= 0 && tx < m && ty >= 0 && ty < n && map[tx][ty] == '.') {
                cur.x = tx, cur.y = ty;
            }
        } else if (step[itr] == 'L') {
            face = (face + 3) % 4;
        } else {
            face = (face + 1) % 4;
        }
        
        int size = list.size();
        for (int i = 0; i < size; ++i) {
            int cx = list[i].x;
            int cy = list[i].y;
            for (int d = 0; d < 5; ++d) {
                int tx = cx + dir[d][0];
                int ty = cy + dir[d][1];
                if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
                if (map[tx][ty] == '*') continue;
                if (status[tx][ty][itr]) continue;
                if (check(point(tx, ty), cur, map, face)) {
                    if (tx == end.x && ty == end.y) {
                        return;
                    }
                    status[tx][ty][itr] = true;
                    list.push_back(point(tx, ty));
                }
            }
        }
        for (int i = 0; i < size; ++i) list.pop_front();
        if (list.size() == 0) break;
    }
    ret = -1;
}

void Run() {
    cin >> start.x >> start.y;
    --start.x, --start.y;
    cin >> end.x >> end.y;
    --end.x, --end.y;
    cin >> dog.x >> dog.y;
    --dog.x, --dog.y;
    cin >> len >> step;
    vector<vector<char> > map(m, vector<char>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
        }
    }
    deque<point> list;
    list.push_back(start);
    bfs(list, map);
    if (ret == -1) {
        cout << "No way out" << endl;
    } else {
        cout << "Minimal time is: " << ret << endl;
    }
}

int main() {
    int kase = 0;
    while (cin >> m >> n && m + n) {
        if (kase) cout << endl;
        cout << "Case " << ++kase << ":" << endl;
        Run();
    }
    return 0;
}
