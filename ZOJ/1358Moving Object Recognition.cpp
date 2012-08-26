// ac

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <cstdio>
using namespace std;

int m, k;
int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

char ch[300][300];

pair<double, double> get_center() {
        int row = k, col = m;
        vector<vector<int> > visited(row, vector<int>(col, 0));
        int res = 0;
        pair<double, double> ret, cen;
        for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                        if (visited[i][j]) continue;
                        if (ch[i][j] == '.') continue;
                        int num = 0;
                        ret.first = ret.second = 0.0;
                        deque<pair<int, int> > que;
                        que.push_back(make_pair(i, j));
                        visited[i][j] = 1;
                        while (!que.empty()) {
                                pair<int, int> now = que.front();
                                que.pop_front();
                                ++num;
                                ret.first += now.first, ret.second += now.second;
                                for (int dd = 0; dd < 8; ++dd) {
                                        int tx = now.first + dir[dd][0], ty = now.second + dir[dd][1];
                                        if (tx < 0 || tx >= row || ty < 0 || ty >= col) continue;
                                        if (ch[tx][ty] == '.') continue;
                                        if (visited[tx][ty]) continue;
                                        visited[tx][ty] = 1;
                                        que.push_back(make_pair(tx, ty));
                                }
                        }
                        if (num > res) {
                                res = num;
                                cen.first = ret.first / num, cen.second = ret.second / num;
                        }
                }
        }
        return cen;
}

void run() {
        vector<pair<double, double> > pic;
        while (1) {
                for (int i = 0; i < k; ++i) {
                        scanf("%s", ch[i]);
                }
                pair<double, double> c = get_center();
                pic.push_back(c);
                scanf("%s", ch[0]);
                if (ch[0][0] == '=') break;
        }
        int t = pic.size() / 2;
        pair<double, double> ret(0.0, 0.0);
        for (int i = 0; i < t; ++i) {
                ret.first += pic[i + t].first - pic[i].first;
                ret.second += pic[i + t].second - pic[i].second;
        }
        printf("%.2lf %.2lf\n", ret.second / t / t, ret.first / t / t);
}

int main() {
        while (scanf("%d %d", &m, &k) && m + k) {
                run();
        }
        return 0;
}
