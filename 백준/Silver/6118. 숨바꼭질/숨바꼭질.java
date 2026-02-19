import java.util.*;
import java.io.*;

public class Main {
  static int n, m;
  static List<Integer>[] cabin;
  static boolean[] visited;
  static int maxD;
  static List<Integer> clist = new ArrayList<>();
  
  static void findCabin(int x){
    visited[x] = true;
    Queue<int[]> q = new ArrayDeque<>(); // (num,d)
    q.offer(new int[]{x,0});
    
    while(!q.isEmpty()){
      int[] tmp = q.poll();
      int num = tmp[0];
      int d = tmp[1];
      
      if(d > maxD){
        maxD = d;
        clist.clear();
        clist.add(num);
      }else if(d == maxD){
        clist.add(num);
      }
      
      for(int i=0 ; i<cabin[num].size(); i++){
        int num2 = cabin[num].get(i);
        if(!visited[num2]){
          q.offer(new int[]{num2,d+1});
          visited[num2] = true;
        }
      }
    }
  }
  
    public static void main(String[] args) throws IOException{
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());
      n = Integer.parseInt(st.nextToken());
      m = Integer.parseInt(st.nextToken());
      
      visited = new boolean[n+1];
      cabin = new ArrayList[n+1]; // 1 based Index
      for(int i=0 ; i<=n ; i++){
        cabin[i] = new ArrayList<>();
      }
      
      int v1,v2;
      for(int i=0 ; i<m ; i++){
        st = new StringTokenizer(br.readLine());
        v1 = Integer.parseInt(st.nextToken());
        v2 = Integer.parseInt(st.nextToken());
        cabin[v1].add(v2);
        cabin[v2].add(v1);
      }
      
      findCabin(1);
      
      Collections.sort(clist); // int[] 대신 List 정렬
      System.out.println(clist.get(0) + " " + maxD + " " + clist.size());
      
    }
}