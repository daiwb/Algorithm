/**
 * P1013: Robbery
 *
 * ZJU Summer Camp 2003
 *
 * Judge Solution created by WishingBone
 *
 * Algo Desc: BFS
 */
#ifdef WIN32
#   pragma warning(disable:4786)
#   define for if (0); else for
#endif

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// state info
class state {
public:
    int x, y, time;
    state() {
    }
    state(int x, int y, int time) : x(x), y(y), time(time) {
    }
};

// state tag
enum tag {
    unreachable,
    reachable,
    reachable1,
    reachable2
};

bool run(int now) {
    int width, height, time;
    cin >> width >> height >> time;
    if (width == 0 && height == 0 && time == 0) {
        return false;
    }
    int n;
    cin >> n;
    vector<vector<vector<tag> > > visit(time + 1, vector<vector<tag> >(width, vector<tag>(height, reachable)));
    // clear all impossible positions
    for (int i = 0; i < n; ++i) {
        int left, top, right, bottom, t;
        cin >> t >> left >> top >> right >> bottom;
        for (int j = left - 1; j < right; ++j) {
            for (int k = top - 1; k < bottom; ++k) {
                visit[t][j][k] = unreachable;
            }
        }
    }
    int dir[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    deque<state> que;
    // bfs pass 1
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            if (visit[time][i][j] == reachable) {
                visit[time][i][j] = reachable1;
                que.push_back(state(i, j, time));
            }
        }
    }
    bool escaped = true;
    while (!que.empty()) {
        state current = que.front();
        que.pop_front();
        if (current.time == 0) {
            escaped = false;
            continue;
        }
        for (int d = 0; d < 5; ++d) {
            int x = current.x + dir[d][0];
            int y = current.y + dir[d][1];
            if (x >= 0 && x < width && y >= 0 && y < height
                && visit[current.time - 1][x][y] == reachable) {
                que.push_back(state(x, y, current.time - 1));
                visit[current.time - 1][x][y] = reachable1;
            }
        }
    }
    cout << "Robbery #" << now << ':' << endl;
    if (escaped) {
        cout << "The robber has escaped." << endl << endl;
        return true;
    }
    // bfs pass 2
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            if (visit[0][i][j] == reachable1) {
                que.push_back(state(i, j, 0));
            }
        }
    }
    vector<state> result(time + 1);
    vector<int> cnt(time + 1, 0);
    while (!que.empty()) {
        state current = que.front();
        que.pop_front();
        if (current.time == time) {
            continue;
        }
        for (int d = 0; d < 5; ++d) {
            int x = current.x + dir[d][0];
            int y = current.y + dir[d][1];
            if (x >= 0 && x < width && y >= 0 && y < height
                && visit[current.time + 1][x][y] == reachable1) {
                ++cnt[current.time + 1];
                result[current.time + 1] = state(x, y, current.time + 1);
                que.push_back(result[current.time + 1]);
                visit[current.time + 1][x][y] = reachable2;
            }
        }
    }
    // output
    bool info = false;
    for (int i = 1; i <= time; ++i) {
        if (cnt[i] == 1) {
            info = true;
            state ret = result[i];
            cout << "Time step " << ret.time << ": The robber has been at " << ret.x + 1 << ',' << ret.y + 1 << '.' << endl;
        }
    }
    if (!info) {
        cout << "Nothing known." << endl;
    }
    cout << endl;
    return true;
}

int main() {
    int now = 0;
    while (run(++now));
    return 0;
}
