import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static ArrayList<int[]> steps;
    
    static void hanoi(int n, int from, int to, int via) {
        if(n == 1) { //가장 큰 하나의 원판만 남았으면, 1 -> 3
            steps.add(new int[] {from, to});
        }else {
            //1.N-1개의 원판을 1 -> 2
            hanoi(n-1, from, via, to);
            steps.add(new int[] {from, to});
            //2.N-1개의 원판을 2 -> 3
            hanoi(n-1, via, to, from);
        }
    }
    
    public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      n = Integer.parseInt(br.readLine());
      steps = new ArrayList<int[]>();
      
      // 이동 횟수 출력 = 2^n - 1
      BigInteger count = new BigInteger("2");
      System.out.println(count.pow(n).subtract(new BigInteger("1")));
      
      if(n <= 20) {
          hanoi(n, 1, 3, 2);

          for (int i = 0; i < steps.size(); i++) {
              int[] step = steps.get(i);
              System.out.println(step[0] + " " + step[1]);
          }
      }
      
    }
}