import java.util.*;
import java.io.*;
import java.math.*;

public class B
{
	public static void main (String[] argv) throws IOException
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		int kase = Integer.parseInt(st.nextToken());
		for (int k = 1; k <= kase; ++k) {
			System.out.print(String.format("Case #%s: ", k));
			
			st = new StringTokenizer(in.readLine());
			
			int n = Integer.parseInt(st.nextToken());
			ArrayList<BigInteger> list = new ArrayList<BigInteger>();
			for (int i = 0; i < n; ++i) {
				BigInteger b = new BigInteger(st.nextToken());
				list.add(b);
			}
			
			Collections.sort(list);
			
			BigInteger g = list.get(1).subtract(list.get(0));
			for (int i = 2; i <= n - 1; ++i) {
				BigInteger d = list.get(i).subtract(list.get(i - 1)); 
				g = B.gcd(g, d);
			}

		    BigInteger y = list.get(0).mod(g);
		    if (y != BigInteger.ZERO) y = g.subtract(y);
		    System.out.println(y);
		}
	}
	
	private static BigInteger gcd(BigInteger a, BigInteger b) {
		while (true) {
			if (b == BigInteger.ZERO) return a;
			a = a.mod(b);
			BigInteger c = b;
			b = a;
			a = c;
		}
	}
}
