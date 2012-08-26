// BEGIN CUT HERE

// END CUT HERE
using System;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections;

public class SquareFreeNumbers {
    private int[] plist = new int[200000];
    private int pcount=0;

    public int prime(int n){
	    int i;
	    if ((n!=2&&!((n%2)>0))||(n!=3&&!((n%3)>0))||(n!=5&&!((n%5)>0))||(n!=7&&!((n%7)>0)))
		    return 0;
	    for (i=0;plist[i]*plist[i]<=n;i++)
		    if (!((n%plist[i]) > 0))
			    return 0;
        if (n > 1) return 1;
        else return 0;
    }

    public void initprime(){
        pcount = 0;
	    int i;
	    for (plist[pcount++]=2,i=3;i<2000000;i++)
		    if (prime(i) == 1)
			    plist[pcount++]=i;
    }

    private int[] mm = new int[1000005];

    public int getCount(long min, long max) {
        initprime();
        for (int i = 0; i < 1000005; ++i) mm[i] = 0;
        for (int i = 0; i < pcount; ++i) {
            long t = plist[i];
            t *= t;
            if (t > max) break;
            long start = min / t;
            start *= t;
            while (true) {
                if (start > max) break;
                if (start >= min) mm[start - min] = 1;
                start += t;
            }
        }
        int res = 0;
        for (long i = min; i <= max; ++i) {
            if (mm[i - min] == 0) ++res;
        }
        return res;
    }

// BEGIN CUT HERE
    public static void Main(String[] args) {
        try  {
            eq(0,(new SquareFreeNumbers()).getCount(1L, 10L),7);
            eq(1,(new SquareFreeNumbers()).getCount(15L, 15L),1);
            eq(2,(new SquareFreeNumbers()).getCount(1L, 1000L),608);
        } 
        catch( Exception exx)  {
            System.Console.WriteLine(exx);
            System.Console.WriteLine( exx.StackTrace);
        }
    }
    private static void eq( int n, object have, object need) {
        if( eq( have, need ) ) {
            Console.WriteLine( "Case "+n+" passed." );
        } else {
            Console.Write( "Case "+n+" failed: expected " );
            print( need );
            Console.Write( ", received " );
            print( have );
            Console.WriteLine();
        }
    }
    private static void eq( int n, Array have, Array need) {
        if( have == null || have.Length != need.Length ) {
            Console.WriteLine("Case "+n+" failed: returned "+have.Length+" elements; expected "+need.Length+" elements.");
            print( have );
            print( need );
            return;
        }
        for( int i= 0; i < have.Length; i++ ) {
            if( ! eq( have.GetValue(i), need.GetValue(i) ) ) {
                Console.WriteLine( "Case "+n+" failed. Expected and returned array differ in position "+i );
                print( have );
                print( need );
                return;
            }
        }
        Console.WriteLine("Case "+n+" passed.");
    }
    private static bool eq( object a, object b ) {
        if ( a is double && b is double ) {
            return Math.Abs((double)a-(double)b) < 1E-9;
        } else {
            return a!=null && b!=null && a.Equals(b);
        }
    }
    private static void print( object a ) {
        if ( a is string ) {
            Console.Write("\"{0}\"", a);
        } else if ( a is long ) {
            Console.Write("{0}L", a);
        } else {
            Console.Write(a);
        }
    }
    private static void print( Array a ) {
        if ( a == null) {
            Console.WriteLine("<NULL>");
        }
        Console.Write('{');
        for ( int i= 0; i < a.Length; i++ ) {
            print( a.GetValue(i) );
            if( i != a.Length-1 ) {
                Console.Write(", ");
            }
        }
        Console.WriteLine( '}' );
    }
// END CUT HERE
}
