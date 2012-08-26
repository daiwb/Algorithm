/**
 * P1015: Triangle War
 *
 * ZJU Summer Camp 2003
 *
 * Judge Solution created by WishingBone
 *
 * Algo Desc: Dynamic Programming
 */
#ifdef WIN32
#   pragma warning(disable:4786)
#   define for if (0); else for
#endif

#include <iostream>
#include <vector>
using namespace std;

int triangles[9][3] = {{1, 2, 3}, {2, 3, 5}, {2, 4, 5}, {3, 5, 6}, {4, 5, 8}, {4, 7, 8}, {5, 6, 9}, {5, 8, 9}, {6, 9, 10}};
// the best result for current player with mask as index
vector<pair<int, int> > ret(1 << 18);
// vertex pair to edge index mapping
vector<vector<int> > edges(11, vector<int>(11, -1));
// triangle constructs
vector<int> cst1(18, -1), cst2(18, -1);

// the number of new triangles made with mask and edge
int triangle(int mask, int edge) {
    int ret = 0;
    int submask = cst1[edge];
    if ((mask & submask) == submask) {
        ++ret;
    }
    submask = cst2[edge];
    if (submask != -1 && (mask & submask) == submask) {
        ++ret;
    }
    return ret;
}

// pre calculation
void precalc() {
    // conversion
    for (int i = 0, t = 0; i < 9; ++i) {
        int id[3];
        // mapping edges
        for (int j = 0; j < 3; ++j) {
            int a = triangles[i][j], b = triangles[i][(j + 1) % 3];
            if (edges[a][b] == -1) {
                edges[a][b] = t;
                edges[b][a] = t;
                t++;
            }
            id[j] = edges[a][b];
        }
        // initiate constructs
        for (int j = 0; j < 3; ++j) {
            if (cst1[id[j]] == -1) {
                cst1[id[j]] = (1 << id[(j + 1) % 3]) | (1 << id[(j + 2) % 3]);
            } else {
                cst2[id[j]] = (1 << id[(j + 1) % 3]) | (1 << id[(j + 2) % 3]);
            }
        }
    }
    ret[(1 << 18) - 1] = make_pair(0, 0);
    // dynamic programming on all masks
    for (int mask = (1 << 18) - 2; mask >= 0; --mask) {
        pair<int, int> now(-1, -1);
        for (int i = 0; i < 18; ++i) {
            if ((mask & (1 << i)) == 0) {
                pair<int, int> tmp = ret[mask | (1 << i)];
                int newtri = triangle(mask, i);
                if (newtri > 0) {
                    if (tmp.first + newtri > now.first) {
                        now.first = tmp.first + newtri;
                        now.second = tmp.second;
                    }
                } else {
                    if (tmp.second > now.first) {
                        now.first = tmp.second;
                        now.second = tmp.first;
                    }
                }
            }
        }
        ret[mask] = now;
    }
}

void run() {
    int n;
    cin >> n;
    int point[2] = {0, 0}, mask = 0, turn = 0;
    // make moves in turn
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        int edge = edges[a][b];
        int newtri = triangle(mask, edge);
        mask |= 1 << edge;
        if (newtri > 0) {
            point[turn] += newtri;
        } else {
            turn = 1 - turn;
        }
    }
    point[turn] += ret[mask].first;
    point[1 - turn] += ret[mask].second;
    if (point[0] > point[1]) {
        cout << "A wins." << endl;
    } else {
        cout << "B wins." << endl;
    }
}

int main() {
    precalc();
    int total;
    cin >> total;
    for (int now = 0; now < total; ++now) {
        if (now > 0) {
            cout << endl;
        }
        int total2;
        cin >> total2;
        for (int now2 = 0; now2 < total2; ++now2) {
            cout << "Game " << now2 + 1 << ": ";
            run();
        }
    }
    return 0;
}
