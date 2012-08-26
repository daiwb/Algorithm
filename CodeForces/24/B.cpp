#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

class driver {
public:
    string name;
    int points;
    int places[55];
};

vector<driver> mm;

bool cmp1(const driver& a, const driver& b) {
    if (a.points != b.points) return b.points < a.points;
    REP(i,50) {
        if (a.places[i] != b.places[i]) return b.places[i] < a.places[i];
    }
    
	return false; 
}

bool cmp2(const driver& a, const driver& b) {
    if (a.places[0] != b.places[0]) return b.places[0] < a.places[0];
    if (a.points != b.points) return b.points < a.points;
    FOR(i,1,49) {
        if (a.places[i] != b.places[i]) return b.places[i] < a.places[i];
    }
    
	return false; 
}

int scores[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

map<string, int> mp;
map<string, int>::iterator itr;

void run() {
    mp.clear();
    mm.clear();
    int idx = 0;
    int T;
    cin >> T;
    REP(t,T) {
        int n;
        cin >> n;
        REP(i,n) {
            string name;
            cin >> name;
            itr = mp.find(name);
            if (itr == mp.end()) {
                driver d = driver();
                d.name = name;
                d.points = 0;
                memset(d.places, 0, sizeof(d.places));
                mm.push_back(d);
                mp[name] = idx++;
            }

            int id = mp[name];
            if (i < 10) mm[id].points += scores[i];
            mm[id].places[i] += 1;
        }
    }

    sort(mm.begin(), mm.end(), cmp1);
    cout << mm[0].name << endl;
    sort(mm.begin(), mm.end(), cmp2);
    cout << mm[0].name << endl;
}

int main() {
    run();
    return 0;
}
