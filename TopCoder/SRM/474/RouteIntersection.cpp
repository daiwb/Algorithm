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
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

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

class RouteIntersection {
public:
    string isValid(int N, vector <int> mm, string moves) {
		int n = mm.size();
		vector<int> dd(n);

		REP(i,n) {
			mm[i] -= 1;
			dd[i] = (moves[i] == '+' ? 1 : -1);
		}
		
		REP(i,n) {
			map<int, int> mp;
			map<int, int>::iterator itr;
			int cnt = 0;
			FOR(j,i,n-1) {
				itr = mp.find(mm[j]);
				if (itr == mp.end()) {
					mp[mm[j]] = dd[j];
					++cnt;
				} else {
					mp[mm[j]] += dd[j];
					if (mp[mm[j]] == dd[j]) ++cnt;
					else if (mp[mm[j]] == 0) --cnt;
				}

				if (cnt == 0) return "NOT VALID";
			}
		}
        return "VALID";
    }

};
// BEGIN CUT HERE
int main() {
    {
        int coordsARRAY[] = {1};
        vector <int> coords( coordsARRAY, coordsARRAY+ARRSIZE(coordsARRAY) );
        RouteIntersection theObject;
        eq(0, theObject.isValid(1, coords, "+"),"VALID");
    }
    {
        int coordsARRAY[] = {1,2,1,2};
        vector <int> coords( coordsARRAY, coordsARRAY+ARRSIZE(coordsARRAY) );
        RouteIntersection theObject;
        eq(1, theObject.isValid(2, coords, "++--"),"NOT VALID");
    }
    {
        int coordsARRAY[] = {1,2,3,1,2};
        vector <int> coords( coordsARRAY, coordsARRAY+ARRSIZE(coordsARRAY) );
        RouteIntersection theObject;
        eq(2, theObject.isValid(3, coords, "+++--"),"VALID");
    }
    {
        int coordsARRAY[] = {132,51717,628,344447,628,51717,344447,2};
        vector <int> coords( coordsARRAY, coordsARRAY+ARRSIZE(coordsARRAY) );
        RouteIntersection theObject;
        eq(3, theObject.isValid(344447, coords, "+-++-+--"),"NOT VALID");
    }
    {
        int coordsARRAY[] = {1,1};
        vector <int> coords( coordsARRAY, coordsARRAY+ARRSIZE(coordsARRAY) );
        RouteIntersection theObject;
        eq(4, theObject.isValid(1, coords, "+-"),"NOT VALID");
    }
    {
        int coordsARRAY[] = {833196,524568,361663,108056,28026,824639,269315,440977,440977,765458,
           988451,242440,948414,130873,773990,765458,130873,28026,853121,553636,
           581069,82254,735536,833196,898562,898562,940783,988451,540613,317306,
           623194,940783,571384,988451,108056,514374,97664};
        vector <int> coords( coordsARRAY, coordsARRAY+ARRSIZE(coordsARRAY) );
        RouteIntersection theObject;
        eq(5, theObject.isValid(990630, coords, "--+---+-+++-+-+---++-++-+---+-+--+-++"),"NOT VALID");
    }
    return 0;
}
// END CUT HERE
