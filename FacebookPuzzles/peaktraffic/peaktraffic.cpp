#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iterator>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

vector<string> mm;
map<string, int> mp;
vector<pair<int, int> > lines;
vector<vector<int> > links;
int cnt = 0;
vector<string> ret;

void Bron_Kerbosch(set<int> R, set<int> P, set<int> X) {
    if (P.empty()) {
        if (X.empty() && R.size() >= 3) {
            vector<string> mt;
            for (set<int>::iterator it = R.begin(); it != R.end(); ++it) {
                mt.push_back(mm[*it]);
            }
            sort(mt.begin(), mt.end());
            string str = "";
            REP(i,mt.size()) {
                if (i > 0) str += ", ";
                str += mt[i];
            }
            ret.push_back(str);
        }
        return;
    }

    int pivot = *P.begin();
    for (set<int>::iterator it = P.begin(); it != P.end(); ++it) {
        if (links[*it].size() > links[pivot].size()) pivot = *it;
    }
    for (set<int>::iterator it = X.begin(); it != X.end(); ++it) {
        if (links[*it].size() > links[pivot].size()) pivot = *it;
    }

    set<int> PNU = set<int>(P);
    REP(i,links[pivot].size()) {
        PNU.erase(links[pivot][i]);
    }

    for (set<int>::iterator it = PNU.begin(); it != PNU.end(); ++it) {
        int v = *it;
        set<int> NR = set<int>(R), NP, NX;
        NR.insert(v);
        REP(i,links[v].size()) {
            if (P.find(links[v][i]) != P.end()) NP.insert(links[v][i]);
            if (X.find(links[v][i]) != X.end()) NX.insert(links[v][i]);
        }

        Bron_Kerbosch(NR, NP, NX);

        P.erase(v);
        X.insert(v);
    }
}

int getIdx(string str) {
    map<string, int>::iterator itr = mp.find(str);
    if (itr == mp.end()) {
        mp[str] = cnt++;
        mm.push_back(str);
    }

    return mp[str];
}

int main(int argc, const char* argv[]) {
    ifstream input(argv[1]);
    string a, f, t;

    //char ch[1000], ff[1000], tt[1000];
    //FILE *fin  = fopen (argv[1], "r");
    //while (fscanf(fin, "%s %s %s %s %s %s %s %s", ch, ch, ch, ch, ch, ch, ff, tt) != EOF) {
    while (input >> a >> a >> a >> a >> a >> a >> f >> t) {
        //string f(ff), t(tt);
        int idx1 = getIdx(f);
        int idx2 = getIdx(t);
        lines.push_back(make_pair(idx1, idx2));
    }

    //cout << cnt << endl;

    vector<vector<int> > mat(cnt, vector<int>(cnt, 0));
    REP(i,lines.size()) mat[lines[i].first][lines[i].second] = 1;
    REP(i,cnt) mat[i][i] = 0;
    REP(i,cnt) {
        FOR(j,i+1,cnt-1) {
            if (mat[i][j] + mat[j][i] != 2) mat[i][j] = mat[j][i] = 0;
        }
    }

    REP(i,cnt) {
        vector<int> t;
        REP(j,cnt) {
            if (mat[i][j] == 1) t.push_back(j);
        }
        links.push_back(t);
    }
    
    set<int> R, P, X;
    REP(i,cnt) P.insert(i);

    Bron_Kerbosch(R, P, X);

    sort(ret.begin(), ret.end());
    //cout << ret.size() << endl;
    //REP(i,ret.size()) printf("%s\n", ret[i].c_str());
    REP(i,ret.size()) cout << ret[i] << endl;
}
