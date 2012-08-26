import java.math.BigInteger;

public class Euler {
    public static void main(String args[]) {
        BigInteger a = BigInteger.valueOf(1);
        BigInteger b = BigInteger.valueOf(3);
        while (true) {
            BigInteger c = b.multiply(BigInteger.valueOf(6)).subtract(a).subtract(BigInteger.valueOf(2));
            BigInteger t = c.multiply(c).subtract(c).multiply(BigInteger.valueOf(8)).add(BigInteger.ONE);
            t = BigInteger.valueOf((long) ((Math.sqrt(t.doubleValue()) + 1.000000005) / 2));
            if (t.longValue() > 1000000000000L) {
                System.out.println(c);
                return;
            }
            a = b;
            b = c;
        }
    }
}
