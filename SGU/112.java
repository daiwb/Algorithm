import java.util.*;
import java.io.*;
import java.math.*;

public class Solution
{
	public static void main (String[] argv) throws IOException
	{
		BufferedReader in = new BufferedReader(new
				InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());

		BigInteger biga = BigInteger.valueOf(a);
		BigInteger bigb = BigInteger.valueOf(b);
		BigInteger res = biga.pow(b).subtract(bigb.pow(a));
		System.out.println(res.toString());
	}
}
