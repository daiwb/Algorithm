#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <iterator>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

class engineer {
public:
    int id;
    int score;
    engineer(int _id, int _score) : id(_id), score(_score) {}
    bool operator<(const engineer& rhs) const {
        if (score != rhs.score) return score > rhs.score;
        return id > rhs.id;
    }
};

int n2, n, m, p;
vector<vector<int> > dk, rank, rk1, rk2, vv;
deque<int> freeM;
vector<int> engage;

vector<string> split(const string& s, const string& delim =" ") {
    vector<string> res;
    string t;
    REP(i,s.size()) {
        if (delim.find(s[i]) != string::npos) {
            if (!t.empty()) {
                res.push_back(t);
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if (!t.empty()) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split(s, delim);
    vector<int> res;
    REP(i,tok.size()) res.push_back(atoi(tok[i].c_str()));
    return res;
}

int getScore(int i1, int i2) {
    int ret = 0;
    REP(i,dk[i1].size()) {
        int d = dk[i1][i];
        if (rank[i2][d] == rank[i1][d]) ret += rank[i2][d] * rank[i2][d];
        else if (rank[i2][d] < rank[i1][d]) ret += rank[i1][d];
    }
    return ret;
}

void Gale_Shapley() {
    vv.assign(n, vector<int>(n, 0));
    freeM.clear();
    REP(i,n) freeM.push_back(i);
    engage.assign(n2, -1);

    while (!freeM.empty()) {
        int now = freeM.front();
        int idx = -1;
        REP(i,n) {
            if (vv[now][i] == 1) continue;
            if (idx == -1 || (rk1[now][i] < rk1[now][idx])) idx = i;
        }
        vv[now][idx] = 1;
        
        int cur = engage[idx + n];
        if (cur == -1) {
            engage[now] = idx + n;
            engage[idx + n] = now;
            freeM.pop_front();
        } else {
            if (rk2[idx][now] < rk2[idx][cur]) {
                engage[now] = idx + n;
                engage[idx + n] = now;
                engage[cur] = -1;
                freeM.pop_front();
                freeM.push_back(cur);
            }
        }
    }

    REP(i,n) {
        cout << i << " " << engage[i] << endl;
    }
}

void run(const char* argv[]) {
    ifstream input(argv[1]);
    input >> n2 >> m;
    n = (n2 >> 1);
    
    string drink;
    REP(i,m+1) getline(input, drink);
    
    dk.assign(n2, vector<int>());
    rank.assign(n2, vector<int>(m, -1));
    REP(i,n2) {
        int id;
        string td;
        input >> id >> td;
        dk[id] = splitInt(td, ",");
        p = dk[id].size();
        REP(j,p) {
            rank[id][dk[id][j]] = p - j;
        }
    }

    rk1.assign(n, vector<int>(n));
    rk2.assign(n, vector<int>(n));
    REP(i,n) {
        vector<engineer> eng;
        REP(j,n) eng.push_back(engineer(j, getScore(i, j + n)));
        sort(eng.begin(), eng.end());
        REP(j,n) rk1[i][eng[j].id] = j;

        eng.clear();
        REP(j,n) eng.push_back(engineer(j, getScore(i + n, j)));
        sort(eng.begin(), eng.end());
        REP(j,n) rk2[i][eng[j].id] = j;
    }
    
    
    Gale_Shapley();
}

int main(int argc, const char* argv[]) {
    run(argv);
}
