import java.math.BigInteger;

public class Euler {
    private static BigInteger mm[][] = new BigInteger[105][10];
    
    private static BigInteger dp(int left, int prev) {
        if (mm[left][prev].compareTo(BigInteger.ZERO) > 0) return mm[left][prev];
        
        if (left == 0) return mm[left][prev] = BigInteger.ONE;
        
        mm[left][prev] = BigInteger.ZERO;
        for (int i = prev; i <= 9; ++i) {
            BigInteger t = dp(left - 1, i);
            mm[left][prev] = mm[left][prev].add(t);
        }
        
        return mm[left][prev];
    }
    
    public static void main(String args[]) {
        for (int i = 0; i <= 100; ++i) {
            for (int j = 1; j <= 9; ++j) {
                mm[i][j] = BigInteger.valueOf(-1);
            }
        }
        
        int maxn = 100;
        BigInteger res = BigInteger.ZERO;
        for (int len = 1; len <= maxn; ++len) {
            res = res.add(dp(len, 1).shiftLeft(1));
            for (int i = 1; i <= len - 1; ++i) res = res.add(dp(i, 1));
            res = res.subtract(BigInteger.valueOf(9));
        }
        
        System.out.println(res);
    }
}
