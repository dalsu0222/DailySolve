import java.io.*;
import java.util.*;

public class Solution {
    static int n, l;
    static int[][] map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= t; tc++) {
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

            sb.append("#").append(tc).append(" ").append(result).append("\n");
        }

        System.out.print(sb);
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

            if (diff == 1) { // 오르막
                for (int j = i; j > i - l; j--) {
                    if (j < 0 || line[j] != line[i] || installed[j]) return false;
                    installed[j] = true;
                }
            } else if (diff == -1) { // 내리막
                for (int j = i + 1; j <= i + l; j++) {
                    if (j >= n || line[j] != line[i + 1] || installed[j]) return false;
                    installed[j] = true;
                }
            } else {
                return false;
            }
        }
        return true;
    }
}