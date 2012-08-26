import java.math.BigInteger;

public class Euler {
    private static int doit(int n) {
        for (int i = 1; i <= 10; ++i) {
            if (i * i == n) {
                return 0;
            }
        }
        String s = "";
        String str = String.valueOf(n);
        int len = str.length();
        BigInteger r = BigInteger.valueOf(Integer.parseInt(str.substring(0, 2 - len % 2)));
        int idx = 2 - len % 2;
        int num = 0;
        BigInteger q = BigInteger.ZERO;
        while (true) {
            int t = (int) Math.sqrt(r.doubleValue());
            int low = 0, high = t;
            while (true) {
                if (low == high) {
                    t = low;
                    break;
                }
                if (low + 1 == high) {
                    BigInteger p = BigInteger.valueOf(high);
                    BigInteger o = p.add(q).multiply(p);
                    if (o.compareTo(r) <= 0)
                        t = high;
                    else
                        t = low;
                    break;
                }
                int mid = (low + high) / 2;
                BigInteger p = BigInteger.valueOf(mid);
                BigInteger o = p.add(q).multiply(p);
                if (o.compareTo(r) <= 0) {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }
            BigInteger p = BigInteger.valueOf(t);
            BigInteger o = p.add(q).multiply(p);
            r = r.subtract(o);
            s += String.valueOf((char) (t + '0'));
            if (idx < len) {
                r = r.multiply(BigInteger.valueOf(100)).add(
                        BigInteger.valueOf(Integer.valueOf(str.substring(idx, idx + 2))));
                idx += 2;
            } else {
                r = r.multiply(BigInteger.valueOf(100));
                if (s.indexOf(".") == -1) {
                    s += ".";
                }
            }
            ++num;
            if (num == 100)
                break;
            q = q.multiply(BigInteger.valueOf(10)).add(BigInteger.valueOf(t * 20));
        }
        System.out.println(s);
        int ret = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) != '.')
                ret += s.charAt(i) - '0';
        }
        return ret;
    }

    public static void main(String args[]) {
        int res = 0;
        for (int i = 1; i <= 100; ++i) {
            res += doit(i);
        }
        System.out.println(res);
    }
}
