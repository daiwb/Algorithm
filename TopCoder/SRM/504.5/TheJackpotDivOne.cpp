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

class TheJackpotDivOne {
public:
    vector<long long> find(vector<long long> money, long long jackpot) {
        int n = money.size();
        while (jackpot > 0) {
            sort(money.begin(), money.end());
            if (money.front() == money.back()) break;

            LL d = 0;
            LL r = n;
            REP(i,n) {
                d += money[i] / n;
                r += money[i] % n;
            }
            d += r / n;
            d -= money[0];

            money[0] += min(d, jackpot);
            jackpot = max(0LL, jackpot - d);
        }
        sort(money.begin(), money.end());
        LL add = jackpot / n;
        jackpot %= n;
        RFOR(i,n-1,0) {
            money[i] += add;
            if (jackpot > 0) {
                ++money[i];
                --jackpot;
            }
        }
        return money;
    }
};
// BEGIN CUT HERE
int main() {
    {
        long long moneyARRAY[] = {367890375713257659};
        vector<long long> money( moneyARRAY, moneyARRAY+ARRSIZE(moneyARRAY) );
        long long retrunValueARRAY[] = {1345409013487966260};
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheJackpotDivOne theObject;
        eq(0, theObject.find(money, 977518637774708601LL),retrunValue);
    }
    {
        long long moneyARRAY[] = {805372452334228772LL, 323831522355545557LL, 222318376157839320LL, 890540141938216941LL};
        vector<long long> money( moneyARRAY, moneyARRAY+ARRSIZE(moneyARRAY) );
        long long retrunValueARRAY[] = {633666337549555264LL, 645064934956112230LL, 805372452334228772LL, 890540141938216941LL};
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheJackpotDivOne theObject;
        eq(0, theObject.find(money, 732581373992282617LL),retrunValue);
    }
    {
        long long moneyARRAY[] = {699085108043528729LL, 712159816824889738LL, 955333392923506302LL, 824815726724562276LL, 201243198940762441LL, 890074013601085831LL, 856280423905582773LL, 652869772991442089LL, 456424450107247762LL, 481552162171757726LL, 433983913446941400LL, 589533240618970779LL, 818688009567563283LL, 785702044492944871LL, 190360345644731728LL, 647032252659235390LL, 113369882957256831LL, 761824690082198585LL, 911259649954335014LL};
        vector<long long> money( moneyARRAY, moneyARRAY+ARRSIZE(moneyARRAY) );
        long long retrunValueARRAY[] = {201243198940762441LL, 359949898759778599LL, 433983913446941400LL, 456424450107247762LL, 481552162171757726LL, 589533240618970779LL, 630610110297818082LL, 647032252659235390LL, 652869772991442089LL, 699085108043528729LL, 712159816824889738LL, 761824690082198585LL, 785702044492944871LL, 818688009567563283LL, 824815726724562276LL, 856280423905582773LL, 890074013601085831LL, 911259649954335014LL, 955333392923506302LL};
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheJackpotDivOne theObject;
        eq(0, theObject.find(money, 686829780455608122LL),retrunValue);
    }
    {
        long moneyARRAY[] = {4L, 4L, 4L, 4L};
        vector<long long> money( moneyARRAY, moneyARRAY+ARRSIZE(moneyARRAY) );
        long retrunValueARRAY[] = {5L, 5L, 6L, 6L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheJackpotDivOne theObject;
        eq(0, theObject.find(money, 6L),retrunValue);
    }
    {
        long moneyARRAY[] = {1L, 2L, 3L, 4L};
        vector<long long> money( moneyARRAY, moneyARRAY+ARRSIZE(moneyARRAY) );
        long retrunValueARRAY[] = {2L, 3L, 3L, 4L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheJackpotDivOne theObject;
        eq(0, theObject.find(money, 2L),retrunValue);
    }
    {
        long moneyARRAY[] = {4L};
        vector<long long> money( moneyARRAY, moneyARRAY+ARRSIZE(moneyARRAY) );
        long retrunValueARRAY[] = {11L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheJackpotDivOne theObject;
        eq(1, theObject.find(money, 7L),retrunValue);
    }
    {
        long moneyARRAY[] = {4L, 44L, 7L, 77L};
        vector<long long> money( moneyARRAY, moneyARRAY+ARRSIZE(moneyARRAY) );
        long retrunValueARRAY[] = {24L, 34L, 44L, 77L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheJackpotDivOne theObject;
        eq(2, theObject.find(money, 47L),retrunValue);
    }
    {
        long moneyARRAY[] = {4L, 10L, 8L, 3L, 6L, 5L, 8L, 3L, 7L, 5L};
        vector<long long> money( moneyARRAY, moneyARRAY+ARRSIZE(moneyARRAY) );
        long retrunValueARRAY[] = {105L, 106L, 106L, 106L, 106L, 106L, 106L, 106L, 106L, 106L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheJackpotDivOne theObject;
        eq(3, theObject.find(money, 1000L),retrunValue);
    }
    return 0;
}
// END CUT HERE
