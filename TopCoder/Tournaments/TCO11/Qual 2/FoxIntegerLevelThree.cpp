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

// By inazz@TopCoder

// y*d(y) == x
// (9z+y)*y == x
// 9yz + yy

class FoxIntegerLevelThree {
public:
    long long lcm(long long a, long long b) {
        return a * b / gcd(a,b);
    }
    long long gcd(long long a, long long b) {
        if (a > b) return gcd(b, a);
        if (a == 0) return b;
        return gcd(b%a, a);
    }
    bool test(long long a) {
        for (int i = 1; i <= 9 && i*i <= a; i++)
            if ((a - i*i) % (9 * i) == 0)
                return true;
        return false;
    }
    long long count(long long min, long long max) {
        long long g = 1;
        for (int i=1; i<=9; i++)
            g = lcm(g, i);
        g *= 9;
        long long ans = 0;
        long long seg = 0;
        for (int i = g; i < 2 * g; i++)
            seg += test(i);
        max++;
        while (min < max && !(min % g == 0 && min >= g))
            ans += test(min++);
        ans += (max - min)/g * seg;
        min += (max - min)/g * g;
        while (min < max)
            ans += test(min++);
        return ans;
    }
};
// BEGIN CUT HERE
int main() {
    {
        FoxIntegerLevelThree theObject;
        eq(0, theObject.count(10LL, 16LL),2LL);
    }
    {
        FoxIntegerLevelThree theObject;
        eq(1, theObject.count(123LL, 123LL),0LL);
    }
    {
        FoxIntegerLevelThree theObject;
        eq(2, theObject.count(160LL, 160LL),1LL);
    }
    {
        FoxIntegerLevelThree theObject;
        eq(3, theObject.count(47LL, 58LL),4LL);
    }
    {
        FoxIntegerLevelThree theObject;
        eq(4, theObject.count(123456789LL, 9876543210LL),2618024258LL);
    }
    return 0;
}
// END CUT HERE
