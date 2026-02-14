import java.util.*;
import java.io.*;

class Solution {
    
    
    public int[] solution(int[] progresses, int[] speeds) {
        List<Integer> answer = new ArrayList<>();
        
        int[] remain = new int[progresses.length];
        for(int i=0; i<progresses.length; i++){
            remain[i] = (int)Math.ceil((100-progresses[i])/(double)speeds[i]);
        }
        
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(remain[0]);
        for(int i=1; i<remain.length; i++){
            if(q.peek() >= remain[i]){
                q.offer(remain[i]);
            }else{
                answer.add(q.size());
                q.clear();
                q.offer(remain[i]);
            }
        }
        
        if(q.size() > 0){
            answer.add(q.size());
        }
        
        // List<Integer> -> int[]
        int[] result = new int[answer.size()];
        for(int i=0 ; i<answer.size(); i++)
            result[i] = answer.get(i);
        
        return result;
    }
}