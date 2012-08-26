// By ACRush

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

#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))
struct Tnode
{
    char type;
    vector<int> childs;
    int size;
};
class TreeMaps
{
    public:
        int n;
        Tnode tree[1000];
        int solve(int v,double x1,double y1,double x2,double y2,double x0,double y0)
        {
            if (tree[v].type=='F')
            {
                tree[v].size=0;
                return v;
            }
            int tmp=-1;
            double last=x1;
            for (int i=0;i<SIZE(tree[v].childs);i++)
            {
                double next=last+(x2-x1)/tree[v].size*tree[tree[v].childs[i]].size;
                if (x0>=last && x0<=next)
                {
                    tmp=solve(tree[v].childs[i],y1,last,y2,next,y0,x0);
                    break;
                }
                last=next;
            }
            tree[v].size=0;
            for (int i=0;i<SIZE(tree[v].childs);i++)
                tree[v].size+=tree[tree[v].childs[i]].size;
            return tmp;
        }
        vector <int> eraseFiles(string type, vector <int> parent, vector <int> size, int width, int height, vector <int> px, vector <int> py)
        {
            n=LENGTH(type);
            for (int i=0;i<n;i++)
            {
                tree[i].type=type[i];
                tree[i].childs.clear();
                tree[i].size=size[i];
            }
            for (int i=0;i<n;i++)
                if (parent[i]>=0)
                    tree[parent[i]].childs.push_back(i);
            vector<int> R;
            for (int i=0;i<SIZE(px);i++)
            {
                int ret=solve(0,0,0,width,height,px[i],py[i]);
                R.push_back(ret);
            }
            return R;
        }
};
// BEGIN CUT HERE
int main() {
    {
        int parentARRAY[] = {-1, 0, 0, 0, 3, 3, 3, 3, 0};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        int sizeARRAY[] = {10, 2, 2, 4, 1, 1, 1, 1, 2};
        vector <int> size( sizeARRAY, sizeARRAY+ARRSIZE(sizeARRAY) );
        int pxARRAY[] = {12, 12};
        vector <int> px( pxARRAY, pxARRAY+ARRSIZE(pxARRAY) );
        int pyARRAY[] = {1, 4};
        vector <int> py( pyARRAY, pyARRAY+ARRSIZE(pyARRAY) );
        int retrunValueARRAY[] = {4, 6 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TreeMaps theObject;
        eq(0, theObject.eraseFiles("DFFDFFFFF", parent, size, 20, 8, px, py),retrunValue);
    }
    {
        int parentARRAY[] = {-1, 0, 0, 0, 3, 3, 3, 3, 0};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        int sizeARRAY[] = {10, 2, 2, 4, 1, 1, 1, 1, 2};
        vector <int> size( sizeARRAY, sizeARRAY+ARRSIZE(sizeARRAY) );
        int pxARRAY[] = {12, 12, 12, 12, 12};
        vector <int> px( pxARRAY, pxARRAY+ARRSIZE(pxARRAY) );
        int pyARRAY[] = {1, 1, 1, 1, 1};
        vector <int> py( pyARRAY, pyARRAY+ARRSIZE(pyARRAY) );
        int retrunValueARRAY[] = {4, 5, 6, 7, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TreeMaps theObject;
        eq(1, theObject.eraseFiles("DFFDFFFFF", parent, size, 20, 8, px, py),retrunValue);
    }
    {
        int parentARRAY[] = {-1, 0, 0, 1, 1, 2, 2, 5, 5};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        int sizeARRAY[] = {10, 4, 6, 2, 2, 5, 1, 2, 3};
        vector <int> size( sizeARRAY, sizeARRAY+ARRSIZE(sizeARRAY) );
        int pxARRAY[] = {16, 41, 32};
        vector <int> px( pxARRAY, pxARRAY+ARRSIZE(pxARRAY) );
        int pyARRAY[] = {10, 38, 29};
        vector <int> py( pyARRAY, pyARRAY+ARRSIZE(pyARRAY) );
        int retrunValueARRAY[] = {3, 8, 7 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TreeMaps theObject;
        eq(2, theObject.eraseFiles("DDDFFDFFF", parent, size, 50, 50, px, py),retrunValue);
    }
    {
        int parentARRAY[] = {-1, 5, 5, 5, 5, 0};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        int sizeARRAY[] = {10, 4, 2, 3, 1, 10};
        vector <int> size( sizeARRAY, sizeARRAY+ARRSIZE(sizeARRAY) );
        int pxARRAY[] = {1, 1};
        vector <int> px( pxARRAY, pxARRAY+ARRSIZE(pxARRAY) );
        int pyARRAY[] = {2, 18};
        vector <int> py( pyARRAY, pyARRAY+ARRSIZE(pyARRAY) );
        int retrunValueARRAY[] = {1, 4 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TreeMaps theObject;
        eq(3, theObject.eraseFiles("DFFFFD", parent, size, 20, 20, px, py),retrunValue);
    }
    return 0;
}
// END CUT HERE
