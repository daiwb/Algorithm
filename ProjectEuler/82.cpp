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


void run() {
    REP(i,MAXN) {
        string str;
        cin >> str;
        num.push_back(splitInt(str, ","));
    }

    memset(mm, 127, sizeof(mm));
    priority_queue<state> pq;
    REP(i, MAXN) {
        mm[i][MAXN - 1] = num[i][MAXN - 1];
        pq.push(state(i, MAXN - 1, num[i][MAXN - 1]));
    }
    while (!pq.empty()) {
        state cur = pq.top(); pq.pop();
        int dist = cur.dist, row = cur.row, col = cur.col;
        if (dist > mm[row][col]) continue;
        else mm[row][col] = dist;
        if (col > 0) pq.push(state(row, col - 1, num[row][col - 1] + dist));
        if (row > 0) pq.push(state(row - 1, col, num[row - 1][col] + dist));
        if (row < MAXN - 1) pq.push(state(row + 1, col, num[row + 1][col] + dist));
    }
    int ret = mm[0][0];
    FOR(i,1,MAXN-1) ret = min(ret, mm[i][0]);
    cout << ret << endl;
}

int main() {
    run();
    return 0;
}
