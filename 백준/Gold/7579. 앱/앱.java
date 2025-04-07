import java.io.*;
import java.util.*;

public class Main {
	static int n, k;
	static int[] m, c;
	static int[][] dp;
	static int minCost = Integer.MAX_VALUE;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		
		m = new int[n+1];
		c = new int[n+1];
		
		dp = new int[n+1][10001];	// dp[i][j] = 비용 i로 최대한 얻을 수 있는 메모리

		st = new StringTokenizer(br.readLine());
		for(int i=1 ; i<=n ; i++) {
			m[i] = Integer.parseInt(st.nextToken());
		}
		
		st = new StringTokenizer(br.readLine());
		for(int i=1 ; i<=n ; i++) {
			c[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i=1 ; i<=n ; i++) {
			for(int j=0 ; j<=10000 ; j++) {
				 if(j < c[i]) {
					 dp[i][j] = dp[i-1][j];
				 }else {
					 dp[i][j] = Math.max(m[i] + dp[i-1][j-c[i]], dp[i-1][j]);
				 }
				 
				 if(dp[i][j] >= k)
					 minCost = Math.min(minCost, j);
			}
		}
		
		System.out.println(minCost);
	
	}

}
