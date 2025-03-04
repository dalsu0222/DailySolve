import java.io.*;

public class Main {
	static int n, r, c;
	static int cnt;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		r = Integer.parseInt(input[1]);
		c = Integer.parseInt(input[2]);
		
		Z(0,0, (int) Math.pow(2,n));

	}
	
	static void Z(int x, int y, int size) {
		if(x == r && y == c) {
			System.out.println(cnt);
			return;
		}
		
		if(x <= r && r < x + size 
				&& y <= c && c < y + size) {
			// 찾으려는 열&행이 사분면 안에 있는 경우
			Z(x, y, size / 2);
			Z(x, y + size / 2, size / 2);
			Z(x + size / 2, y, size / 2);
			Z(x + size / 2, y + size / 2, size / 2);
		}else {	// 없다면 정사각형 넓이만큼 카운트 추가
			cnt += size * size;
		}
	}
}
