import java.util.*;
import java.io.*;
import java.math.*;

public class security
{
    private static String k1, k2, str;
    private static int n, sz, lt, tot;
    private static int[][] vol = new int[105][105];
    private static int[][] flow = new int[105][105];
    private static BigInteger[][] cost = new BigInteger[105][105];
    private static BigInteger six = BigInteger.valueOf(6);
    private static BigInteger inf = BigInteger.ONE;
    
    private static int min_cost_max_flow(int n, int mat[][], BigInteger cost[][], int source, int sink, int[][] flow) {
    	int[] pre = new int[105];
    	int[] d = new int[105];
    	int i, j, t, tag;
    	BigInteger[] min = new BigInteger[105];
    	if (source == sink) {
    		return 1000000000;
    	}
    	for (i=0;i<n;i++) {
    		for (j=0;j<n;flow[i][j++]=0);
    	}
    	BigInteger netcost = BigInteger.ZERO;
    	while (true){
    		for (i=0;i<n;i++) {
    			pre[i]=0;
    			min[i]=inf;
    		}
    		pre[source]=source+1;
    		min[source]=BigInteger.ZERO;
    		d[source]=1000000000;
    		tag = 1;
    		for (;tag != 0;) {
    			for (tag=t=0;t<n;t++) {
    				if (d[t] != 0) {
    					for (i=0;i<n;i++) {
    						if ((j=mat[t][i]-flow[t][i]) != 0 && min[t].add(cost[t][i]).compareTo(min[i]) < 0) {
    							tag=1;
    							min[i]=min[t].add(cost[t][i]);
    							pre[i]=t+1;
    							d[i]=d[t]<j?d[t]:j;
    						} else if ((j=flow[i][t]) != 0 && min[t].compareTo(inf) < 0&&min[t].subtract(cost[i][t]).compareTo(min[i]) < 0) {
    							tag=1;
    							min[i]=min[t].subtract(cost[i][t]);
    							pre[i]=-t-1;
    							d[i]=d[t]<j?d[t]:j;
    						}
    					}
    				}
    			}
    		}
    		if (pre[sink] == 0)	break;
    		netcost = netcost.add(min[sink].multiply(BigInteger.valueOf(d[i=sink])));
    		for (;i!=source;) {
    			if (pre[i]>0) {
    				flow[pre[i]-1][i]+=d[sink];
    				i=pre[i]-1;
    			} else {
    				flow[i][-pre[i]-1]-=d[sink];
    				i=-pre[i]-1;
    			}
    		}
    	}
    	for (j=i=0;i<n;j+=flow[source][i++]);
    	return j;
    }
    
    private static BigInteger getV(int i1, int i2) {
    	str = "";
    	BigInteger ret = BigInteger.ZERO;
    	int s1 = i1 * lt, s2 = i2 * lt;
    	for (int i = 0; i < lt; ++i) {
    		char c1 = k1.charAt(s1), c2 = k2.charAt(s2);
    		if (c1 != '?' && c2 != '?') {
    			if (c1 == c2) {
	    			str += k1.charAt(s1);
	    			ret = ret.multiply(six).add(BigInteger.valueOf(k1.charAt(s1) - 'a'));
    			} else {
        			return BigInteger.valueOf(-1);
        		}
    		} else if (c1 == '?' && c2 == '?') {
    			str += 'a';
    			ret = ret.multiply(six);
    		} else {
    			if (c1 == '?') {
    				str += c2;
    				ret = ret.multiply(six).add(BigInteger.valueOf(c2 - 'a'));
    			} else {
    				str += c1;
    				ret = ret.multiply(six).add(BigInteger.valueOf(c1 - 'a'));
    			}
    		}
    		++s1;
    		++s2;
    	}
    	return ret;
    }
    
    public static void main (String[] argv) throws IOException
	{
    	for (int i = 0; i < 100; ++i) {
    		inf = inf.multiply(six);
    	}
    	
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());

        int kase = Integer.parseInt(st.nextToken());
        for (int k = 1; k <= kase; ++k) {
			System.out.print(String.format("Case #%s: ", k));

			st = new StringTokenizer(in.readLine());
			n = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(in.readLine());
            k1 = st.nextToken();
            st = new StringTokenizer(in.readLine());
            k2 = st.nextToken();
            
            for (int i = 0; i < 105; ++i) {
            	for (int j = 0; j < 105; ++j) {
            		vol[i][j] = 0;
            		cost[i][j] = BigInteger.ZERO;
            	}
            }
            sz = k1.length();
            lt = sz / n;
            tot = n * 2 + 2;
            
            BigInteger mu = BigInteger.ONE, t = BigInteger.ONE;
            for (int i = 0; i < lt; ++i) {
            	mu = mu.multiply(six);
            }
            
            for (int i = 1; i <= n; ++i) {
            	vol[0][i] = 1;
            	cost[0][i] = BigInteger.ZERO;
            	vol[i + n][tot - 1] = 1;
            	cost[i + n][tot - 1] = BigInteger.ZERO;
            }
            for (int i = n; i >= 1; --i) {
            	for (int j = 1; j <= n; ++j) {
            		int idx1 = i, idx2 = n + j;
            		BigInteger v = getV(i - 1, j - 1);
            		if (v.compareTo(BigInteger.ZERO) < 0) {
            			vol[idx1][idx2] = 0;
            			cost[idx1][idx2] = BigInteger.ZERO;
            		} else {
            			vol[idx1][idx2] = 1;
            			cost[idx1][idx2] = v.multiply(t);
            		}
            	}
            	t = t.multiply(mu);
            }
            int f = min_cost_max_flow(tot, vol, cost, 0, tot - 1, flow);
            if (f < n) {
            	System.out.println("IMPOSSIBLE");
            } else {
            	String res = "";
            	for (int i = 1; i <= n; ++i) {
            		for (int j = 1; j <= n; ++j) {
            			if (flow[i][j + n] == 1) {
            				getV(i - 1, j - 1);
            				res += str;
            				break;
            			}
            		}
            	}
            	System.out.println(res);
            }
        }
    }
}
