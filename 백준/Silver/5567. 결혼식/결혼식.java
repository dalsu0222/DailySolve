import java.util.*;
import java.io.*;

public class Main {
    static int n,m;
    static List<Integer>[] v;
    static boolean[] visited;
    static int answer;
    
    static void findFriends(int x){
      visited[x] = true;
      Queue<int[]> q = new ArrayDeque<>(); // (번호, 깊이) 저장
      q.offer(new int[]{x,0});
      
      while(!q.isEmpty()){
        int[] top = q.poll();
        int num = top[0];
        int d = top[1];
        
        if(d>=2) continue;
        
        for(int i=0 ; i<v[num].size(); i++){
          int nx = v[num].get(i); // ArrayList 원소에 접근
          if(visited[nx] == true) continue;
          
          visited[nx] = true;
          q.offer(new int[]{nx,d+1});
          answer++;
        }
      }
    }
  
    public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());
      
      n = Integer.parseInt(st.nextToken());
      st = new StringTokenizer(br.readLine());
      m = Integer.parseInt(st.nextToken());
      
      v = new ArrayList[n+1];
      visited = new boolean[n+1];
      for(int i=0 ; i<=n; i++){
        v[i] = new ArrayList<>();
      }
      
      int a,b;
      for(int i=0 ; i<m ; i++){
        st = new StringTokenizer(br.readLine());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        
        v[a].add(b);
        v[b].add(a);
      }
      
      findFriends(1);
      
      System.out.println(answer);
    }
}