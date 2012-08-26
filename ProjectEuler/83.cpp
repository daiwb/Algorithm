#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define MAXN 80

vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}

vector<vector<int> > num;
int mm[MAXN + 5][MAXN + 5];

class state {
public:
    int row, col, dist;
    state(int r, int c, int d) : row(r), col(c), dist(d) {};
    bool operator<(const state &rhs) const {
        return dist > rhs.dist;
    }
};

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};


void run() {
    REP(i,MAXN) {
        string str;
        cin >> str;
        num.push_back(splitInt(str, ","));
    }

    memset(mm, 127, sizeof(mm));
    priority_queue<state> pq;
    mm[MAXN - 1][MAXN - 1] = num[MAXN - 1][MAXN - 1];
    pq.push(state(MAXN - 1, MAXN - 1, num[MAXN - 1][MAXN - 1]));
    while (!pq.empty()) {
        state cur = pq.top(); pq.pop();
        int dist = cur.dist, row = cur.row, col = cur.col;
        if (dist > mm[row][col]) continue;
        else mm[row][col] = dist;
        REP(i,4) {
            int tr = row + dir[i][0], tc = col + dir[i][1];
            if (tr < 0 || tr >= MAXN || tc < 0 || tc >= MAXN) continue;
            pq.push(state(tr, tc, num[tr][tc] + dist));
        }
    }
    int ret = mm[0][0];
    cout << ret << endl;
}

int main() {
    run();
    return 0;
}
