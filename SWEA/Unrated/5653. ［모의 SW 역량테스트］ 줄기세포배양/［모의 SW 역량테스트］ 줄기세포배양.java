import java.io.*;
import java.util.*;

public class Solution {
    static int t, n, m, k;
    static int[][] map;
    static int SIZE = 650;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    static class Cell implements Comparable<Cell> {
        int x, y;
        int life;
        int remain;

        Cell(int x, int y, int life, int remain) {
            this.x = x;
            this.y = y;
            this.life = life;
            this.remain = remain;
        }

        @Override
        public int compareTo(Cell o) {
            return o.life - this.life; // 생명력 내림차순
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        t = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());

            map = new int[SIZE][SIZE];
            Queue<Cell> q = new ArrayDeque<>();

            int mid = SIZE / 2;

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < m; j++) {
                    int life = Integer.parseInt(st.nextToken());
                    if (life == 0) continue;

                    int nx = mid + i;
                    int ny = mid + j;
                    map[nx][ny] = life;
                    q.offer(new Cell(nx, ny, life, life));
                }
            }

            // 시뮬레이션
            for (int time = 1; time <= k; time++) {
                PriorityQueue<Cell> pq = new PriorityQueue<>();

                int size = q.size();
                for (int i = 0; i < size; i++) {
                    Cell cur = q.poll();

                    if (cur.remain > 0) {
                        cur.remain--;
                        q.offer(cur);
                    } else if (cur.remain == 0) {
                        for (int d = 0; d < 4; d++) {
                            int nx = cur.x + dx[d];
                            int ny = cur.y + dy[d];

                            if (map[nx][ny] == 0) {
                                pq.offer(new Cell(nx, ny, cur.life, cur.life));
                            }
                        }
                        cur.remain--;
                        q.offer(cur);
                    } else {
                        cur.remain--;
                        if (cur.remain > -cur.life) {
                            q.offer(cur);
                        }
                    }
                }

                // 번식 처리
                while (!pq.isEmpty()) {
                    Cell c = pq.poll();
                    if (map[c.x][c.y] == 0) {
                        map[c.x][c.y] = c.life;
                        q.offer(c);
                    }
                }
            }

            // 살아있는 세포만 카운트 (비활성 + 활성)
            int ans = 0;
            for (Cell cell : q) {
                if (cell.remain > -cell.life) {
                    ans++;
                }
            }

            sb.append("#").append(tc).append(" ").append(ans).append("\n");
        }

        System.out.println(sb);
    }
}
