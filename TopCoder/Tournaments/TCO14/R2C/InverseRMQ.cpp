// BEGIN CUT HERE

// END CUT HERE
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
// END CUT HERE

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define SZ(x) x.size()
#define MP make_pair
#define MPI make_pair<int, int>
#define PB push_back
typedef long long LL;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef pair<int, int> PI;
typedef vector<pair<int, int> > VPI;

// BEGIN CUT HERE
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
// END CUT HERE

// BEGIN CUT HERE
int s2i(string s) {
    stringstream ss;
    ss << s;
    int res;
    ss >> res;
    return res;
}

string i2s(int n) {
    stringstream ss;
    ss << n;
    string res;
    ss >> res;
    return res;
}
// END CUT HERE

class seg {
public:
    int val;
    PI uni, ins;
    bool operator<(const seg& rhs) const {
        return val < rhs.val;
    }
};

vector<seg> mm;

int doit(PI p, int cnt) {
    VPI t;
    t.PB(p);
    REP(j,cnt) {
        PI u = mm[j].uni;
        VPI q;
        REP(k,SZ(t)) {
            PI now = t[k];
            if (u.second < now.first) q.PB(now);
            else if (u.first > now.second) q.PB(now);
            else {
                if (u.first > now.first) q.PB(MP(now.first, u.first - 1));
                if (u.second < now.second) q.PB(MP(u.second + 1, now.second));
            }
        }
        t = q;
    }

    int sum = 0;
    REP(ii,SZ(t)) {
        sum += t[ii].second - t[ii].first + 1;
    }

    return sum;
}

class InverseRMQ {
public:
    string possible(int n, vector <int> A, vector <int> B, vector <int> ans) {
        n = n;
        mm.clear();
        REP(i,SZ(A)) {
            seg s;
            s.val = ans[i];
            s.uni = MP(A[i], B[i]);
            s.ins = MP(A[i], B[i]);
            mm.PB(s);
        }
        SORT(mm);
        int idx = 0;
        REP(i,SZ(A)) {
            int next = i + 1;
            while (next < SZ(A) && mm[next].val == mm[i].val) {
                int a = mm[next].uni.first, b = mm[next].uni.second;
                mm[i].uni.first = min(mm[i].uni.first, a);
                mm[i].uni.second = max(mm[i].uni.second, b);
                mm[i].ins.first = max(mm[i].ins.first, a);
                mm[i].ins.second = min(mm[i].ins.second, b);
                ++next;
            }
            if (mm[i].ins.first > mm[i].ins.second) return "Impossible";
            mm[idx++] = mm[i];
            i = next - 1;
        }
        mm.erase(mm.begin() + idx, mm.end());

        int used = 0;
        REP(i,SZ(mm)) {
            int sum = doit(mm[i].ins, i);
            if (sum == 0) return "Impossible";

            used += doit(mm[i].uni, i);
            if (used > mm[i].val) return "Impossible";
        }
        
        return "Possible";
    }
};
// BEGIN CUT HERE
int main() {
    {
        int AARRAY[] = {2,5};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {6,8};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int ansARRAY[] = {3,3};
        vector <int> ans( ansARRAY, ansARRAY+ARRSIZE(ansARRAY) );
        InverseRMQ theObject;
        eq(0, theObject.possible(9, A, B, ans),"Impossible");
    }
    {
        int AARRAY[] = {1,2,4};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {2,4,5};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int ansARRAY[] = {3,4,5};
        vector <int> ans( ansARRAY, ansARRAY+ARRSIZE(ansARRAY) );
        InverseRMQ theObject;
        eq(0, theObject.possible(5, A, B, ans),"Possible");
    }
    {
        int AARRAY[] = {1,2,3};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1,2,3};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int ansARRAY[] = {3,3,3};
        vector <int> ans( ansARRAY, ansARRAY+ARRSIZE(ansARRAY) );
        InverseRMQ theObject;
        eq(1, theObject.possible(3, A, B, ans),"Impossible");
    }
    {
        int AARRAY[] = {1,101,201,301,401,501};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {100,200,300,400,500,600};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int ansARRAY[] = {100,200,300,400,500,600};
        vector <int> ans( ansARRAY, ansARRAY+ARRSIZE(ansARRAY) );
        InverseRMQ theObject;
        eq(2, theObject.possible(600, A, B, ans),"Possible");
    }
    {
        int AARRAY[] = {1234,1234};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {5678,5678};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int ansARRAY[] = {10000,20000};
        vector <int> ans( ansARRAY, ansARRAY+ARRSIZE(ansARRAY) );
        InverseRMQ theObject;
        eq(3, theObject.possible(1000000000, A, B, ans),"Impossible");
    }
    {
        int AARRAY[] = {1,2,3,4,5,6,7,8};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1,2,3,4,5,6,7,8};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int ansARRAY[] = {4,8,2,5,6,3,7,1};
        vector <int> ans( ansARRAY, ansARRAY+ARRSIZE(ansARRAY) );
        InverseRMQ theObject;
        eq(4, theObject.possible(8, A, B, ans),"Possible");
    }
    {
        int AARRAY[] = {1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1000000000};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int ansARRAY[] = {19911120};
        vector <int> ans( ansARRAY, ansARRAY+ARRSIZE(ansARRAY) );
        InverseRMQ theObject;
        eq(5, theObject.possible(1000000000, A, B, ans),"Impossible");
    }
    return 0;
}
// END CUT HERE
