#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define INF 1000000000
typedef long long LL;

class hline {
public:
    hline(int lt, int rt, int yt, int tt) : left(lt), right(rt), y(yt), type(tt) {}
    int left, right, y, type;
    bool operator<(const hline& rhs) const {
        if (y != rhs.y) return y < rhs.y;
        return left < rhs.left;
    }
};

int W, H, P, Q, N, X, Y, a, b, c, d;

void run() {
    cin >> W >> H >> P >> Q >> N >> X >> Y >> a >> b >> c >> d;
    vector<pair<int, int> > mm;
    int xx = X, yy = Y;
    mm.push_back(make_pair(xx, yy));
    FOR(i,1,N-1) {
        int tx = (xx * a + yy * b + 1) % W;
        int ty = (xx * c + yy * d + 1) % H;
        mm.push_back(make_pair(tx, ty));
        xx = tx, yy = ty;
    }
    
    sort(mm.begin(), mm.end());
    mm.erase(unique(mm.begin(), mm.end()), mm.end());

    vector<hline> hh;
    vector<int> vv;

    REP(i,mm.size()) {
        xx = mm[i].first, yy = mm[i].second;
        int left = max(0, xx - (P - 1));
        int top = max(0, yy - (Q - 1));
        int right = xx + 1;
        int bottom = yy + 1;

        hh.push_back(hline(left, right, top, 0));
        hh.push_back(hline(left, right, bottom, 1));

        vv.push_back(left);
        vv.push_back(right);
    }

    hh.push_back(hline(0, W, H - Q + 1, 0));
    hh.push_back(hline(0, W, H, 1));
    vv.push_back(0);
    vv.push_back(W);

    hh.push_back(hline(W - P + 1, W, 0, 0));
    hh.push_back(hline(W - P + 1, W, H, 1));
    vv.push_back(W - P + 1);

    sort(hh.begin(), hh.end());
    sort(vv.begin(), vv.end());
    vv.erase(unique(vv.begin(), vv.end()), vv.end());

    int nv = vv.size(), nh = hh.size();

    int area = 0, cnt = 0, top, bot;
    FOR(i,0,nv-2) {
        int lt = vv[i], rt = vv[i + 1], d = rt - lt;
        REP(j,nh) {
            if (hh[j].left <= lt && hh[j].right >= rt) {
                bot = hh[j].y;
                if (cnt > 0) {
                    area += d * (bot - top);
                }
                if (hh[j].type == 1) --cnt;
                else ++cnt;
                top = bot;
            }
        }
    }

    int total = W * H;
    cout << total - area << endl;
}

int main() {
    int m;
    cin >> m;
    FOR(i,1,m) {
        cout << "Case #" << i << ": ";
        run();
    }
    return 0;
}
