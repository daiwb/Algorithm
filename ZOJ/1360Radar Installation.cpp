// ac

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define eps 1e-8

class seg {
public:
        double l, r;
        seg(double mL, double mR) : l(mL), r(mR) {}
        bool operator<(const seg& rhs) const {
                return r < rhs.r - eps;
        }
};

int n;
double d;

void run(int kase) {
        int flag = 0;
        vector<seg> mm;
        for (int i = 0; i < n; ++i) {
                double x, y;
                cin >> x >> y;
                if (flag) continue;
                if (y > d + eps) {
                        flag = 1;
                }
                double s = sqrt(d * d - y * y);
                mm.push_back(seg(x - s, x + s));
        }
        if (flag) {
                cout << "Case " << kase << ": " << -1 << endl;
                return;
        }
        sort(mm.begin(), mm.end());
        vector<int> visited(n, 0);
        int ret = 0;
        for (int i = 0; i < n; ++i) {
                if (visited[i]) continue;
                ++ret;
                visited[i] = 1;
                for (int j = i + 1; j < n; ++j) {
                        if (mm[j].l < mm[i].r + eps) visited[j] = 1;
                }
        }
        cout << "Case " << kase << ": " << ret << endl;
}

int main() {
        int kase = 1;
        while (cin >> n && n) {
                cin >> d;
                run(kase++);
        }
        return 0;
}