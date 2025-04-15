import java.io.*;
import java.util.*;

public class Main {
	static int n, m, k;
	static long[] input;	// 0 based index
	static long[] tree;	// 1 based index

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		
		input = new long[n];
		for(int i=0 ; i<n ; i++) {
			input[i] = Long.parseLong(br.readLine());
		}
		
		tree = new long[4_000_001];
		
		makeTree(1,0,n-1);
		
		int a,b;	long c;
		for(int i=0 ; i<m+k ; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Long.parseLong(st.nextToken());
			
			if(a == 1) {
				update(1,0, n-1, b-1, c);
			}else if(a == 2) {
				sb.append(get(1, 0, n-1, b-1, (int)c-1)).append("\n");
			}
		}
		
		System.out.println(sb);
	
	}
	
	static void makeTree(int node, int start, int end) {
		if(start == end) {
			tree[node] = input[start];
		}else {
			makeTree(node*2, start, (start+end)/2);
			makeTree(node*2 + 1, (start+end)/2 + 1, end);
			tree[node] = tree[node*2] + tree[node*2+1];
		}
	}
	
	static void update(int node, int start, int end, int idx, long val) {
		if(idx < start || idx > end)	// 찾는 요소가 범위 밖에 있으면 return
			return;
			
		if(start == end) {	// 찾는 요소의 번호에 도달
			input[idx] = val;
			tree[node] = val;
			return;
		}
		
		update(node*2, start, (start+end)/2, idx, val);
		update(node*2 + 1,(start+end)/2 + 1, end, idx, val);
		tree[node] = tree[node*2] + tree[node*2+1];	// update된 tree 반영
	}
	
	static long get(int node, int start, int end, int left, int right) {
		if(right < start || left > end)	// 찾는 요소가 범위 밖에 있으면 return
			return 0;
			
		if(left <= start && end <= right) {
			return tree[node];
		}
		
		long l_result = get(node*2, start, (start+end)/2, left, right);
		long r_result = get(node*2 + 1, (start+end)/2 + 1, end, left, right);
		
		return l_result + r_result;
	}

}
