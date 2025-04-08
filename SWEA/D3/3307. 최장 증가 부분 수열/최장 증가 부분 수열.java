import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			int n = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());

			ArrayList<Integer> list = new ArrayList<>();
			list.add(-1);

			for (int i = 0; i < n; i++) {
				int num = Integer.parseInt(st.nextToken());

				if (num >= list.get(list.size() - 1)) {
					list.add(num);
					continue;
				}

                // lower bound
				int left = 0;
				int right = list.size() - 1;
				while (left <= right) {
					int mid = (left + right) / 2;

					if (num > list.get(mid)) {
						left = mid + 1;
					} else {
						right = mid - 1;
					}
				}
                
				list.set(left, num);
			}

			sb.append("#").append(tc).append(" ").append(list.size() - 1).append("\n");
		}

		System.out.print(sb);
	}
}
