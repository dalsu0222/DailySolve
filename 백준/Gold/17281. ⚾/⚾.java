import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[][] players; // N번째 이닝에서 타자의 행동
    static boolean[] select; // 순열 생성
    static int[] order; // 타순 (인덱스: 타순, 값: 선수 번호)
    static int result;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());

        // init
        players = new int[n + 1][10];
        select = new boolean[10];
        order = new int[10];

        // input
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= 9; j++) {
                players[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 1번 선수는 4번 타자로 고정
        order[4] = 1;
        select[1] = true;

        result = 0;
        makeOrder(1);

        System.out.println(result);
        br.close();
    }

    // 타순 정하기 (순열)
    static void makeOrder(int idx) {
        if (idx == 10) {	// 모든 타순이 결정되는 경우
            play();
            return;
        }

        // 4번 타자는 이미 1번 선수로 정해져 있으므로 건너뜀
        if (idx == 4) {
            makeOrder(idx + 1);
            return;
        }

        // 나머지 타자 순서 정하기
        for (int i = 2; i <= 9; i++) {
            if (select[i]) continue;

            select[i] = true;
            order[idx] = i;	// idx번째 타자는 i번호를 가진 타자
            makeOrder(idx + 1);
            select[i] = false;
        }
    }

    // 야구 경기 시뮬레이션
    static void play() {
        int score = 0;
        int hitterIdx = 1; // 타순 (1~9)

        for (int inning = 1; inning <= n; inning++) {
            int outCount = 0;
            boolean[] bases = new boolean[4]; // 베이스 상태 (1루, 2루, 3루)

            // 3아웃까지 이닝 진행
            while (outCount < 3) {
                int hitter = order[hitterIdx]; // 현재 타자의 선수 번호
                int result = players[inning][hitter]; // 현재 타자의 결과

                // 다음 타자 준비
                hitterIdx = hitterIdx % 9 + 1;

                // 타자의 결과에 따른 진행
                switch (result) {
                    case 0: // 아웃
                        outCount++;
                        break;
                    case 1: // 안타 (1루타)
                        if (bases[3]) {
                            score++; // 3루 주자 홈인
                            bases[3] = false;
                        }
                        if (bases[2]) {
                            bases[3] = true; // 2루 -> 3루
                            bases[2] = false;
                        }
                        if (bases[1]) {
                            bases[2] = true; // 1루 -> 2루
                            bases[1] = false;
                        }
                        bases[1] = true; // 타자 1루 진출
                        break;
                    case 2: // 2루타
                        if (bases[3]) {
                            score++; // 3루 주자 홈인
                            bases[3] = false;
                        }
                        if (bases[2]) {
                            score++; // 2루 주자 홈인
                            bases[2] = false;
                        }
                        if (bases[1]) {
                            bases[3] = true; // 1루 -> 3루
                            bases[1] = false;
                        }
                        bases[2] = true; // 타자 2루 진출
                        break;
                    case 3: // 3루타
                        if (bases[3]) {
                            score++; // 3루 주자 홈인
                            bases[3] = false;
                        }
                        if (bases[2]) {
                            score++; // 2루 주자 홈인
                            bases[2] = false;
                        }
                        if (bases[1]) {
                            score++; // 1루 주자 홈인
                            bases[1] = false;
                        }
                        bases[3] = true; // 타자 3루 진출
                        break;
                    case 4: // 홈런
                        for (int i = 1; i <= 3; i++) {
                            if (bases[i]) {
                                score++; // 루에 있는 모든 주자 홈인
                                bases[i] = false;
                            }
                        }
                        score++; // 타자 홈인
                        break;
                }
            }
        }

        result = Math.max(result, score);
    }
}