#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

vector<int> doit() {
    vector<int> res;
    int r;
    cin >> r;
    REP(i,4) {
        REP(j,4) {
            int num;
            cin >> num;
            if (i + 1 == r) res.push_back(num);
        }
    }
    return res;
}

void run() {
    vector<int> m1 = doit();
    vector<int> m2 = doit();

    sort(m1.begin(), m1.end());
    sort(m2.begin(), m2.end());
    
    vector<int> mm(8);
    vector<int>::iterator it = set_intersection(m1.begin(), m1.end(), m2.begin(), m2.end(), mm.begin());
    mm.resize(it - mm.begin());

    if (mm.size() == 1) cout << mm[0] << endl;
    else if (mm.size() == 0) cout << "Volunteer cheated!" << endl;
    else cout << "Bad magician!" << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
