#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

class player {
public:
    string name;
    int p, h, t;
    bool operator<(const player& rhs) const {
        if (p != rhs.p) return p > rhs.p;
        return h > rhs.h;
    }
}mm[30];

int N, M, P;

void doit(vector<int>& a, vector<int>& b) {
    if (b.empty()) return;
    REP(r,M) {
        REP(i,P) ++mm[a[i]].t;
        int idx1 = 0;
        FOR(j,1,P-1) {
            if (mm[a[j]].t > mm[a[idx1]].t || (mm[a[j]].t == mm[a[idx1]].t && a[j] > a[idx1])) idx1 = j;
        }

        int idx2 = 0;
        FOR(j,1,b.size()-1) {
            if (mm[b[j]].t < mm[b[idx2]].t || (mm[b[j]].t == mm[b[idx2]].t && b[j] < b[idx2])) idx2 = j;
        }

        swap(a[idx1], b[idx2]);
    }
}

void run() {
    cin >> N >> M >> P;
    REP(i,N) {
        cin >> mm[i].name >> mm[i].p >> mm[i].h;
        mm[i].t = 0;
    }
    sort(mm, mm + N);

    vector<string> ret;
    
    vector<int> a, b;
    REP(i,P) a.push_back(i * 2);
    for (int i = P * 2; i < N; i += 2) b.push_back(i);
    doit(a, b);
    REP(i,P) ret.push_back(mm[a[i]].name);

    a.clear();
    b.clear();
    REP(i,P) a.push_back(i * 2 + 1);
    for (int i = P * 2 + 1; i < N; i += 2) b.push_back(i);
    doit(a, b);
    REP(i,P) ret.push_back(mm[a[i]].name);

    sort(ret.begin(), ret.end());
    REP(i,ret.size()) {
        if (i) cout << " ";
        cout << ret[i];
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    FOR(t,1,T) {
        cout << "Case #" << t << ": ";
        run();
    }
    return 0;
}
