import java.util.*;
import java.io.*;
import java.math.*;

class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line;
        
        for (int now = 0; (line = reader.readLine()) != null; ++now) {
            if (now > 0) {
                line = reader.readLine();
                System.out.println();
            }
            String[] nums = line.split("\\s+");
            BigInteger a = new BigInteger(nums[0]);
            BigInteger b = new BigInteger(nums[1]);
            System.out.println(a.gcd(b));
        }
    }
}
