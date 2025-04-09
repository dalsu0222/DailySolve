import java.util.*;
import java.io.*;

public class Main {
    static int n, l;
    static int[][] map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());
        map = new int[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            if (isValidRoad(map[i])) result++;
            if (isValidRoad(getCol(i))) result++;
        }

        System.out.println(result);
    }

    // 열 추출
    static int[] getCol(int colIdx) {
        int[] col = new int[n];
        for (int i = 0; i < n; i++) {
            col[i] = map[i][colIdx];
        }
        return col;
    }

    // 경사로 설치 가능한지 판단
    static boolean isValidRoad(int[] line) {
        boolean[] installed = new boolean[n];

        for (int i = 0; i < n - 1; i++) {
            int diff = line[i + 1] - line[i];

            if (diff == 0) continue;

            // 올라가는 경사로
            if (diff == 1) {
                for (int j = i; j > i - l; j--) {
                    if (j < 0 || line[j] != line[i] || installed[j]) return false;
                    installed[j] = true;
                }
            }
            // 내려가는 경사로
            else if (diff == -1) {
                for (int j = i + 1; j <= i + l; j++) {
                    if (j >= n || line[j] != line[i + 1] || installed[j]) return false;
                    installed[j] = true;
                }
            } else {
                return false; // 높이 차이가 2 이상이면 불가능함
            }
        }

        return true;
    }
}
