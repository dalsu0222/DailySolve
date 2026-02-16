import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int num : scoville){
            pq.offer(num);
        }
        
        while(pq.size() >= 2 && pq.peek() < K){
            int s0 = pq.poll();
            int s1 = pq.poll();
            int newS = s0 + s1*2;
            pq.offer(newS);
            
            answer++;
        }
        
        if(pq.peek() < K)
            answer = -1;
        
        return answer;
    }
}