import java.io.*;
import java.util.StringTokenizer;

public class Solution{
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		for(int tc=1 ; tc<=t ; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			
			// n x n 사이즈 배열 입력받기
			int[][] arr = new int[n][n];
			for(int i=0 ; i<n ; i++) {
				 st = new StringTokenizer(br.readLine());
				 for(int j=0 ; j<n ; j++) {
					 arr[i][j] = Integer.parseInt(st.nextToken());
				 }
			}
			
			// m 크기의 영역중 합이 가장 큰 영역 찾기
			int max_total = 0;
			for(int i=0 ; i<= n-m ; i++) {
				for(int j=0 ; j<= n-m ; j++) {
					int total = 0;
					for(int k=0 ; k<m ; k++) {
						for(int r=0 ; r<m ; r++) {
							total += arr[i+k][j+r];
						}
					}
					max_total = Math.max(max_total, total);
				}
			}
			
			System.out.println("#"+ tc + " " + max_total);
		}
	}

}