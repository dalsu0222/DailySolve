import java.util.*;

class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2]; //(가로,세로)
        
        // 전체넓이 = brown+yello = 가로 x 세로
        for(int i=3 ; i<= brown+yellow ; i++){
            int h = i;
            int w = (brown+yellow)/h;
            
            if(w < 3) continue;
            
            if(w >= h){
                if((w-2)*(h-2) == yellow){
                    answer[0] = w;
                    answer[1] = h;
                    break;
                }
            }
        }
        
        
        return answer;
    }
}