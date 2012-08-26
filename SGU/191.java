import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
	public static void main (String[] argv) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		char c;
		char[] a = new char[30001];
		int idx = 0;
		String str;
		str = in.readLine();
		c = str.charAt(0);
		str = in.readLine();
		int len = str.length();
		for (int i = 0; i < len; ++i) {
			if (idx == 0) {
				idx = 1;
				a[1] = str.charAt(i);
			} else {
				if (str.charAt(i) == a[idx]) --idx;
				else a[++idx] = str.charAt(i);
			}
		}
		if (idx > 1 || a[1] == c) System.out.println("NO");
		else System.out.println("YES");
	}
}
