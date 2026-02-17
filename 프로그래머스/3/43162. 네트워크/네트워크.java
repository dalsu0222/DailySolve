import java.util.*;
import java.io.*;

class Solution {
    static boolean visited[];
    static int answer;
    
    static void bfs(int x, int[][] computers, int n){
        visited[x] = true;
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(x);
        
        while(!q.isEmpty()){
            int newX = q.poll();
            for(int i=0; i<n; i++){
                if(newX == i || computers[newX][i] == 0 || visited[i])
                    continue;
                q.offer(i);
                visited[i] = true;
            }
        }
    }
    
    public int solution(int n, int[][] computers) {    
        visited = new boolean[n];
        
        for(int i=0 ; i<n ; i++){
            if(!visited[i]){
                bfs(i,computers,n);
                answer++;
            }
        }
        
        return answer;
    }
}