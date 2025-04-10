import java.io.*;
import java.util.*;

public class Solution {
    static int n, w, h;
    static int answer;
    static int[][] map;
    static int[] dx = {-1, 1, 0, 0}; // 상 하 좌 우
    static int[] dy = {0, 0, 1, -1};

    static class Pos {
        int x, y, range;

        Pos(int x, int y, int range) {
            this.x = x;
            this.y = y;
            this.range = range;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= t; tc++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());

            map = new int[h + 1][w + 1];
            int blockCount = 0;

            // 입력 처리
            for (int row = 1; row <= h; row++) {
                st = new StringTokenizer(br.readLine());
                for (int col = 1; col <= w; col++) {
                    map[row][col] = Integer.parseInt(st.nextToken());
                    if (map[row][col] > 0) blockCount++;
                }
            }

            answer = blockCount + 1; // 최대값 초기화

            int[][] temp = copyMap(map);

            // 첫 구슬 떨어뜨리기 시뮬레이션
            for (int col = 1; col <= w; col++) {
                for (int row = 1; row <= h; row++) {
                    if (map[row][col] != 0) {
                        crush(0, row, col, blockCount);
                        map = copyMap(temp); // 원상복구
                        break;
                    }
                }
            }

            sb.append("#").append(tc).append(" ").append(answer).append("\n");
        }

        System.out.print(sb);
    }

    // 구슬을 떨어뜨려 벽돌을 부수고 연쇄적으로 터뜨리는 시뮬레이션 함수
    static void crush(int depth, int x, int y, int remain) {
        if (depth == n) {
            answer = Math.min(answer, remain);
            return;
        }

        Queue<Pos> q = new LinkedList<>();
        int[][] temp = copyMap(map);

        q.add(new Pos(x, y, map[x][y]));
        map[x][y] = 0;
        remain--;

        // bfs 로 벽돌 터뜨리기
        while (!q.isEmpty()) {
            Pos now = q.poll();

            for (int d = 0; d < 4; d++) {
                int nx = now.x;
                int ny = now.y;

                for (int k = 1; k < now.range; k++) {
                    nx += dx[d];
                    ny += dy[d];

                    if (nx <= 0 || ny <= 0 || nx > h || ny > w) continue;
                    if (map[nx][ny] == 0) continue;

                    if (map[nx][ny] > 1) q.add(new Pos(nx, ny, map[nx][ny]));

                    map[nx][ny] = 0;
                    remain--;
                }
            }
        }

        drop();

        if (remain <= 0) {
            answer = 0;
            return;
        }

        temp = copyMap(map);

        // 다음 구슬 떨어뜨리기
        for (int col = 1; col <= w; col++) {
            for (int row = 1; row <= h; row++) {
                if (map[row][col] != 0) {
                    crush(depth + 1, row, col, remain);
                    map = copyMap(temp);
                    break;
                }
            }
        }
    }

    // 벽돌이 부숴진 후 위에 있는 벽돌들을 아래로 떨어뜨리는 함수
    static void drop() {
        for (int col = 1; col <= w; col++) {
            int bottom = h;
            for (int row = h; row >= 1; row--) {
                if (map[row][col] > 0) {
                    map[bottom][col] = map[row][col];
                    if (bottom != row) map[row][col] = 0;
                    bottom--;
                }
            }
            for (int row = bottom; row >= 1; row--) {
                map[row][col] = 0;
            }
        }
    }

    // 배열 복사 함수
    static int[][] copyMap(int[][] src) {
        int[][] dest = new int[h + 1][w + 1];
        for (int x = 1; x <= h; x++) {
            dest[x] = src[x].clone();
        }
        return dest;
    }
}
