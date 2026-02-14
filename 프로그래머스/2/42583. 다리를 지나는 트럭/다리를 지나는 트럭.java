import java.util.*;
import java.io.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        
        int onBridgeW = 0;
        Queue<Integer> q = new ArrayDeque<>();
        for(int i=0 ; i<bridge_length; i++){
            q.offer(0);
        }
        
        int idx = 0;
        for(int t=1; ; t++){
            // 하차
            if(!q.isEmpty()){
                int w = q.poll();
                onBridgeW -= w;
            }
            
            // 종료
            if(idx == truck_weights.length && onBridgeW == 0){
                answer = t;
                break;
            }
            
            
            // 상차
            if(idx < truck_weights.length && 
               onBridgeW + truck_weights[idx] <= weight){
                onBridgeW += truck_weights[idx];
                q.offer(truck_weights[idx]);
                idx++;
            }else{
                q.offer(0);
            }
        }
        
        return answer;
    }
}