import java.math.BigInteger;

public class Euler {
    public static void main(String args[]) {
	BigInteger a = BigInteger.ONE;
	BigInteger b = BigInteger.ZERO;
	for (int i = 99; i >= 1; --i) {
	    BigInteger t = BigInteger.ONE;
	    if (i % 3 == 2) {
		t = BigInteger.valueOf((i + 2) / 3 * 2);
	    }
	    t = t.multiply(a);
	    b = b.add(t);
	    BigInteger g = b.gcd(a);
	    a = a.divide(g);
	    b = b.divide(g);
	    BigInteger tmp = a;
	    a = b;
	    b = tmp;
	}
	b = b.add(a.shiftLeft(1));
	BigInteger g = b.gcd(a);
	a = a.divide(g);
	b = b.divide(g);
	System.out.println(b + "/" + a);
	String str = b.toString();
	int res = 0;
	for (int i = 0; i < str.length(); ++i) {
	    res += str.charAt(i) - '0';
	}
	System.out.println(res);
    }
}
