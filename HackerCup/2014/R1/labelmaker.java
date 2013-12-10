import java.util.*;
import java.io.*;
import java.math.*;

public class labelmaker
{    
    public static void main (String[] argv) throws IOException
	{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
        int kase = Integer.parseInt(st.nextToken());
        for (int k = 1; k <= kase; ++k) {
			System.out.print(String.format("Case #%s: ", k));

			String letters;
			BigInteger n;
			st = new StringTokenizer(in.readLine());
			letters = st.nextToken();
            n = BigInteger.valueOf(Long.parseLong(st.nextToken()));
            
            int len = letters.length();
            if (len == 1) {
            	for (Long i = 0L; i < n.longValue(); ++i) {
            		System.out.print(letters);
            	}
            	System.out.println();
            	continue;
            }
            
            int sz = 0;
            BigInteger tmp = BigInteger.ONE;
            BigInteger bLen = BigInteger.valueOf(len);
            while (true) {
            	++sz;
            	tmp = tmp.multiply(bLen);
            	if (n.compareTo(tmp) <= 0) {
            		tmp = tmp.divide(bLen);
            		break;
            	}
            	n = n.subtract(tmp);
            }
            
            n = n.subtract(BigInteger.ONE);
            StringBuilder ret = new StringBuilder();
            for (int i = 0; i < sz; ++i) {
            	ret.append(letters.charAt(n.divide(tmp).intValue()));
            	n = n.mod(tmp);
            	tmp = tmp.divide(bLen);
            }
            
            System.out.println(ret.toString());
        }
    }
}

