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
#define PB push_back
#define MP make_pair
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

class OneDimensionalBalls {
public:
    long long countValidGuesses(vector <int> fp, vector <int> sp) {
        sort(fp.begin(), fp.end());
        long long res = 0;
        REP(i,sp.size()) {
            if (fp[0] == sp[i]) continue;
            LL d = abs(fp[0] - sp[i]);
            set<LL> s(sp.begin(), sp.end());
            s.erase(sp[i]);
            vector<LL> f(fp.begin() + 1, fp.end());
            LL t = 1;
            while (!f.empty()) {
                LL curr = f[0];
                f.erase(f.begin());
                int up = 1, down = 0;
                if (s.find(curr - d) != s.end()) {
                    s.erase(curr - d);
                    ++down;
                }
                while (s.find(curr + d) != s.end()) {
                    s.erase(curr + d);
                    curr += (d << 1);
                    ++down;
                    vector<LL>::iterator itr = find(f.begin(), f.end(), curr);
                    if (itr == f.end()) break;
                    f.erase(itr);
                    ++up;
                }
                if (up + 1 == down) t *= down;
                else if (up == down + 1) {
                    t = 0;
                    break;
                }
            }
            res += t;
        }
        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        int firstPictureARRAY[] = {12,11};
        vector <int> firstPicture( firstPictureARRAY, firstPictureARRAY+ARRSIZE(firstPictureARRAY) );
        int secondPictureARRAY[] = {10,11,13};
        vector <int> secondPicture( secondPictureARRAY, secondPictureARRAY+ARRSIZE(secondPictureARRAY) );
        OneDimensionalBalls theObject;
        eq(0, theObject.countValidGuesses(firstPicture, secondPicture),3LL);
    }
    {
        int firstPictureARRAY[] = {1,2,3};
        vector <int> firstPicture( firstPictureARRAY, firstPictureARRAY+ARRSIZE(firstPictureARRAY) );
        int secondPictureARRAY[] = {1,2,3};
        vector <int> secondPicture( secondPictureARRAY, secondPictureARRAY+ARRSIZE(secondPictureARRAY) );
        OneDimensionalBalls theObject;
        eq(1, theObject.countValidGuesses(firstPicture, secondPicture),0LL);
    }
    {
        int firstPictureARRAY[] = {1,3};
        vector <int> firstPicture( firstPictureARRAY, firstPictureARRAY+ARRSIZE(firstPictureARRAY) );
        int secondPictureARRAY[] = {1,3};
        vector <int> secondPicture( secondPictureARRAY, secondPictureARRAY+ARRSIZE(secondPictureARRAY) );
        OneDimensionalBalls theObject;
        eq(2, theObject.countValidGuesses(firstPicture, secondPicture),1LL);
    }
    {
        int firstPictureARRAY[] = {7234};
        vector <int> firstPicture( firstPictureARRAY, firstPictureARRAY+ARRSIZE(firstPictureARRAY) );
        int secondPictureARRAY[] = {6316,689156,689160,689161,800000,1000001};
        vector <int> secondPicture( secondPictureARRAY, secondPictureARRAY+ARRSIZE(secondPictureARRAY) );
        OneDimensionalBalls theObject;
        eq(3, theObject.countValidGuesses(firstPicture, secondPicture),6LL);
    }
    {
        int firstPictureARRAY[] = {6,2,4};
        vector <int> firstPicture( firstPictureARRAY, firstPictureARRAY+ARRSIZE(firstPictureARRAY) );
        int secondPictureARRAY[] = {1,2,3,4,5,7,8};
        vector <int> secondPicture( secondPictureARRAY, secondPictureARRAY+ARRSIZE(secondPictureARRAY) );
        OneDimensionalBalls theObject;
        eq(4, theObject.countValidGuesses(firstPicture, secondPicture),7LL);
    }
    return 0;
}
// END CUT HERE
