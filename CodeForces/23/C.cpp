#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long LL;

class box {
public:
    int a, o, idx;
    bool operator<(const box &r) const {
        return a < r.a;
    }
};

void run() {
    int n;
    cin >> n;
    int m = (n << 1) - 1;

    vector<box> boxes(m);
    
    LL totalo = 0;
    REP(i,m) {
        cin >> boxes[i].a >> boxes[i].o;
        boxes[i].idx = i + 1;
        totalo += boxes[i].o;
    }
    sort(boxes.begin(), boxes.end());
    
    LL tmp = 0;
    REP(i,n) {
        tmp += boxes[i << 1].o;
    }

    cout << "YES" << endl;
    if ((tmp << 1) >= totalo) {
        REP(i,n) {
            if (i) cout << " ";
            cout << boxes[i << 1].idx;
        }
        cout << endl;
    } else {
        REP(i,n-1) {
            if (i) cout << " ";
            cout << boxes[(i << 1) + 1].idx;
        }
        cout << " " << boxes[m - 1].idx << endl;
    }
}

int main() {
    int kase;
    for (cin >> kase; kase; --kase) {
        run();
    }
    return 0;
}
