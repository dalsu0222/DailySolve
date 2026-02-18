import java.util.*;
import java.io.*;

public class Main {
    static int t;
    static boolean[] isPrime = new boolean[10000]; // 0~9999
    
    static void checkPrime(){
      Arrays.fill(isPrime,true);
      isPrime[0] = isPrime[1] = false;
      
      for(int i=2 ; i*i <= 9999 ; i++){
        if(!isPrime[i]) continue;
        for(int j=i*i; j<=9999; j+=i){ // i의 배수 처리
          isPrime[j] = false;
        }
      }
    }
  
    static int changeToTarget(String start,String target){
      boolean[] visited = new boolean[10000]; // false
      Queue<int[]> q = new ArrayDeque<>(); // (num,d)
      q.offer(new int[]{Integer.parseInt(start),0});
      visited[Integer.parseInt(start)] = true;
      
      while(!q.isEmpty()){
        int[] tmp = q.poll();
        int num = tmp[0];
        int d = tmp[1];
        
        // target 인지 확인
        if(num == Integer.parseInt(target)){
          return d;
        }
        
        // 그 다음 소수이면서 한 글자만 다른지 체크
        String s = Integer.toString(num);
        char[] arr = s.toCharArray(); // String은 불변이므로 필요
        
        // 한글자만 바꿔서 소수인지 체크
        for(int i=0 ; i<4 ; i++){
          char c = arr[i];
          int startDig = i == 0 ? 1 : 0; // 천의자리는 0 불가
          for(int j=startDig ; j<=9 ; j++){ // j는 바꾸게 될 수
            if(c == (char)(j+'0')) continue; // 형명시 필요?
            
            arr[i] = (char)(j + '0');
            int next = Integer.parseInt(new String(arr));
            if(!visited[next] && isPrime[next]){
              q.offer(new int[]{next,d+1});
              visited[next] = true;
            }
            
            arr[i] = c; // 원상복구 필수
          }
        }
      }
      
      return -1;
    }
  
    public static void main(String[] args) throws IOException{
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());
      t = Integer.parseInt(st.nextToken());
      
       // 4자리수 소수 체크
      checkPrime();
        
      for(int i=0 ; i<t; i++){
        st = new StringTokenizer(br.readLine());
        String start = st.nextToken();
        String target = st.nextToken();
        
        // start = target 인지 확인, 맞으면 바로 0 반환
        if(start.equals(target)){
          System.out.println(0);
          continue;
        }
       
        
        // 변환 최소 횟수 구하기
        int result = changeToTarget(start,target);
        if(result == -1)
          System.out.println("Impossible");
        else
          System.out.println(result);
        
      }
    }
}