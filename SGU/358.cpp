#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)

int main() {
    vector<int> mm;
    REP(i,3) {
        vector<int> t(3);
        REP(j,3) cin >> t[j];
        sort(t.begin(), t.end());
        mm.push_back(t[1]);
    }
    sort(mm.begin(), mm.end());
    cout << mm[1] << endl;
    return 0;
}
